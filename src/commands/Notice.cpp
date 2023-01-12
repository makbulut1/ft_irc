#include "../../inc/Commands.hpp"

int notice(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr,std::string data)
{
	std::string message;
	int i = -1;
	int cliOfNbr;

	(void)usr;
	(void)data;
	cliOfNbr = pfd.size();
	message = usr[id - 1].getNick() + " Send a message to everyone: " + data + "\r\n";
	//message = "[FT_IRC] Have a fun in the Server! :)\nDon't forget to use the [HELP] command if you need help.\r\n";
	while(++i <= cliOfNbr - 1)
		SendMessage(message, pfd[i].fd);

	return 0;
}