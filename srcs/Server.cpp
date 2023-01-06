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
	memset(&servSock, 0, sizeof(servSock));
	servSock_fd = sockAttr( &servSock, PORT );
	if( servSock_fd == -1 )
		return -1;
	if( fcntl( servSock_fd, F_SETFL, O_NONBLOCK ) == -1 )
	{
		cerr << "[-]Socket could not be set to nonblock" << endl;
		close(servSock_fd);
		return -1;
	}
	if( listen(servSock_fd, 5) == -1 )
	{
		cerr << "[-]Socket is not listening" << endl;
		close(servSock_fd);
		return -1;
	}
	cout << "[.]Server Listening..." << endl;
};