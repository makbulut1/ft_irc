#include "ircserv.hpp"

int main( int ac, char* av[] )
{
    if (ac == 3)
    {
		PORT = atoi(av[1]);
		string outPass = av[2];
    }
    else
		cerr << "Missing or More Arguments!" << endl;
    
}