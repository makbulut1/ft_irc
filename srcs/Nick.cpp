//
// Created by Mehmet eren Akbulut on 1/8/23.
//
#include "../inc/Commands.hpp"

int nickname(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr, std::string data) {
    std::string my_data;
    std::string message;
    int i = 0;

    my_data = data;
    if (my_data.length() == 0)
        return 0;
    if (usr[id - 1].getNameStat() == 0) {
        while (i < id - 1) {
            if (usr[i].getNick() == my_data) {
                message = "\e[1;31m>_ Nickname Error: \e[1;36m[" + my_data + "]\e[1;31m This nickname is used!\r\n\e[0m";
                SendMessage(message, pfd[id].fd);
                return 0;
            }
            i++;
        }
        usr[id - 1].setNameStat(1);
        usr[id - 1].getNick() = my_data;
        return 0;
    }
    usr[id - 1].setName(my_data);
    usr[id - 1].setNameStat(1);
    usr[id - 1].getReply() = ":" + usr[id - 1].getNick() + "!" + usr[id - 1].getName() + "@127.0.0.1";
    message = ":ircserv 001 " + usr[id - 1].getNick() + " Welcome to the Internet Relay Network " \
 + usr[id - 1].getReply() + "\r\n";
    SendMessage(message, pfd[id].fd);
    return 0;
}