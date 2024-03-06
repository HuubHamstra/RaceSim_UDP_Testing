#include <iostream>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 9876 // Port on which the UDP connection is made

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    // Create a UDP socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }

    // Set up server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // Bind the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        std::cerr << "Binding failed\n";
        return 1;
    }

    std::cout << "Server is listening on port " << PORT << std::endl;

    char buffer[1024];
    socklen_t len = sizeof(cliaddr);

    // Receive data continuously
    while (true) {
        int n = recvfrom(sockfd, (char *)buffer, sizeof(buffer), 0, (struct sockaddr *)&cliaddr, &len);
        buffer[n] = '\0'; // Append a null byte at the end of the received data
        std::cout << "Received message: " << buffer << std::endl;
    }

    // Close the socket
    close(sockfd);

    return 0;
}
