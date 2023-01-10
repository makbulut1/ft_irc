#include "../inc/Commands.hpp"

int ping(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr,std::string data)
{
    std::string message;

    (void)usr;
    (void)data;
    message = "[FT_IRC]-/Ping request received.\r\n";
    SendMessage(message, pfd[id].fd);
    return 0;
}
