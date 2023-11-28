/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:10:40 by paescano          #+#    #+#             */
/*   Updated: 2023/11/28 13:31:26 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( void ) {
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon( void ) {
}

const std::string&	Weapon::getType( void ) const {
	return this->_type;
}

void	Weapon::setType( std::string type ) {
	this->_type = type;
}
