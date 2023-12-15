/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:38:02 by paescano          #+#    #+#             */
/*   Updated: 2023/12/15 17:28:01 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() 
{
    this->_forms[0] = new ShrubberyCreationForm();
    this->_forms[1] = new RobotomyRequestForm();
    this->_forms[2] = new PresidentialPardonForm();
};

Intern::Intern(Intern const & src) 
{
    (void) src;
    this->_forms[0] = new ShrubberyCreationForm();
    this->_forms[1] = new RobotomyRequestForm();
    this->_forms[2] = new PresidentialPardonForm();
};

Intern::~Intern() 
{
    delete _forms[0];
    delete _forms[1];
    delete _forms[2];
};

Intern & Intern::operator=(Intern const & src) 
{
    (void) src;
    return *this;
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string names[] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (_forms[i]->clone(target));
		}
	}
	std::cout << "Intern can't create " << name << std::endl;
	return (NULL);
}
