/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:10:50 by paescano          #+#    #+#             */
/*   Updated: 2023/12/20 16:51:55 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template< typename T >
void print(T & x)
{
	std::cout << x << std::endl;
}

void printChar(char & x )
{
	std::cout << x << std::endl;
}

void printInt(int & x )
{
	std::cout << x << std::endl;
}

int main()
{
	int		int_array[5] = {1, 2, 3, 4, 5};
	char	char_array[5] = {'a', 'b', 'c', 'd', 'e'};

	std::cout << "--------------------" << std::endl;
	std::cout << "---Print template---" << std::endl;
	std::cout << "--------------------" << std::endl;
	std::cout << "int_array:" << std::endl;
	iter(int_array, 5, print<int>);
	std::cout << std::endl;
	std::cout << "char_array:" << std::endl;
	iter(char_array, 5, print<char>);

	std::cout << "---------------" << std::endl;
	std::cout << "---Print int---" << std::endl;
	std::cout << "---------------" << std::endl;
	std::cout << "int array:" << std::endl;
	iter(int_array, 5, printInt);
	
	std::cout << "----------------" << std::endl;
	std::cout << "---print char---" << std::endl;
	std::cout << "----------------" << std::endl;
	std::cout << "char array:" << std::endl;
	iter(char_array, 5, printChar);
}