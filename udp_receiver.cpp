#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <cstdint> // Inclusie van cstdint voor uint16_t, uint8_t, uint32_t, uint64_t

#include "PacketHeader.h"
#include "CarMotionData.h"

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
    PACKET_ID_SESSION_HISTORY = 11
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
    servaddr.sin_addr.s_addr = inet_addr("172.20.10.4"); // IP-adres instellen
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
    CarMotionData p_motion;

    // Ontvang continu data
    while (true) {
        int n = recvfrom(sockfd, (char *)buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0'; // Voeg een nulbyte toe aan het einde van de ontvangen gegevens
        h_packet.get(buffer);

        std::cout << "Ontvangen bericht: " << h_packet.m_sessionTime << std::endl;

        unsigned long offset = h_packet.get(buffer); // Haal de offset op van de PacketHeader
        switch (h_packet.m_packetId) {
            case PACKET_ID_MOTION:  // 0 - Motion
                p_motion.get(buffer, offset); // Geef de offset mee aan CarMotionData
                std::cout << "Velocity: " << p_motion.m_worldVelocityX << ","  << p_motion.m_worldVelocityY << ","  << p_motion.m_worldVelocityZ << std::endl;
                break;
            // Voeg andere gevallen voor andere pakkettypen toe indien nodig
        }
    }

    // Sluit de socket
    close(sockfd);

    return 0;
}
