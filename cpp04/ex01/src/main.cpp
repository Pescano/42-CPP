/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:10:04 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 12:56:52 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void) {
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;
	std::cout << "animal->getType(): " << animal->getType() << std::endl;
	std::cout << "dog->getType(): " << dog->getType() << std::endl;
	std::cout << "cat->getType(): " << cat->getType() << std::endl;
	std::cout << std::endl;
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	std::cout << std::endl;
	delete animal;
	delete dog;
	delete cat;
	std::cout << std::endl;
	const WrongAnimal*	wronganimal = new WrongAnimal();
	const WrongAnimal*	wrongcat = new WrongCat();
	const WrongCat*		wrongcat2 = new WrongCat();
	std::cout << std::endl;
	wronganimal->makeSound();
	wrongcat->makeSound();
	wrongcat2->makeSound();
	std::cout << std::endl;
	delete wronganimal;
	delete wrongcat;
	delete wrongcat2;
	return (0);
}
