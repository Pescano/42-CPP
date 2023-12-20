/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:07:02 by paescano          #+#    #+#             */
/*   Updated: 2023/12/20 12:55:38 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP_
# define WHATEVER_HPP_

#include <iostream>

template<typename T>
void swap(T& a, T& b) 
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
const T& max(const T& x, const T& y) 
{
	return (x > y) ? x : y;
}

template<typename T>
const T& min(const T& x, const T& y) 
{
	return (x < y) ? x : y;
}

#endif
