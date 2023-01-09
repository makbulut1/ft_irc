#include "../inc/Commands.hpp"

int ping(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr,std::string data)
{
    std::string message;

    (void)usr;
    (void)data;
    message = "\e[1;33m>_ Ping request received by [IRC_SERVER]\r\n\e[0m";
    SendMessage(message, pfd[id].fd);
    return 0;
}
