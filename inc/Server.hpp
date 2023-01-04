#ifndef SERVER_HPP
#define SERVER_HPP

#include <iostream>

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
	string PASS;
};

#endif