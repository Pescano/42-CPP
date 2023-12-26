/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:48:22 by paescano          #+#    #+#             */
/*   Updated: 2023/12/26 17:38:45 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "------------------------" << std::endl;
	std::cout << "--- MutantStack test ---" << std::endl;
	std::cout << "------------------------" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: "<< mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "iterator: " << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "-----------------" << std::endl;
	std::cout << "--- List test ---" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::list<int> test;
	test.push_back(5);
	test.push_back(17);
	std::cout << "top: " << test.back() << std::endl;
	test.pop_back();
	std::cout << "size: " << test.size() << std::endl;
	test.push_back(3);
	test.push_back(5);
	test.push_back(737);
	test.push_back(0);
	std::list<int>::iterator it2 = test.begin();
	std::list<int>::iterator ite2 = test.end();
	++it2;
	--it2;
	std::cout << "iterator: " << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	return (0);
}