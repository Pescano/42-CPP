/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:34 by paescano          #+#    #+#             */
/*   Updated: 2023/12/15 18:01:36 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

void ft_leaks()
{
	system("leaks intern");
}

int main(void)
{
	atexit(ft_leaks);

	Bureaucrat a("Pepe", 1);
	Intern inter;

	std::cout << "------------------------" << std::endl;
	std::cout << "---Presidential test ---" << std::endl;
	std::cout << "------------------------" << std::endl;
	AForm *form = inter.makeForm("presidential pardon", "bender");
	if (form)
	{
		std::cout << *form << std::endl;
		a.executeForm(*form);
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "---Robotomy test -------" << std::endl;
	std::cout << "------------------------" << std::endl;
	form = inter.makeForm("robotomy request", "bender");
	if (form)
	{
		std::cout << *form << std::endl;
		a.executeForm(*form);
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "---Shrubbery test ------" << std::endl;
	std::cout << "------------------------" << std::endl;
	form = inter.makeForm("shrubbery creation", "bender");
	if (form)
	{
		std::cout << *form << std::endl;
		a.executeForm(*form);
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}
	std::cout << "------------------------" << std::endl;
	std::cout << "---Unknown test --------" << std::endl;
	std::cout << "------------------------" << std::endl;
	form = inter.makeForm("Unknow", "bender");
	if (form)
	{
		std::cout << *form << std::endl;
		a.executeForm(*form);
		a.signForm(*form);
		a.executeForm(*form);
		delete form;
	}
	return (0);
}