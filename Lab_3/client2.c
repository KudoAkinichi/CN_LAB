// Create an UDP socket through which the client will send 2 integer number to the server, server will add the number and return back the value.

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

#define SERVERPORT 4952 // the port users will be connecting to

int main()
{
    int sockfd;
    struct sockaddr_in their_addr; // connector's address information
    int numbytes;
    int num1, num2, result;
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

    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);

    if ((numbytes = sendto(sockfd, &num1, sizeof(int), 0,
                           (struct sockaddr *)&their_addr, addr_len)) == -1)
    {
        perror("sendto");
        exit(1);
    }

    if ((numbytes = sendto(sockfd, &num2, sizeof(int), 0,
                           (struct sockaddr *)&their_addr, addr_len)) == -1)
    {
        perror("sendto");
        exit(1);
    }

    if ((numbytes = recvfrom(sockfd, &result, sizeof(int), 0,
                             (struct sockaddr *)&their_addr, &addr_len)) == -1)
    {
        perror("recvfrom");
        exit(1);
    }

    printf("Received sum: %d\n", result);

    close(sockfd);
    return 0;
}
