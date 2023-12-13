/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:39:30 by paescano          #+#    #+#             */
/*   Updated: 2023/12/13 15:34:52 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150) {
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name) {
	if (grade < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else if (grade > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->_grade = grade;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade()) {
}

Bureaucrat::~Bureaucrat() {
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src) {
	if (this != &src) {
		this->_grade = src.getGrade();
	}
	return *this;
}

std::string const	&Bureaucrat::getName() const {
	return this->_name;
}

int					Bureaucrat::getGrade() const {
	return this->_grade;
}

void				Bureaucrat::incrementGrade() {
	if (this->_grade - 1 < 1) {
		throw Bureaucrat::GradeTooHighException();
	} else {
		this->_grade--;
	}
}

void				Bureaucrat::decrementGrade() {
	if (this->_grade + 1 > 150) {
		throw Bureaucrat::GradeTooLowException();
	} else {
		this->_grade++;
	}
}

const char			*Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high";
}

const char			*Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src) {
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}
