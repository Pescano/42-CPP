/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:01:38 by paescano          #+#    #+#             */
/*   Updated: 2023/12/08 15:48:31 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap default Constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap name Constructor called." << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "ClapTrap copy Constructor called." << std::endl;
	*this = src;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called." << std::endl;
}

ClapTrap &	ClapTrap::operator=(ClapTrap const & src) {
	std::cout << "ClapTrap assignation operator called." << std::endl;
	if (this != &src) {
		this->_name = src._name;
		this->_hitPoints = src._hitPoints;
		this->_energyPoints = src._energyPoints;
		this->_attackDamage = src._attackDamage;
	}
	return *this;
}

std::string		ClapTrap::getName(void) const {
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints(void) const {
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const {
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDamage(void) const {
	return this->_attackDamage;
}

void	ClapTrap::attack(std::string const & target) {
	if (getEnergyPoints() < 1 && getHitPoints() < 1)
		std::cout << "ClapTrap " << getName() << " has no energy points and no hit points!" << std::endl;
	else if (getEnergyPoints() < 1 && getHitPoints() > 0)
		std::cout << "ClapTrap " << getName() << " has no energy points!" << std::endl;
	else if (getEnergyPoints() > 0 && getHitPoints() < 1)
		std::cout << "ClapTrap " << getName() << " has no hit points!" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ClapTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (amount > getHitPoints())
		this->_hitPoints = 0;
	else
		this->_hitPoints -= amount;
	std::cout << "ClapTrap " << getName() << " takes " << amount << " points of damage!" << std::endl;
	if(getHitPoints() > 0)
		std::cout << "ClapTrap " << getName() << " has " << getHitPoints() << " hit_points left" << std::endl;
	else
		std::cout << "ClapTrap " << getName() << " is without hit_points" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (getEnergyPoints() == 0)
		std::cout << "ClapTrap " << getName() << " has no energy points, can't be repaired!" << std::endl;
	else
	{
		if (amount + this->_hitPoints > MAX_HP)
			this->_hitPoints = MAX_HP;
		else
			this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << getName() << " has been repaired with " << amount << " hit points!" << std::endl;
	}
}

std::ostream &	operator<<(std::ostream & o, ClapTrap const & src) {
	o << src.getName() << " has " << src.getHitPoints() << " hit points, " << src.getEnergyPoints() << " energy points and " << src.getAttackDamage() << " attack damage" << std::endl;
	return o;
}
