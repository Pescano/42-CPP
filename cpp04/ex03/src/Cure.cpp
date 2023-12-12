/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:09:51 by paescano          #+#    #+#             */
/*   Updated: 2023/12/12 16:32:52 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void): AMateria() {
	this->_type = "cure";
}

Cure::Cure(Cure const & src): AMateria(src) {
	*this = src;
}

Cure::~Cure(void) {
}

Cure & Cure::operator=(Cure const & src) {
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

AMateria * Cure::clone(void) const {
	return (new Cure());
}

void Cure::use(ICharacter & target) {
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
