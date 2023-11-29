/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:04:25 by paescano          #+#    #+#             */
/*   Updated: 2023/11/29 18:19:26 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;

	if (argc != 2)
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
	else
		harl.complain(argv[1]);
	return (0);
}