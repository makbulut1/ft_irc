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
			Server serv(atoi(av[1]), av[2]);
			if ( serv.sockStart() == -1 )
				return 1;
			if ( serv.sockScan() == -1 )
				return 1;
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