/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:32:25 by paescano          #+#    #+#             */
/*   Updated: 2023/12/14 18:13:52 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name)
{
	try
	{
		if (grade < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		else if (grade > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else
		{
			this->_grade = grade;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		this->_grade = 150;
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
{
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src)
{
	if (this != &src)
	{
		this->_grade = src.getGrade();
	}
	return *this;
}

std::string const &Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	try
	{
		if (this->_grade - 1 < 1)
		{
			throw Bureaucrat::GradeTooHighException();
		}
		else
		{
			this->_grade--;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::decrementGrade()
{
	try
	{
		if (this->_grade + 1 > 150)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else
		{
			this->_grade++;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::signForm(AForm &src) const
{
	if (src.getGradeToSign() < this->_grade)
	{
		std::cout << this->_name << " couldn't sign " << src.getName() << " because grade too low" << std::endl;
	}
	else if (src.getSigned())
	{
		std::cout << this->_name << " couldn't sign " << src.getName() << " because it's already signed" << std::endl;
	}
	else
	{
		src.beSigned(*this);
		std::cout << this->_name << " signed " << src.getName() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const &src) const
{
	try
	{
		if (!src.getSigned())
		{
			throw AForm::FormNotSignedException();
		}
		else if (src.getGradeToExecute() < this->_grade)
		{
			throw Bureaucrat::GradeTooLowException();
		}
		else
		{
			src.execute(*this);
			std::cout << this->_name << " executed " << src.getName() << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		std::cerr << this->_name << " couldn't execute " << src.getName() << std::endl;
	}
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

std::ostream &operator<<(std::ostream &o, Bureaucrat const &src)
{
	o << src.getName() << ", bureaucrat grade " << src.getGrade() << std::endl;
	return o;
}
