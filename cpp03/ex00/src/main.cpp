/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:44:03 by paescano          #+#    #+#             */
/*   Updated: 2023/12/06 17:53:41 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap a;
	ClapTrap b("jose");

	std::cout << a;
	std::cout << b;
	for(int i = 11; i > 0; i--)
		a.attack("pepe");
	std::cout << a;
	for(int i = 11; i > 0; i--)
		b.takeDamage(1);
	b.beRepaired(100);
	std::cout << b;
	a.beRepaired(100);

	return (0);
};
