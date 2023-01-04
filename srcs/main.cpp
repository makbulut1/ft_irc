/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftekdrmi <ftekdrmi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 20:01:56 by ftekdrmi          #+#    #+#             */
/*   Updated: 2023/01/04 12:06:16 by ftekdrmi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ircserv.hpp"
#include "../inc/Server.hpp"

int main( int ac, char* av[] )
{
    if (ac == 3)
    {
		try
		{
			int servSock, cliSock, i;
			struct sockaddr_in serv_addr, cli_addr;
			socklen_t addr_len;
			char data[1024];
			const char* msg = "--/ WELCOME TO THE [FT_IRC] SERVER \\--\n";

			Server serv(atoi(av[1]), av[2]);

			servSock = socket( AF_INET, SOCK_STREAM, 0 );
			if ( servSock < 0 )
			{
				cerr << "[-]Socket Error!" << endl;
				exit(1);
			}
			memset(&serv_addr, '\0', sizeof(serv_addr));
			serv_addr.sin_family = AF_INET;
			serv_addr.sin_addr.s_addr = htons(INADDR_ANY);
			serv_addr.sin_port = htons(PORT);

			i = bind(servSock, (sockaddr*)&serv_addr, sizeof(serv_addr) );
			if (i < 0)
			{
				cerr << "[-]Connection cannot binding!" << endl;
				exit(1);
			}
			cout << "[+]Bind to the port number: " << PORT << endl;

			listen(servSock, 5);
			cout << "[.]Server Listening..." << endl;
			while (true)
			{
				addr_len = sizeof(cli_addr);
				cliSock = accept(servSock, (sockaddr*)&cli_addr, &addr_len);
				cout << "[+]Client Connected." << endl;
				send(cliSock, msg, strlen(msg), 0);
				int t = recv(cliSock, data, sizeof(data), 0);
				cout << "<<" << endl;
				data[t] = 0;
				cout << data << endl;
			}
		}
		catch ( const std::exception &e )
		{
			cerr << e.what() << endl;
			exit(1);
		}
	}
    else
		cerr << "Missing or More Arguments!" << endl;   
	 return 0;
}