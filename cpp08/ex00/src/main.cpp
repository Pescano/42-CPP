/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:06:09 by paescano          #+#    #+#             */
/*   Updated: 2023/12/26 17:35:15 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::list<int>		l;
	std::vector<int>	v;

	for (int i = 0; i < 10; i++)
	{
		l.push_back(i * i);
		v.push_back(i * i);
	}
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "--- Content of the list container ---" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
	for ( std::list<int>::iterator n = l.begin(); n != l.end(); n++)
		std::cout << *n << " ";
	std::cout << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << "--- Content of the vector container ---" << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	for (std::vector<int>::iterator n = v.begin(); n != v.end(); n++)
		std::cout << *n << " ";
	std::cout << std::endl;
	try
	{
		std::cout << "------------------------------------" << std::endl;
		std::cout << "--- Searching for 25 in the list ---" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Found: " << *easyfind(l, 25) << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "--- Searching for 67 in the list ---" << std::endl;
		std::cout << "------------------------------------" << std::endl;
		std::cout << "Found: " << *easyfind(l, 67) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "--- Searching for 25 in the vector ---" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Found: " << *easyfind(v, 25) << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "--- Searching for 67 in the vector ---" << std::endl;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Found: " << *easyfind(v, 67) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}