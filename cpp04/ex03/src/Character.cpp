/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:09:32 by paescano          #+#    #+#             */
/*   Updated: 2023/12/12 17:24:33 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(void) {
	this->_name = "Default";
	this->_count = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(std::string const & name) {
	this->_name = name;
	this->_count = 0;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const & src) {
	this->_name = src.getName();
	this->_count = 0;
	for (int i = 0; i < 4; i++)
    {
        if (i < src._count)
            this->equip(src._inventory[i]->clone());
        else
            this->_inventory[i] = NULL;
    }
}

Character::~Character(void) {
	for (int i = 0; i < 4; i++)
		delete this->_inventory[i];
}

Character & Character::operator=(Character const & src) {
	if (this != &src)
	{
		this->_name = src.getName();
		for (int i = 0; i < 4; i++)
		{
			if (i < src._count)
				this->equip(src._inventory[i]->clone());
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

std::string const & Character::getName(void) const {
	return (this->_name);
}

void Character::equip(AMateria * m) {
	if (this->_count < 4 && m)
	{
		this->_inventory[this->_count] = m;
		this->_count++;
	} else
		std::cout << "Inventory is full or materia is NULL" << std::endl;
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < this->_count)
	{
		for (int i = idx; i < this->_count - 1; i++)
			this->_inventory[i] = this->_inventory[i + 1];
		this->_inventory[this->_count - 1] = NULL;
		this->_count--;
	} else
		std::cout << "Index out of range" << std::endl;
}

void Character::use(int idx, ICharacter & target) {
	if (idx >= 0 && idx < this->_count && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else
		std::cout << "Index out of range or materia is NULL" << std::endl;
}
