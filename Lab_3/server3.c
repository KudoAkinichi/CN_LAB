/*
** A datagram sockets "server" demo
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

#define MYPORT 4952 // the port users will be connecting to
#define MAXARRAYSIZE 100

void sort_array(int *array, int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int sockfd;
    struct sockaddr_in my_addr;    // my address information
    struct sockaddr_in their_addr; // connector's address information
    socklen_t addr_len;
    int numbytes;
    int array[MAXARRAYSIZE];
    int array_size;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        perror("socket");
        exit(1);
    }

    my_addr.sin_family = AF_INET;         // host byte order
    my_addr.sin_port = htons(MYPORT);     // short, network byte order
    my_addr.sin_addr.s_addr = INADDR_ANY; // automatically fill with my IP

    if (bind(sockfd, (struct sockaddr *)&my_addr, sizeof my_addr) == -1)
    {
        perror("bind");
        exit(1);
    }

    addr_len = sizeof their_addr;

    while (1)
    {
        if ((numbytes = recvfrom(sockfd, &array_size, sizeof(int), 0,
                                 (struct sockaddr *)&their_addr, &addr_len)) == -1)
        {
            perror("recvfrom");
            exit(1);
        }

        if (array_size > MAXARRAYSIZE)
        {
            fprintf(stderr, "Received array size exceeds maximum limit of %d\n", MAXARRAYSIZE);
            continue;
        }

        if ((numbytes = recvfrom(sockfd, array, array_size * sizeof(int), 0,
                                 (struct sockaddr *)&their_addr, &addr_len)) == -1)
        {
            perror("recvfrom");
            exit(1);
        }

        sort_array(array, array_size);

        if ((numbytes = sendto(sockfd, array, array_size * sizeof(int), 0,
                               (struct sockaddr *)&their_addr, addr_len)) == -1)
        {
            perror("sendto");
            exit(1);
        }
    }

    close(sockfd);
    return 0;
}
