/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:10:22 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 12:45:05 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
	this->_type = "WrongAnimal";
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = src;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &	WrongAnimal::operator=(WrongAnimal const & src) {
	std::cout << "WrongAnimal assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void			WrongAnimal::setType(std::string type) {
	this->_type = type;
}

std::string		WrongAnimal::getType(void) const {
	return this->_type;
}

void			WrongAnimal::makeSound( void ) const {
	std::cout << "WrongAnimal sound" << std::endl;
}
