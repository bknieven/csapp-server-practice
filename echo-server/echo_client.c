#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>

typedef struct sockaddr SA;
int open_clientfd(char *hostname, int port)
{
	int clientfd;
	struct hostent *hp;	//nDNS entry structure.etdb.h
	struct sockaddr_in serveraddr;	//Internet-style socket address structure. netinet/in.h	

	if((clientfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		return -1;

	//fill in the server's IP address and port
	if((hp = gethostbyname(hostname)) == NULL)
		return -2;
	bzero((char *) &serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	bcopy((char *)hp->h_addr_list[0], (char *)&serveraddr.sin_addr.s_addr, hp->h_length);
	serveraddr.sin_port = htons(port);
	
	//establish a connection with the server
	if(connect(clientfd, (SA *) &serveraddr, sizeof(serveraddr)) < 0)
		return -1;
	return clientfd;	
}

#define MAXLINE 10;
int main(int argc, int **argv)
{
	int clientfd, port;
	char *host, buf[MAXLINE];
	rio_t rio;//p602
}








