#include <stdio.h>
#include <stdlib.h> 
#include <string.h> 
#include <arpa/inet.h> 
#include<unistd.h>
#define PORT 1111 
#define MAX_MESSAGE_LEN 100 
int main() {
    int sockfd;
    struct sockaddr_in serverAddr, clientAddr; 
    socklen_t clientAddrLen = sizeof(clientAddr); 
    char buffer[MAX_MESSAGE_LEN] = {0}; 

    sockfd = socket(AF_INET, SOCK_DGRAM, 0); 
    if (sockfd == -1) {
        perror("socket"); 
        exit(EXIT_FAILURE); 
    }
    memset(&serverAddr, 0, sizeof(serverAddr)); 
    serverAddr.sin_family = AF_INET; 
    serverAddr.sin_addr.s_addr = INADDR_ANY; 
    serverAddr.sin_port = htons(PORT); 


   if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("bind"); 
        close(sockfd);
        exit(EXIT_FAILURE); 
    }

    printf("Server is listening on port %d...\n", PORT); 

    while (1) {
        ssize_t numBytes = recvfrom(sockfd, buffer, MAX_MESSAGE_LEN - 1, 0, (struct sockaddr *)&clientAddr, &clientAddrLen); 
        if (numBytes == -1) {
            perror("recvfrom"); 
            close(sockfd); 
            exit(EXIT_FAILURE);
        }
        buffer[numBytes] = '\0'; 

        printf("Received message from client: %s\n", buffer); 
        
        const char *replyMessage = "Received Message"; 
        if (sendto(sockfd, replyMessage, strlen(replyMessage), 0, (struct sockaddr *)&clientAddr, clientAddrLen) == -1) {
            perror("sendto"); 
            close(sockfd); 
            exit(EXIT_FAILURE); 
        }
    }

    close(sockfd);
    return 0; 
}
