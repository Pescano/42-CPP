/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:05:47 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 16:42:47 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->setType("Cat");
	this->_brain = new Brain();
}

Cat::Cat(Cat const & src): Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	this->_brain = new Brain(*src._brain);
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

Cat &	Cat::operator=(Cat const & src) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
	{
		this->setType(src.getType());
		this->_brain = new Brain(*src._brain);
	}
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Miau" << std::endl;
}