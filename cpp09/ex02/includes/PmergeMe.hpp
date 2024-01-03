/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:32:10 by paescano          #+#    #+#             */
/*   Updated: 2024/01/03 15:15:40 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <chrono>
# include <list>
# include <algorithm>
# include <vector>
# include <iomanip>

template <typename T>
void	print(T &container);

void	checkArgs(int argc, char **argv);
void	mergeSortVector(std::vector<int> &v);
void	mergeSortList(std::list<int> &l);
void	PmergeMe(int argc, char **argv);

#endif