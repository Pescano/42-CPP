/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:06:08 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 17:11:45 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void): Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	this->setType("Dog");
	this->_brain = new Brain();
}

Dog::Dog(Dog const & src): Animal(src) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
	std::cout << "testing deep copy" << std::endl;
	std::cout << "source brain: "<< &src._brain << std::endl;
	std::cout << "this->_brain: "<< &this->_brain << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete this->_brain;
}

Dog &	Dog::operator=(Dog const & src) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &src)
	{
		this->setType(src.getType());
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

void	Dog::makeSound(void) const {
	std::cout << "Guau" << std::endl;
}
