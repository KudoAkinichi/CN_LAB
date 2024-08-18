#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

int main()
{
	int sockfd, fd1, length, i;
	char buf[100]; /* Buffer for communication */
	struct sockaddr_in sa, ta1;

	/* Create a socket */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/* Initialize the sockaddr_in structure */
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;
	sa.sin_port = htons(60018); // Convert port number to network byte order

	/* Bind the socket to the specified port */
	i = bind(sockfd, (struct sockaddr *)&sa, sizeof(sa));
	printf("test %d%d\n", sockfd, i);

	/* Listen for incoming connections */
	listen(sockfd, 5);

	/* Accept a client connection */
	length = sizeof(sa);
	fd1 = accept(sockfd, (struct sockaddr *)&ta1, &length);

	/* Send a message to the client */
	memset(buf, 0, sizeof(buf));
	strcpy(buf, "Message from server");
	send(fd1, buf, 100, 0);

	/* Receive a message from the client */
	memset(buf, 0, sizeof(buf));
	recv(fd1, buf, 100, 0);
	printf("%s\n", buf);

	/* Close the connection */
	close(fd1);

	return 0;
}
