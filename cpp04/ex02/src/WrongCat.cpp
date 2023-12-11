/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:10:49 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 12:49:38 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "WrongCat default constructor called" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & src) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = src;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &	WrongCat::operator=(WrongCat const & src) {
	std::cout << "WrongCat assignation operator called" << std::endl;
	if (this != &src)
		this->_type = src._type;
	return *this;
}

void		WrongCat::makeSound( void ) const {
	std::cout << "WrongCat sound" << std::endl;
}
