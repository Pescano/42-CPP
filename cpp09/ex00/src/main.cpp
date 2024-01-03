/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:43:12 by paescano          #+#    #+#             */
/*   Updated: 2024/01/03 15:19:05 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cerr << "Error: Usage: ./RPN \"file_input\"" << std::endl, 1);
	BitcoinExchange btc;
	btc.converter(argv[1]);
	return (0);
}
