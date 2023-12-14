/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:58 by paescano          #+#    #+#             */
/*   Updated: 2023/12/14 17:04:24 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
	this->_target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5) {
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute()) {
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &	PresidentialPardonForm::operator=(PresidentialPardonForm const & src) {
	if (this != &src)
	{
		setSigned(src.getSigned());
		this->_target = src.getTarget();
	}
	return *this;
}

std::string		PresidentialPardonForm::getTarget() const {
	return this->_target;
}

void			PresidentialPardonForm::executeAction() const {
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
