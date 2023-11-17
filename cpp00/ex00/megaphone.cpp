/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:27:13 by paescano          #+#    #+#             */
/*   Updated: 2023/11/17 17:14:03 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctype.h>

std::string	ft_str_to_upper(std::string str)
{
	std::string upper;
	upper.assign(str);
	for (size_t i = 0; i < upper.length() ; i++)
	{
		if(std::islower(upper[i]))
			upper[i] = std::toupper(upper[i]);
	}
	return (upper);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			std::cout << ft_str_to_upper(argv[i]);
			if (i + 1 < argc)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}