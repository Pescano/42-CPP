/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:08 by paescano          #+#    #+#             */
/*   Updated: 2023/12/09 19:37:13 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->setType("Dog");
}

Dog::Dog(Dog const & src): Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = src;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog &	Dog::operator=(Dog const & src) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
		this->setType(src.getType());
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Guau" << std::endl;
}
