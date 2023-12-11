/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:05:33 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 17:36:56 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal default constructor called" << std::endl;
	this->_type = "Animal";
}

Animal::Animal(Animal const & src) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &	Animal::operator=(Animal const & src) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void		Animal::setType(std::string type) {
	this->_type = type;
}

std::string	Animal::getType(void) const {
	return this->_type;
}
