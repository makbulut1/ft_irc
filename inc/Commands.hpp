//
// Created by Mehmet eren Akbulut on 1/7/23.
//

#ifndef FT_IRC_COMMANDS_HPP
#define FT_IRC_COMMANDS_HPP

#include <iostream>
#include <sys/poll.h>
#include "../inc/Client.hpp"
#include <vector>

class Commands {
private:
    std::string Command;
    std::string Message;
    std::string SubCmd;

public:
    Commands();

    ~Commands();

    const std::string &getCommand();

    const std::string &getSubCmd();

    const std::string &getMessage();

    void setCommand(const std::string &cmd);

    void setSubCmd(const std::string &subCmd);

    void setMessage(const std::string &Message);

    int EnterCommand(std::string &data, int id, std::vector<Client> &usr, std::vector<struct pollfd> &plFd);

};

void	SendMessage(std::string message, int fd);
void    chrTrimer(std::string &s, char ch);
int privmsg(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr, std::string data);

#endif //FT_IRC_COMMANDS_HPP
