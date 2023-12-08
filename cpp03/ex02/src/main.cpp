/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:01:45 by paescano          #+#    #+#             */
/*   Updated: 2023/12/08 16:10:48 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main( void )
{
	FragTrap a;
	FragTrap b("jose");

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
	a.highFivesGuys();
	return (0);
};
