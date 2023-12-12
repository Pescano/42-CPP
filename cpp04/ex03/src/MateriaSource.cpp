/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:10:30 by paescano          #+#    #+#             */
/*   Updated: 2023/12/12 16:44:34 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) {
	this->_count = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

MateriaSource::MateriaSource(MateriaSource const & src) {
	this->_count = 0;
	for (int i = 0; i < 4; i++)
	{
		if (i < src._count)
			this->learnMateria(src._inventory[i]->clone());
		else
			this->_inventory[i] = NULL;
	}
}

MateriaSource::~MateriaSource(void) {
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

MateriaSource & MateriaSource::operator=(MateriaSource const & src) {
	if (this != &src)
	{
		for (int i = 0; i < 4; i++)
		{
			if (i < src._count)
				this->learnMateria(src._inventory[i]->clone());
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria *m) {
	if (this->_count < 4)
	{
		this->_inventory[this->_count] = m;
		this->_count++;
	} 
	else
	{
		delete m;
		std::cout << "Inventory is full" << std::endl;
	}	
}

AMateria * MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < this->_count; i++)
	{
		if (this->_inventory[i]->getType() == type)
			return (this->_inventory[i]->clone());
	}
	return (NULL);
}
