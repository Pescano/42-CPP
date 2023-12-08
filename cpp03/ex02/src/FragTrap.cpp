/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:14:43 by paescano          #+#    #+#             */
/*   Updated: 2023/12/08 16:29:30 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap()
{
	std::cout << "FragTrap default constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage= 30;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name)
{
	std::cout << "FragTrap name constructor called." << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage= 30;
}

FragTrap::FragTrap( FragTrap const & s ) : ClapTrap(s)
{
	std::cout << "FragTrap copy constructor called." << std::endl;
}

FragTrap::~FragTrap( void )
{
	std::cout << "FragTrap destructor called." << std::endl;
}

FragTrap &	FragTrap::operator=( FragTrap const & s )
{
	std::cout << "FragTrap assignation operator called" << std::endl;
	if (this != &s)
	{
		ClapTrap::operator=(s);
	}
	return *this;
}

void	FragTrap::attack( const std::string & target )
{
	if (getEnergyPoints() < 1 && getHitPoints() < 1)
		std::cout << "FragTrap " << getName() << " has no energy points and no hit points!" << std::endl;
	else if (getEnergyPoints() < 1 && getHitPoints() > 0)
		std::cout << "FragTrap " << getName() << " has no energy points!" << std::endl;
	else if (getEnergyPoints() > 0 && getHitPoints() < 1)
		std::cout << "FragTrap " << getName() << " has no hit points!" << std::endl;
	else
	{
		this->_energyPoints--;
		std::cout << "FragTrap " << getName() << " attacks " << target << ", causing " << getAttackDamage() << " points of damage!" << std::endl;
	}
}

void	FragTrap::highFivesGuys( void )
{
	std::cout << "FragTrap " << getName() << " is doing a high fives." << std::endl;
}
