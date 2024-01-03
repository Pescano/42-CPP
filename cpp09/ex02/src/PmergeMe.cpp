/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:55:55 by paescano          #+#    #+#             */
/*   Updated: 2024/01/03 15:12:26 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template <typename T>
void	print(T &container)
{
	for (typename T::iterator it = container.begin(); it != container.end(); ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void mergeSortVector(std::vector<int> &vct)
{
	if (vct.size() <= 1)
		return;
	std::vector<int> left, right;
	int middle = vct.size() / 2;
	for (int i = 0; i < middle; ++i)
		left.push_back(vct[i]);
	for (int i = middle; i < (int)vct.size(); ++i)
		right.push_back(vct[i]);
	mergeSortVector(left);
	mergeSortVector(right);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), vct.begin());
}

void mergeSortList(std::list<int> &lst)
{
	if (lst.size() <= 1)
		return;
	std::list<int> left, right;
	int middle = lst.size() / 2;
	std::list<int>::iterator it = lst.begin();
	for (int i = 0; i < middle; ++i)
		left.push_back(*it++);
	for (int i = middle; i < (int)lst.size(); ++i)
		right.push_back(*it++);
	mergeSortList(left);
	mergeSortList(right);
	left.merge(right);
	lst = left;
}

void checkArgs(int argc, char **argv)
{
	try
	{
		for (int i = 1; i < argc; ++i)
		{
			for (int j = 0; argv[i][j]; ++j)
			{
				if (!isdigit(argv[i][j]))
					throw std::exception();
			}
			if (atoi(argv[i]) < 0)
				throw std::exception();
		}
	}
	catch (std::exception &e)
	{
		std::cerr << "Error: Usage: ./PmergeMe <positive_integers>" << std::endl;
		exit(1);
	}
}

void PmergeMe(int argc, char **argv)
{
	double	vct_time;
	double	lst_time;
	std::vector<int> vct;
	std::list<int> lst;
	std::clock_t time;
	std::cout << std::fixed << std::setprecision(9);
	checkArgs(argc, argv);
	std::cout << "Before:\t";
	for (int i = 1; i < argc; ++i)
	{
		vct.push_back(atoi(argv[i]));
		lst.push_back(atoi(argv[i]));
	}
	print(lst);
	time = std::clock();
	mergeSortVector(vct);
	vct_time = (std::clock() - time) / (double)(CLOCKS_PER_SEC * 1000);
	time = std::clock();
	mergeSortList(lst);
	lst_time = (std::clock() - time) / (double)(CLOCKS_PER_SEC * 1000);
	std::cout << "After:\t";
	print(vct);
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << vct_time << " us" << std::endl;
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::list : " << lst_time << " us" << std::endl;
}
