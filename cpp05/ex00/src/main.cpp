/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:39:37 by paescano          #+#    #+#             */
/*   Updated: 2023/12/13 15:45:05 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat a;
	Bureaucrat b("Jose", 1);
	Bureaucrat c("Pepe", 75);

	std::cout << "--------------------------" << std::endl;
	std::cout << "------- Bureaucrat -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "------- Increment  -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	try {
		b.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << b << std::endl;
	try {
		c.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << c << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "------- Decrement  -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	try {
		a.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << a << std::endl;
	try {
		c.decrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << c << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "------- Exceptions -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	try {
		Bureaucrat  d("luis", 200);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	try {
		Bureaucrat  e("carlos", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
