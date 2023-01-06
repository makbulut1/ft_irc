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
		cerr << "[-]Socket is not created!" << endl;
		return -1;
	}
	if( setsockopt( fdSock, SOL_SOCKET, SO_REUSEADDR, &x, sizeof(x) ) == -1 )
	{
		cerr << "[-]Socket could be not set options!" << endl;
		close(fdSock);
		return -1;
	}
	if ( bind( fdSock, (sockaddr*)servSock, sizeof(sockaddr_in) == -1 ) )
	{
		cerr << "[-]Socket not binding!" << endl;
		close(fdSock);
		return -1;
	}
	cout << "[+]Bind to the port number: " << port << endl;
	return (fdSock);
}