/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:53:22 by paescano          #+#    #+#             */
/*   Updated: 2024/01/03 15:17:20 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Usage: ./RPN \"expression\"" << std::endl;
		return (0);
	}
	RPN	rpn;
	rpn.setInput(argv[1]);
	rpn.calculate();
	rpn.getResult();
	return (0);
}