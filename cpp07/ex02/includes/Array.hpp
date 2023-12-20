/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:24:39 by paescano          #+#    #+#             */
/*   Updated: 2023/12/20 17:45:13 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

template< typename T >
class Array
{
	private:
		unsigned int	_size;
		T	*			_array;
	public:
		Array( void ): _size(0)
		{
			this->_array = new T[0];
		};
		Array( unsigned int n ): _size(n)
		{
			this->_array = new T[n];
			for (unsigned int i = 0; i < _size; i++)
				this->_array[i] = 0;
		};
};

#endif