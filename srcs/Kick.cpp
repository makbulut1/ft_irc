//
// Created by Mehmet eren Akbulut on 1/8/23.
//

#include "../inc/Commands.hpp"

int kick(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr, std::string data) {
    std::string channel;
    std::string nick;
    std::string message;
    std::string sub_cmd = data;
    size_t i;

    i = 0;
    std::cout << data;
    if (data.find(' ') == std::string::npos) {
        message = ":ircserv 411 " + usr[id - 1].getNick() + " :No recipient given (" + sub_cmd + ")\r\n";
        SendMessage(message, pfd[id].fd);
        return 0;
    }
    channel = data.substr(0, data.find(' '));
    channel.erase(channel.begin());
    chrTrimer(data, ' ');
    while (data[0] == ' ')
        data.erase(data.begin());
    nick = data.substr(0, data.find('\n'));
    std::cout << "nick " << nick << std::endl;
    if (nick.length() < 1) {
        message = ":ircserv 412 " + usr[id - 1].getNick() + " :No text to send\r\n";
        SendMessage(message, pfd[id].fd);
        return 0;
    }
    while (i < usr.size()) {
        if (usr[i].getNick() == nick)
            break;
        ++i;
    }
    if (i == usr.size()) {
        message = ":ircserv 476 " + usr[id - 1].getNick() + " " + channel + " :Bad Channel Mask\r\n";
        SendMessage(message, pfd[id].fd);
        return 0;
    }
    if (usr[i].getChannel() != channel) {
        message = ":ircserv 441 " + usr[id - 1].getNick() + " " + channel + " :They aren't on that channel\r\n";
        SendMessage(message, pfd[id].fd);
        return 0;
    }
    if (usr[id - 1].getChannel() != channel) {
        message = ":ircserv 442 " + usr[id - 1].getNick() + " " + channel + " :You're not on that channel\r\n";
        SendMessage(message, pfd[id].fd);
        return 0;
    }
    if (usr[id - 1].getIsOpr() == 0) {
        message = ":ircserv 482 " + usr[id - 1].getNick() + " " + channel + " :You're not channel operator\r\n";
        SendMessage(message, pfd[id].fd);
        return 0;
    } else {
        usr[i].setChannel("");
        message = ":ircserv " + usr[i - 1].getNick() + " YOU ARE KICKED\r\n";
        SendMessage(message, pfd[i].fd);
        return 0;
    }
    message = ":ircserv 401 " + usr[id - 1].getNick() + " " + nick + " :No such nick/channel\r\n";
    SendMessage(message, pfd[id].fd);
    return 0;
}
