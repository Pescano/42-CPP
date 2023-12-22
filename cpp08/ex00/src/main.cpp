/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 13:06:09 by paescano          #+#    #+#             */
/*   Updated: 2023/12/22 15:59:14 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> v;
	std::list<int> l;

	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);

	try
	{
		std::cout << *easyfind(v, 3) << std::endl;
		std::cout << *easyfind(l, 3) << std::endl;
		std::cout << *easyfind(v, 5) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}