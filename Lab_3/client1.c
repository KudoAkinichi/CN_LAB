// WAP in C to create a UDP socket to which client will send a string to the server , the server will echo back the string to the client. When the client will send exit , server will drop the connection.

/*
** A datagram "client" demo
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVERPORT 4952 // the port users will be connecting to
#define MAXBUFLEN 100

int main()
{
    int sockfd;
    struct sockaddr_in their_addr; // connector's address information
    int numbytes;
    char buf[MAXBUFLEN];
    socklen_t addr_len;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    their_addr.sin_family = AF_INET;         // host byte order
    their_addr.sin_port = htons(SERVERPORT); // short, network byte order
    their_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    addr_len = sizeof their_addr;

    while (1)
    {
        printf("Enter a message (type 'exit' to quit):\n");
        fgets(buf, MAXBUFLEN, stdin);

        // Remove newline character from the end of the string
        buf[strcspn(buf, "\n")] = 0;

        if ((numbytes = sendto(sockfd, buf, strlen(buf), 0,
                               (struct sockaddr *)&their_addr, addr_len)) == -1)
        {
            perror("sendto");
            exit(1);
        }

        if (strcmp(buf, "exit") == 0)
        {
            printf("Exiting...\n");
            break;
        }

        if ((numbytes = recvfrom(sockfd, buf, MAXBUFLEN - 1, 0,
                                 (struct sockaddr *)&their_addr, &addr_len)) == -1)
        {
            perror("recvfrom");
            exit(1);
        }

        buf[numbytes] = '\0';
        printf("Received: %s\n", buf);
    }

    close(sockfd);
    return 0;
}
