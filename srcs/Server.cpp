#include "../inc/Server.hpp"
#include "../inc/ircserv.hpp"

Server::Server( int &port, string &pass ) : PORT(port), PASS(pass)
{
	if( PORT > 65535 || PORT < 1024 )
		throw WrongPortNumber();
};

const char* Server::WrongPortNumber::what() const throw()
{
	return "Wrong Port Number!";
}

Server::~Server() {};

int Server::starting( void )
{
	struct sockaddr_in servSock;
	int servSock_fd;

	memset(&servSock, 0, sizeof(servSock));
	servSock_fd =
};