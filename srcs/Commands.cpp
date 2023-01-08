//
// Created by Mehmet eren Akbulut on 1/7/23.
//

#include "../inc/Commands.hpp"
#include "../inc/ircserv.hpp"
Commands::Commands() {}

Commands::~Commands() {}

const std::string &Commands::getCommand() {
    return this->Command;
}

const std::string &Commands::getSubCmd() {
    return this->SubCmd;
}

const std::string &Commands::getMessage() {
    return this->Message;
}

void Commands::setCommand(const std::string &cmd) {
    this->Command = cmd;
}

void Commands::setSubCmd(const std::string &subCmd) {
    this->SubCmd = subCmd;
}

void Commands::setMessage(const std::string &Message) {
    this->Message = Message;
}

int Commands::EnterCommand(std::string &data, int id, std::vector<Client> &usr, std::vector<struct pollfd> &plFd) {
    int i = 0;

    const char *cmd[] = {
            "PRIVMSG",
//            "JOIN",
//            "PING",
//            "NICK",
//            "USER",
//            "KICK",
            NULL
    };

    int (*cmdp[])(int id, std::vector<struct pollfd> &pfd, std::vector<Client> &usr, std::string data) =
    {
            &privmsg,
//            &join,
//            &ping,
//            &nickname,
//            &nickname,
//            &kick
    };

    setSubCmd(data);
    if (data.find(' ') == std::string::npos) {
        setMessage("411 ERR_NORECIPIENT\n:No recipient given (" + getSubCmd() + ")\n");
        send(plFd[id].fd , this->getMessage().data(), this->getMessage().length(), 0);
        return 0;
    }
    setCommand(data.substr(0, data.find(' ')));
    chrTrimer(data, ' ');
    std::cout << "command: " << getCommand() << std::endl;
    while (cmd[i]) {
        if (getCommand() == cmd[i])
            return cmdp[i](id, plFd, usr, data);
        ++i;
    }
    setMessage("411 ERR_NORECIPIENT\n:No recipient given (" + getSubCmd() + ")\n");
    SendMessage(getMessage(), plFd[id].fd);
    return 0;
}

void chrTrimer(std::string &s, char ch) {
    s = s.substr(s.find(ch) + 1, s.length() - s.find(ch));
}

void	SendMessage(std::string message, int fd)
{
    std::cout << GRN << "[Server] " << WHT << "-> " << BLUE << "[Client " << fd << "] " << YLW << message << RESET << std::endl;
    send(fd, message.data(),message.length(), 0);
}
