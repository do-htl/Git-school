/*  Author: Oberhofer Daniel
    Date: 18.11.2020
    Function: Server
    Server which returns data send by a client
    Github-repo: https://github.com/do-htl/Git-school.git
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

/* TCP echo server - creates a socket and bind to a defined PORT.
    After binding the server listens for incoming connections.
    When a it is connected the server returns the incoming message
    to the client.
*/

void main(){

    int sockfd, newSocket, received;
	struct sockaddr_in serverAddr;
	struct sockaddr_in newAddr;

	socklen_t addr_size;
	char buffer[1024];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	printf(">server socket created\n");
	memset(&serverAddr, '\0', sizeof(serverAddr));

	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(PORT);
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
	printf(">bind to port\n");

	listen(sockfd, 5);
	printf(">listening...\n"); //Waiting until client connects to the server

	newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);

	recv(newSocket, buffer, strlen(buffer), 0);
	printf("%s", buffer);
	send(newSocket, buffer, strlen(buffer), 0); //Returning the received message from the client
	printf(">closing\n");

	return 0;
}
