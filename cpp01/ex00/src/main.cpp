/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:26:07 by paescano          #+#    #+#             */
/*   Updated: 2023/11/27 16:14:19 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie( std::string name );
void randomChump( std::string name );

int	main( void )
{
	Zombie*	undead;

	undead = newZombie("Pablo");
	randomChump("Juan");
	undead->announce();
	delete undead;
	return (0);
}
