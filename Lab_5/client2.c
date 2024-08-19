#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main()
{
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    char command[BUFFER_SIZE] = {0};

    // Creating socket file descriptor
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return -1;
    }

    // Get command from the user
    printf("Enter command (list or retr filename): ");
    fgets(command, BUFFER_SIZE, stdin);
    command[strcspn(command, "\n")] = 0; // Remove newline character

    // Send the command to the server
    send(sock, command, strlen(command), 0);

    // Receive the response from the server
    valread = read(sock, buffer, BUFFER_SIZE);
    buffer[valread] = '\0'; // Null-terminate the received string
    printf("Response from server:\n%s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}
