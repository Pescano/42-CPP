/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:31:47 by paescano          #+#    #+#             */
/*   Updated: 2023/12/15 13:01:58 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	try {
		if (gradeToSign < 1 || gradeToExecute < 1)
			throw GradeTooHighException();
		else if (gradeToSign > 150 || gradeToExecute > 150)
			throw GradeTooLowException();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

AForm::AForm(AForm const & src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {
}

AForm::~AForm() {
}

AForm &	AForm::operator=(AForm const & src) {
	if (this != &src)
		_signed = src.getSigned();
	return *this;
}

std::string	AForm::getName() const {
	return _name;
}

bool		AForm::getSigned() const {
	return _signed;
}

int			AForm::getGradeToSign() const {
	return _gradeToSign;
}

int			AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void		AForm::setSigned(bool value) {
	_signed = value;
}

void		AForm::beSigned(Bureaucrat const & src) {
	try {
		if (src.getGrade() > _gradeToSign)
			throw GradeTooLowException();
		else
			_signed = true;
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

void		AForm::execute(Bureaucrat const & src) const {
	try {
		if (!this->_signed)
			throw FormNotSignedException();
		else if (src.getGrade() > _gradeToExecute)
			throw GradeTooLowException();
		else
			executeAction();
	}
	catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "<GradeTooHighException>: Grade too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "<GradeTooLowException>: Grade too low";
}

const char* AForm::FormNotSignedException::what() const throw() {
	return "<FormNotSignedException>: Form not signed";
}

std::ostream &	operator<<(std::ostream & o, AForm const & src) {
	o << "AForm " << src.getName() << " is ";
	if (src.getSigned())
		o << "signed";
	else
		o << "not signed";
	o << " and requires grade " << src.getGradeToSign() << " to be signed and grade " << src.getGradeToExecute() << " to be executed." << std::endl;
	return o;
}