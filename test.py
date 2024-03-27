import socket
import struct

# Define the struct formats for PacketHeader and CarMotionData
packet_header_format = "<HBBBBBQfIIIBB"
car_motion_data_format = "<fffffffffffff"

# Define the size of the packet header and car motion data in bytes
packet_header_size = struct.calcsize(packet_header_format)
car_motion_data_size = struct.calcsize(car_motion_data_format)

# Function to unpack the received packet header
def unpack_packet_header(data):
    return struct.unpack(packet_header_format, data)

# Function to unpack the received car motion data
def unpack_car_motion_data(data):
    return struct.unpack(car_motion_data_format, data)

# IP and port to listen on
UDP_IP = "0.0.0.0"  # Listen on all available network interfaces
UDP_PORT = 20777    # Choose a port number

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Bind the socket to the IP and port
sock.bind((UDP_IP, UDP_PORT))

print("UDP packet listener started...")

# Infinite loop to continuously listen for packets
while True:
    # Receive data from the socket
    data, addr = sock.recvfrom(4096)  # Buffer size is 1024 bytes

    # Check if received data has at least the size of the packet header
    if len(data) >= packet_header_size:
        # Unpack the packet header
        packet_header = unpack_packet_header(data[:packet_header_size])
        
        # Check if packetId is 0
        if packet_header[5] == 0:
            # Check if the received data has enough size for CarMotionData
            if len(data) >= packet_header_size + car_motion_data_size:
                # Unpack the CarMotionData
                car_motion_data = unpack_car_motion_data(data[packet_header_size:packet_header_size + car_motion_data_size])
                
                # Print CarMotionData
                print("Car Motion Data:")
                print("World Position (X, Y, Z):", car_motion_data[:3])
                print("World Velocity (X, Y, Z):", car_motion_data[3:6])
                print("World Forward Direction (X, Y, Z):", car_motion_data[6:9])
                print("World Right Direction (X, Y, Z):", car_motion_data[9:12])
                print("G-Force (Lateral, Longitudinal, Vertical):", car_motion_data[12:15])
                print("Yaw, Pitch, Roll:", car_motion_data[15:])
                print("--------------------")
