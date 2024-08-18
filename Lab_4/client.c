#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main()
{
	int i, sockfd;
	char buf[100];
	struct sockaddr_in sa;

	/* Opening a socket is exactly similar to the server process */
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	/* Specify the IP address and port of the server */
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = inet_addr("127.0.0.1"); // Loop back IP address
	sa.sin_port = 60018;

	/* Establish a connection with the server process */
	i = connect(sockfd, (struct sockaddr *)&sa, sizeof(sa));

	/* Receive and print message from server */
	for (i = 0; i < 100; i++)
		buf[i] = '\0';
	recv(sockfd, buf, 100, 0);
	printf("%s\n", buf);

	/* Send message to the server */
	for (i = 0; i < 100; i++)
		buf[i] = '\0';
	strcpy(buf, "Message from client");
	send(sockfd, buf, 100, 0);

	close(sockfd);

	return 0;
}
