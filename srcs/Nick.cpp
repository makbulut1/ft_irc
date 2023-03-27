//
// Created by Mehmet eren Akbulut on 1/8/23.
//
#include "../inc/Commands.hpp"

int nickname(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr, std::string data) {
    std::string my_pass;
    std::string message;
    int i = 0;

    my_pass = data;
    if (my_pass.length() == 0)
        return 0;
    if (usr[id - 1].getNameStat() == 0) {
        while (i < id - 1) {
            if (usr[i].getNick() == my_pass) {
                message = ":ircserv 433 ERR_NICKNAMEINUSE\n" + my_pass + " :Nickname is already in use\r\n";
                SendMessage(message, pfd[id].fd);
                return 0;
            }
            i++;
        }
        usr[id - 1].setNameStat(1);
        usr[id - 1].getNick() = my_pass;
        return 0;
    }
    usr[id - 1].setName(my_pass);
    usr[id - 1].setNameStat(1);
    usr[id - 1].setReply(":" + usr[id - 1].getNick() + "!" + usr[id - 1].getName() + "@127.0.0.1");
    message = ":ircserv 001 " + usr[id - 1].getNick() + " Welcome to the Internet Relay Network " \
 + usr[id - 1].getReply() + "\r\n";
    SendMessage(message, pfd[id].fd);
    return 0;
}
