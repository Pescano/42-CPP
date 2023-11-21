/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:52:38 by paescano          #+#    #+#             */
/*   Updated: 2023/11/21 18:25:43 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string	command;

	while (1)
	{
		if (std::cin.fail() || std::cin.eof())
			return 1;
		std::cin.clear();
		std::cout << "Comands available: ADD, SEARCH, EXIT" << std::endl;
		std::cout << "Please enter a command: ";
		if (std::getline(std::cin, command))
		{
			if (command == "ADD")
				std::cout << "ADD" << std::endl;
			else if (command == "SEARCH")
				std::cout << "SEARCH" << std::endl;
			else if (command == "EXIT")
				return 0;
			else
				std::cout << "Invalid command, try again" << std::endl;
		}
	}
	return 0;
}
