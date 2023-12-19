/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:41:29 by paescano          #+#    #+#             */
/*   Updated: 2023/12/18 18:08:14 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <exception>

// void ft_leaks() {
// 	system("leaks -q dinamyc_cast");
// }

Base *generate(void) {
	int i = rand() % 3;
	if (i == 0) {
		std::cout << "A generated" << std::endl;
		return new A;
	}
	else if (i == 1) {
		std::cout << "B generated" << std::endl;
		return new B;
	}
	else {
		std::cout << "C generated" << std::endl;
		return new C;
	}
}

void identify(Base *base) {
	if (dynamic_cast<A *>(base))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(base))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C *>(base))
		std::cout << "C" << std::endl;
}

void identify(Base &base) {
	try {
		A &a = dynamic_cast<A &>(base);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B &>(base);
			std::cout << "B" << std::endl;
			(void)b;
		}
		catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C &>(base);
				std::cout << "C" << std::endl;
				(void)c;
			}
			catch (std::exception &e) {
				std::cerr << "Error" << std::endl;
			}
		}
	}
}

int main(void) {
	// atexit(ft_leaks);
    Base * base;

    std::srand(std::time(NULL));
    for (int i = 0; i < 10; i++)
    {
		std::cout << "--------------"<< std::endl;
        std::cout << "--- Base " << i + 1 << " ---" << std::endl;
		std::cout << "--------------"<< std::endl;
        base = generate();
		std::cout << "Type ptr: "<< std::endl;
        identify(base);
		std::cout << "Type reference"<< std::endl;
        identify(*base);
        delete base;
        std::cout << std::endl;
    }
    return 0;
}