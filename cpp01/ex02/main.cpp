/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:38:49 by paescano          #+#    #+#             */
/*   Updated: 2023/11/27 18:01:33 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main( void )
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << "Address of the string: " << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "Address of string:\t" << &string << std::endl;
	std::cout << "Address of stringPTR:\t" << stringPTR << std::endl;
	std::cout << "Address of stringREF:\t" << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "Value of the string: " << std::endl;
	std::cout << "----------------------" << std::endl;
	std::cout << "Value of string:\t" << string << std::endl;
	std::cout << "Value of stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "Value of stringREF:\t" << stringREF << std::endl;
	return (0);
}
