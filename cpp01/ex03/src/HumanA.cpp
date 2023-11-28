/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:10:35 by paescano          #+#    #+#             */
/*   Updated: 2023/11/28 16:51:13 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon) {
        this->_name = name;
}

HumanA::~HumanA( void ) {
}

void	HumanA::attack( void ) {
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
