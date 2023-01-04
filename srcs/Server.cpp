#include "../inc/Server.hpp"

Server::Server( int &port, string &pass ) : PORT(port), PASS(pass)
{
	if( PORT > 65535 || PORT < 1024 )
		throw WrongPortNumber();
};

const char* Server::WrongPortNumber::what() const throw()
{
	return "Wooaaw Port Number!";
}

Server::~Server() {};

int Server::starting( void ) {};