#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void send_file_list(int client_socket)
{
    DIR *dir;
    struct dirent *entry;
    char buffer[BUFFER_SIZE] = {0};

    // Open the current directory
    if ((dir = opendir(".")) != NULL)
    {
        // Read and send the list of filenames
        while ((entry = readdir(dir)) != NULL)
        {
            strcat(buffer, entry->d_name);
            strcat(buffer, "\n");
        }
        send(client_socket, buffer, strlen(buffer), 0);
        closedir(dir);
    }
    else
    {
        perror("Could not open directory");
        send(client_socket, "Error opening directory\n", 24, 0);
    }
}

void send_file_content(int client_socket, char *filename)
{
    FILE *file;
    char buffer[BUFFER_SIZE] = {0};
    size_t bytes_read;

    // Open the requested file
    if ((file = fopen(filename, "r")) != NULL)
    {
        // Read the file and send its content
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, file)) > 0)
        {
            send(client_socket, buffer, bytes_read, 0);
            memset(buffer, 0, BUFFER_SIZE);
        }
        fclose(file);
    }
    else
    {
        perror("File not found");
        send(client_socket, "Error: File not found\n", 22, 0);
    }
}

int main()
{
    int server_fd, client_socket, valread;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};
    int opt = 1;

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Define server address and port
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    // Accept incoming connection
    if ((client_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Accept failed");
        close(server_fd);
        exit(EXIT_FAILURE);
    }

    // Read command from client
    valread = read(client_socket, buffer, BUFFER_SIZE);
    buffer[valread] = '\0'; // Null-terminate the received string

    // Process the command
    if (strncmp(buffer, "list", 4) == 0)
    {
        // Send the list of files in the current directory
        send_file_list(client_socket);
    }
    else if (strncmp(buffer, "retr ", 5) == 0)
    {
        // Extract filename from the command and send the file content
        char filename[BUFFER_SIZE] = {0};
        sscanf(buffer + 5, "%s", filename); // Get the filename after "retr "
        send_file_content(client_socket, filename);
    }
    else
    {
        send(client_socket, "Invalid command\n", 16, 0);
    }

    // Close the socket
    close(client_socket);
    close(server_fd);

    return 0;
}
