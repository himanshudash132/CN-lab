#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <arpa/inet.h> 
#include<unistd.h>

#define SERVER_IP "127.0.0.1" 
#define PORT 1111
#define MAX_MESSAGE_LEN 100 

int main() {
    int sockfd;
    struct sockaddr_in serverAddr; 

    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
    if (sockfd == -1) {
        perror("socket"); 
        exit(EXIT_FAILURE); 
    }

    memset(&serverAddr, 0, sizeof(serverAddr)); 
    serverAddr.sin_family = AF_INET; 
    serverAddr.sin_port = htons(PORT); 
    if (inet_pton(AF_INET, SERVER_IP, &serverAddr.sin_addr) <= 0) { 
        perror("inet_pton");
        close(sockfd); 
        exit(EXIT_FAILURE);
    }

    const char *message = "My Roll number is 2106167"; 
    if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("sendto");
        close(sockfd); 
        exit(EXIT_FAILURE); 
    }

    char buffer[MAX_MESSAGE_LEN] = {0}; 
    ssize_t numBytes = recvfrom(sockfd, buffer, MAX_MESSAGE_LEN - 1, 0, NULL, NULL); 
    if (numBytes == -1) {
        perror("recvfrom"); 
        close(sockfd); 
        exit(EXIT_FAILURE); 
    }
    buffer[numBytes] = '\0'; 

    printf("Received reply from server: %s\n", buffer); 

    close(sockfd); 
    return 0; 
}
