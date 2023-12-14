/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:38:21 by paescano          #+#    #+#             */
/*   Updated: 2023/12/14 17:19:04 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	this->_target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45) {
	this->_target = target;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &	RobotomyRequestForm::operator=(RobotomyRequestForm const & src) {
	if (this != &src)
	{
		setSigned(src.getSigned());
		this->_target = src.getTarget();
	}
	return *this;
}

std::string		RobotomyRequestForm::getTarget() const {
	return this->_target;
}

void			RobotomyRequestForm::executeAction() const {
	srand(time(NULL));
	if (rand() & 1)
		std::cout << this->_target << " has been robotomized successfully." << std::endl;
	else
		std::cout << this->_target << " robotomization failed." << std::endl;
}
