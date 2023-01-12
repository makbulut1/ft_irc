#include "../../inc/Commands.hpp"

int notice(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr,std::string data)
{
	std::string message;

	(void)usr;
	(void)data;
	message = "[FT_IRC] Have a fun in the Server! :)\nDon't forget to use the [HELP] command if you need help.\r\n";
	SendMessage(message, pfd[id].fd);

	return 0;
}