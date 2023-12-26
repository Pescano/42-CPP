/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:05:56 by paescano          #+#    #+#             */
/*   Updated: 2023/12/26 17:38:04 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void)
{
	Span test(1);
	Span test2(5);
	std::vector<int> array(10000);
	std::srand(time(NULL));
	std::generate(array.begin(), array.end(), std::rand);
	Span test3(array.size());

	std::cout << "---------------------------" << std::endl;
	std::cout << "--- Test with 1 numbers ---" << std::endl;
	std::cout << "---------------------------" << std::endl;
	test.addNumber(6);
	try {
		test.addNumber(3);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Longest span: " << test.longestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		std::cout << "Shortest span: " << test.shortestSpan() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << "---------------------------" << std::endl;
	std::cout << "--- Test with 5 numbers ---" << std::endl;
	std::cout << "---------------------------" << std::endl;
    test2.addNumber(6);
    test2.addNumber(3);
    test2.addNumber(17);
    test2.addNumber(9);
    test2.addNumber(11);
	std::cout << "Longest span: " << test2.longestSpan() << std::endl;
	std::cout << "Shortest span: " << test2.shortestSpan() << std::endl;
	std::cout << "-------------------------------" << std::endl;
	std::cout << "--- Test with 10000 numbers ---" << std::endl;
	std::cout << "-------------------------------" << std::endl;
	test3.addNumber(array.begin(), array.end());
	std::cout << "Longest span: " << test3.longestSpan() << std::endl;
	std::cout << "Shortest span: " << test3.shortestSpan() << std::endl;
	return (0);
}
