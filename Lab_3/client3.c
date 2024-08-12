// Create an UDP socket through which client will send an integer array to the server, the server will sort the array and return back to the client.

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
#define MAXARRAYSIZE 100

int main()
{
    int sockfd;
    struct sockaddr_in their_addr; // connector's address information
    int numbytes;
    int array[MAXARRAYSIZE], sorted_array[MAXARRAYSIZE];
    int array_size;
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

    printf("Enter the size of the array: ");
    scanf("%d", &array_size);

    if (array_size > MAXARRAYSIZE)
    {
        fprintf(stderr, "Array size exceeds maximum limit of %d\n", MAXARRAYSIZE);
        exit(1);
    }

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < array_size; i++)
    {
        scanf("%d", &array[i]);
    }

    if ((numbytes = sendto(sockfd, &array_size, sizeof(int), 0,
                           (struct sockaddr *)&their_addr, addr_len)) == -1)
    {
        perror("sendto");
        exit(1);
    }

    if ((numbytes = sendto(sockfd, array, array_size * sizeof(int), 0,
                           (struct sockaddr *)&their_addr, addr_len)) == -1)
    {
        perror("sendto");
        exit(1);
    }

    if ((numbytes = recvfrom(sockfd, sorted_array, array_size * sizeof(int), 0,
                             (struct sockaddr *)&their_addr, &addr_len)) == -1)
    {
        perror("recvfrom");
        exit(1);
    }

    printf("Received sorted array:\n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d ", sorted_array[i]);
    }
    printf("\n");

    close(sockfd);
    return 0;
}
