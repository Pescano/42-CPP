/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:53:22 by paescano          #+#    #+#             */
/*   Updated: 2023/12/18 17:16:16 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main( void )
{
	Data		original;
	uintptr_t	serial;
	Data *		modified;

	original.str = "hola mundo";
	original.number = 25;
	serial = Serializer::serialize(&original);
	modified = Serializer::deserialize(serial);
	std::cout << "-----------------------" << std::endl;
	std::cout << "---- Original data ----" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Address: " << &original << std::endl;
	std::cout << "str:     " << original.str << std::endl;
	std::cout << "number:  " << original.number << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "--- Serialized data ---" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "serial:  " << serial << std::endl;
	std::cout << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "---- Modified data ----" << std::endl;
	std::cout << "-----------------------" << std::endl;
	std::cout << "Address: " << modified << std::endl;
	std::cout << "str:     " << modified->str << std::endl;
	std::cout << "number:  " << modified->number << std::endl;
	std::cout << std::endl;
	
	return (0);
}