/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:10:05 by paescano          #+#    #+#             */
/*   Updated: 2023/12/12 16:32:48 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void): AMateria() {
	this->_type = "ice";
}

Ice::Ice(Ice const & src): AMateria(src) {
	*this = src;
}

Ice::~Ice(void) {
}

Ice & Ice::operator=(Ice const & src) {
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

AMateria * Ice::clone(void) const {
	return (new Ice());
}

void Ice::use(ICharacter & target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
