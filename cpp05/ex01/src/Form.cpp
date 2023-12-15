/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:50:50 by paescano          #+#    #+#             */
/*   Updated: 2023/12/15 12:08:57 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _signed(false), _gradeToSign(150), _gradeToExecute(150) {
}

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
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

Form::Form(Form const & src) : _name(src.getName()), _signed(src.getSigned()), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute()) {
}

Form::~Form() {
}

Form &	Form::operator=(Form const & src) {
	if (this != &src)
		_signed = src._signed;
	return *this;
}

std::string	Form::getName() const {
	return _name;
}

bool		Form::getSigned() const {
	return _signed;
}

int			Form::getGradeToSign() const {
	return _gradeToSign;
}

int			Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void		Form::beSigned(Bureaucrat const & src) {
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

const char* Form::GradeTooHighException::what() const throw() {
	return "<GradeTooHighException>: Grade too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "<GradeTooLowException>: Grade too low";
}

std::ostream &	operator<<(std::ostream & o, Form const & src) {
	o << "Form " << src.getName() << " is ";
	if (src.getSigned())
		o << "signed";
	else
		o << "not signed";
	o << " and requires grade " << src.getGradeToSign() << " to be signed and grade " << src.getGradeToExecute() << " to be executed." << std::endl;
	return o;
}