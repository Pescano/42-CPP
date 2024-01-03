/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:55:33 by paescano          #+#    #+#             */
/*   Updated: 2024/01/03 15:17:27 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	if (argc <= 1)
		return (std::cout << "Error: Usage: ./PmergeMe <positive_integers>" << std::endl, 1);
	PmergeMe(argc, argv);
	return (0);
}