/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:34 by paescano          #+#    #+#             */
/*   Updated: 2023/12/15 13:19:06 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
//#include "AForm.hpp"

int main()
{
	    Bureaucrat  a("Jose", 1);
        Bureaucrat  b("Pepe", 72);

        ShrubberyCreationForm       fS("Shrubbery");
        RobotomyRequestForm         fR("Robotomy");
        PresidentialPardonForm      fP("Pardon");

		std::cout << "------------------" << std::endl;
		std::cout << "--- Bureaucrat ---" << std::endl;
		std::cout << "------------------" << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;

		std::cout << "-----------------" << std::endl;
		std::cout << "--- Shrubbery ---" << std::endl;
		std::cout << "-----------------" << std::endl;
		std::cout << fS << std::endl;
		std::cout << "--- Execution without sign test ---" << std::endl;
        b.executeForm(fS);
		std::cout << std::endl;
		std::cout << "--- Sign test ---" << std::endl;
        b.signForm(fS);
        std::cout << fS << std::endl;
		std::cout << "--- Execution test ---" << std::endl;
        b.executeForm(fS);
		std::cout << std::endl;

		std::cout << "----------------" << std::endl;
		std::cout << "--- Robotomy ---" << std::endl;
		std::cout << "----------------" << std::endl;
		std::cout << fR << std::endl;
		std::cout << "--- Execution without sign test ---" << std::endl;
		b.executeForm(fR);
		std::cout << std::endl;
		std::cout << "--- Sign test ---" << std::endl;
		b.signForm(fR);
		std::cout << fR << std::endl;
		a.signForm(fR);
		std::cout << fR << std::endl;
		std::cout << "--- Execution test ---" << std::endl;
		b.executeForm(fR);
		a.executeForm(fR);
		std::cout << std::endl;
		
		std::cout << "--------------------" << std::endl;
		std::cout << "--- Presidential ---" << std::endl;
		std::cout << "--------------------" << std::endl;
		std::cout << fP << std::endl;
		std::cout << "--- Execution without sign test ---" << std::endl;
		b.executeForm(fP);
		std::cout << std::endl;
		std::cout << "--- Sign test ---" << std::endl;
		b.signForm(fP);
		std::cout << fP << std::endl;
		a.signForm(fP);
		std::cout << fP << std::endl;
		std::cout << "--- Execution test ---" << std::endl;
		b.executeForm(fP);
		a.executeForm(fP);
		std::cout << std::endl;
		//AForm z;
	return(0);
}