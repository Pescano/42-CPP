/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:05:47 by paescano          #+#    #+#             */
/*   Updated: 2023/12/09 19:23:55 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void): Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	this->setType("Cat");
}

Cat::Cat(Cat const & src): Animal(src) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = src;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

Cat &	Cat::operator=(Cat const & src) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &src)
		this->setType(src.getType());
	return *this;
}

void	Cat::makeSound(void) const {
	std::cout << "Miau" << std::endl;
}