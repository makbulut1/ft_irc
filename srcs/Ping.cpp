//
// Created by Mehmet eren Akbulut on 1/8/23.
//
#include "../inc/Commands.hpp"

int ping(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr,std::string data)
{
    std::string message;

    (void)usr;
    (void)data;
    message = ":ircserv PONG localhost\r\n";
    SendMessage(message, pfd[id].fd);
    return 0;
}
