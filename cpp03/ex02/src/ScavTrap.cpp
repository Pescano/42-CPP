/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:02:44 by paescano          #+#    #+#             */
/*   Updated: 2023/12/06 16:48:19 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	std::cout << "ScavTrap default constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage= 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "ScavTrap name constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage= 20;
}

ScavTrap::ScavTrap( ScavTrap const & s ) : ClapTrap(s)
{
	std::cout << "ScavTrap copy constructor called." << std::endl;
}

ScavTrap::~ScavTrap( void )
{
	std::cout << "ScavTrap destructor called." << std::endl;
}

ScavTrap &	ScavTrap::operator=( ScavTrap const & s )
{
	std::cout << "ScavTrap assignation operator called" << std::endl;
	if (this != &s)
	{
		ClapTrap::operator=(s);
	}
	return *this;
}

void	ScavTrap::attack( const std::string & target )
{
	if (getEnergyPoints() < 1 && getHitPoints() < 1)
		std::cout << "ScavTrap " << getName() << " has no energy points and no hit points!" << std::endl;
	else if (getEnergyPoints() < 1 && getHitPoints() > 0)
		std::cout << "ScavTrap " << getName() << " has no energy points!" << std::endl;
	else if (getEnergyPoints() > 0 && getHitPoints() < 1)
		std::cout << "ScavTrap " << getName() << " has no hit points!" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
}

void	ScavTrap::guardGate( void )
{
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}
