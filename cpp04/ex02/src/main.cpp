/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:10:04 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 17:40:20 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define SIZE 10

int	main(void) {
	const Animal* array[SIZE];

	std::cout << "------------------" << std::endl;
	std::cout << "----  Dogs   -----" << std::endl;
	std::cout << "------------------" << std::endl;
	for (int i = 0; i < SIZE / 2 ; i++)
		array[i] = new Dog();
	std::cout << "------------------" << std::endl;
	std::cout << "----  Cats   -----" << std::endl;
	std::cout << "------------------" << std::endl;
	for (int i = SIZE / 2; i < SIZE; i ++)
		array[i] = new Cat();
	std::cout << "------------------" << std::endl;
	std::cout << "----  Array  -----" << std::endl;
	std::cout << "------------------" << std::endl;
	for (int i = 0; i < SIZE; i++)
		std::cout << array[i]->getType() << std::endl;
	std::cout << "------------------" << std::endl;
	std::cout << "---- Deletes -----" << std::endl;
	std::cout << "------------------" << std::endl;
	for (int i = 0; i < SIZE; i++)
		delete array[i];
	std::cout << "------------------" << std::endl;
	std::cout << "---- Cpy Cons ----" << std::endl;
	std::cout << "------------------" << std::endl;
	const Dog*	dog1;
	const Dog*	dog2;
	dog1 = new Dog();
	dog2 = new Dog(*dog1);
	std::cout << "------------------" << std::endl;
	std::cout << "---- Del Cpy -----" << std::endl;
	std::cout << "------------------" << std::endl;
	delete dog1;
	delete dog2;
	// Test for abstract class
	//Animal cat;
	return (0);
}
