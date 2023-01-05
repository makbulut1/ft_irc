#include "../inc/ircserv.hpp"

int sockAttr( struct sockaddr_in *servSock, int port )
{
	int fdSock, x = 1;

	servSock->sin_family = AF_INET;
	servSock->sin_port = htons(port);
	servSock->sin_addr.s_addr = htons(INADDR_ANY);
	memset(&(servSock->sin_zero), 0, 8);
	fdSock = socket(AF_INET, SOCK_STREAM, 0);
	if( fdSock == -1 )
	{
		std::cerr << "Socket is not created!" << endl;
		return -1;
	}

}