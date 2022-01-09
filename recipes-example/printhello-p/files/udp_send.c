#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 		1234
#define REMOTE_IP 	"192.168.1.188"
#define MAXLINE		1024

int main() {
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "Hello from Pi";
	struct sockaddr_in	 pc_addr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	memset(&pc_addr, 0, sizeof(pc_addr));
	
	// Filling server information
	pc_addr.sin_family = AF_INET;
	pc_addr.sin_port = htons(PORT);
	pc_addr.sin_addr.s_addr = inet_addr(REMOTE_IP);
	
	int n, len;
	
	sendto(sockfd, (const char *)hello, strlen(hello),
		MSG_CONFIRM, (const struct sockaddr *) &pc_addr,
			sizeof(pc_addr));
	printf("Hello message sent.\n");
	
	close(sockfd);
	return 0;
}
