#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 20777 // Poort waarop de UDP-verbinding wordt gemaakt

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
    servaddr.sin_addr.s_addr = inet_addr("172.20.10.5"); // IP-adres instellen
    servaddr.sin_port = htons(PORT);

    // Bind de socket met het serveradres
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Binding mislukt\n";
        return 1;
    }

    std::cout << "Server luistert op poort " << PORT << std::endl;

    char buffer[1024];
    socklen_t len = sizeof(cliaddr);

    // Ontvang continu data
    while (true) {
        int n = recvfrom(sockfd, (char *)buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0'; // Voeg een nulbyte toe aan het einde van de ontvangen gegevens
        std::cout << "Ontvangen bericht: " << buffer << std::endl;
    }

    // Sluit de socket
    close(sockfd);

    return 0;
}
