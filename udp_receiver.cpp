#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdint> // Inclusie van cstdint voor uint16, uint8, uint32, uint64

#include "headers/PacketHeader.h"
#include "headers/PacketMotionData.h"

#define PORT 20777 // Poort waarop de UDP-verbinding wordt gemaakt

// Functie om 16-bit integer van little-endian naar host-endian te converteren
uint16_t convertLE16(uint16_t value) {
    return ntohs(value);
}

// Functie om 32-bit integer van little-endian naar host-endian te converteren
uint32_t convertLE32(uint32_t value) {
    return ntohl(value);
}

// Functie om float van little-endian naar host-endian te converteren
float convertLEFloat(float value) {
    uint32_t temp;
    memcpy(&temp, &value, sizeof(float));
    temp = ntohl(temp);
    memcpy(&value, &temp, sizeof(float));
    return value;
}

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
    servaddr.sin_addr.s_addr = inet_addr("192.168.215.228"); // IP-adres instellen
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
                p_motion.get(buffer); // Geef de juiste offset mee aan PacketMotionData
                // Converteer de ontvangen gegevens van little-endian naar host-endian formaat
                p_motion.m_localVelocityX = convertLEFloat(p_motion.m_localVelocityX);
                p_motion.m_localVelocityY = convertLEFloat(p_motion.m_localVelocityY);
                p_motion.m_localVelocityZ = convertLEFloat(p_motion.m_localVelocityZ);
                // Print de snelheidsgegevens
                std::cout << "Velocity: " << p_motion.m_localVelocityX << ","  << p_motion.m_localVelocityY << ","  << p_motion.m_localVelocityZ << std::endl;
                break;
            // Voeg andere gevallen voor andere pakkettypen toe indien nodig
        }
    }

    // Sluit de socket
    close(sockfd);

    return 0;
}
