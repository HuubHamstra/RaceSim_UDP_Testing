#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdint> // Inclusie van cstdint voor uint16, uint8, uint32, uint64

#include "PacketHeader.h"
#include "PacketMotionData.h"

#define PORT 20777 // Poort waarop de UDP-verbinding wordt gemaakt

enum packetId : int {
    PACKET_ID_MOTION = 0,
    PACKET_ID_SESSION = 1,
    PACKET_ID_LAP_DATA = 2,
    PACKET_ID_EVENT = 3,
    PACKET_ID_PARTICIPANTS = 4,
    PACKET_ID_CAR_SETUPS = 5,
    PACKET_ID_CAR_TELEMETRY = 6,
    PACKET_ID_CAR_STATUS = 7,
    PACKET_ID_FINAL_CLASSIFICATION = 8,
    PACKET_ID_LOBBY_INFO = 9,
    PACKET_ID_CAR_DAMAGE = 10,
    PACKET_ID_SESSION_HISTORY = 11,
    PACKET_ID_TYRE_SETS = 12,
    PACKET_ID_MOTION_EX = 13,
};

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    // Maak een UDP-socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Socket creatie mislukt\n";
        return 1;
    }

    // Serveradres instellen
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("192.168.221.228"); // IP-adres instellen
    servaddr.sin_port = htons(PORT);

    // Bind de socket met het serveradres
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Binding mislukt\n";
        return 1;
    }

    std::cout << "Server luistert op poort " << PORT << std::endl;

    char buffer[4096];
    socklen_t len = sizeof(cliaddr);

    PacketHeader h_packet;
    PacketMotionData p_motion;

    // Ontvang continu data
    while (true) {
        int n = recvfrom(sockfd, buffer, 4096, 0, (struct sockaddr *)&cliaddr, &len);

        h_packet.get(buffer);
        h_packet.print();
        //std::cout << "Ontvangen bericht: " << h_packet << ", " << offset << std::endl;

        switch (h_packet.m_packetId) {
            case PACKET_ID_MOTION:  // 0 - Motion
                p_motion.get(buffer); // Geef de juiste offset mee aan CarMotionData
                //CarMotionData c_motion = p_motion.m_carMotionData;
                // p_motion.print();
                std::cout << "Velocity: " << p_motion.m_localVelocityX << ","  << p_motion.m_localVelocityY << ","  << p_motion.m_localVelocityZ << std::endl;
                break;
            // Voeg andere gevallen voor andere pakkettypen toe indien nodig
        }
    }

    // Sluit de socket
    close(sockfd);

    return 0;
}
