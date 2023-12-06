/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:01:45 by paescano          #+#    #+#             */
/*   Updated: 2023/12/06 17:53:49 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap a;
	ScavTrap b("jose");

	std::cout << a;
	std::cout << b;
	for(int i = 11; i > 0; i--)
		a.attack("pepe");
	std::cout << a;
	for(int i = 11; i > 0; i--)
		b.takeDamage(1);
	std::cout << b;
	b.beRepaired(100);
	std::cout << b;
	a.guardGate();
	return (0);
};
