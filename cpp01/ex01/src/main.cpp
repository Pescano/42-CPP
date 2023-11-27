/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:26:07 by paescano          #+#    #+#             */
/*   Updated: 2023/11/27 17:23:42 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int	main( void )
{
	Zombie*	undead;
	int		n = 5;

	undead = zombieHorde(n, "pepe");
	for (int i = 0; i < n; i++)
		undead[i].announce();	
	delete [] undead;
	return (0);
}
