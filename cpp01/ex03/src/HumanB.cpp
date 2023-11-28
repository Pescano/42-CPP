/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:22:05 by paescano          #+#    #+#             */
/*   Updated: 2023/11/28 16:45:16 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ){
	this->_name = name;
}

HumanB::~HumanB( void ) {
}

void	HumanB::setWeapon( Weapon &weapon ) {
	this->_weapon = &weapon;
}

void	HumanB::attack( void ) {
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}
