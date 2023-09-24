#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // read() write() close()
#include <sys/type.h>
#include <sys/socket.h>
#include <netinet/in.h>
#define PORT 8080
#define SA struct sockaddr

// int sockfd = socket(int domain, int type, int protocol)

// int bind(int sockfd,const struct sockaddr*addr,socken_addrlen);

// int listen(int sockfd,int backlog);

// newsockfd = accept(sockfd,struct sockaddr*)&addr,&addrlen);

// int connect(int sockfd,const struct sockaddar*addr,socklen_t addrlen);

// int read(newsockfd,buffer,buffer_size);

// int write(newsockfd,buffer,buffer_size);

void error(const char *msg)
{
    perror(msg); // inbuilt error func
    exit(1);
}

int main()
{

    int sockfd, newsockfd, portno;
    char buffer[255];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    // socket create and verification
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1)
    {
        printf("Socket connection failed");
        exit(0);
    }
    else
    {
        printf("Socket connection successful\n");
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));

    // assign IP, PORT
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htos(INADDR_ANY);
    serv_addr.sin_port = htons(portno);
    
    // Binding newly created socket to given IP and verification
    if (blind(sockfd, (SA *)&serv_addr, sizeof(serv_addr) != 0))
    {
        printf("Socket blind failed");
        exit(0);
    }
    else
    {
        printf("Socket blind successful\n");
    }