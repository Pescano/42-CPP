/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:50:04 by paescano          #+#    #+#             */
/*   Updated: 2023/12/12 15:50:33 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(void) {
}

AMateria::AMateria(std::string const & type) {
	this->_type = type;
}

AMateria::AMateria(AMateria const & src) {
	*this = src;
}

AMateria::~AMateria(void) {
}

AMateria & AMateria::operator=(AMateria const & src) {
	if (this != &src)
		this->_type = src.getType();
	return (*this);
}

std::string const & AMateria::getType(void) const {
	return (this->_type);
}