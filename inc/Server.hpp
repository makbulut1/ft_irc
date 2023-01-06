#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

using std::string;

class Server
{
public:
	Server( int& port, string&pass );
	~Server();

	struct WrongPortNumber : public exception
	{
		const char* what() const throw();
	};

	int starting( void );

private:
	int PORT;
	int servSock_fd;
	struct sockaddr_in servSock;
	string PASS;
};

#endif