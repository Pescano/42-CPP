/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:39:37 by paescano          #+#    #+#             */
/*   Updated: 2023/12/14 12:12:35 by paescano         ###   ########.fr       */
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
	std::cout << "a bureaucrat:" << std::endl;
	std::cout << a << std::endl;
	std::cout << "b bureaucrat:" << std::endl;
	std::cout << b << std::endl;
	std::cout << "c bureaucrat:" << std::endl;
	std::cout << c << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "------- Increment  -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "b increment message:" << std::endl;
	b.incrementGrade();
	std::cout << b << std::endl;
	std::cout << "c increment message:" << std::endl;
	c.incrementGrade();
	std::cout << c << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "------- Decrement  -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "a decrement message:" << std::endl;
	a.decrementGrade();
	std::cout << a << std::endl;
	std::cout << "c decrement message:" << std::endl;
	c.decrementGrade();
	std::cout << c << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "------- Exceptions -------" << std::endl;
	std::cout << "--------------------------" << std::endl;
	std::cout << "creation d with grade 200 bureaucrat:" << std::endl;
	Bureaucrat  d("luis", 200);
	std::cout << d << std::endl;
	std::cout << "creation e with grade 0 bureaucrat:" << std::endl;
	Bureaucrat  e("carlos", 0);
	std::cout << e << std::endl;
	return (0);
}
