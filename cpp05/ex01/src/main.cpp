/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:39:37 by paescano          #+#    #+#             */
/*   Updated: 2023/12/14 13:33:51 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Bureaucrat a("Juan", 1);
	Bureaucrat b("Jose", 75);
	Bureaucrat c("Pepe", 150);

	std::cout << "--------------------------" << std::endl;
	std::cout << "------- Bureaucrat -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "-------    Form    -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "Form 1:" << std::endl;
	Form f1("f1", 1, 1);
	std::cout << f1 << std::endl;
	std::cout << "Form 2:" << std::endl;
	Form f2("f2", 125, 125);
	std::cout << f2 << std::endl;
	std::cout << "Form 3:" << std::endl;
	Form f3("f3", 170, 20);
	std::cout << f3 << std::endl;
	std::cout << "Form 4:" << std::endl;
	Form f4("f4", 120, -20);
	std::cout << f4 << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "-------    Sign    -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	c.signForm(f2);
	std::cout << f2 << std::endl;
	b.signForm(f2);
	std::cout << f2 << std::endl;
	a.signForm(f2);
	std::cout << f2 << std::endl;
	a.signForm(f1);
	std::cout << f1 << std::endl;
	return (0);
}
