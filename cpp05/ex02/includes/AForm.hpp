/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:29:51 by paescano          #+#    #+#             */
/*   Updated: 2023/12/14 17:03:04 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	private:
		std::string const	_name;
		bool				_signed;
		const int			_gradeToSign;
		const int			_gradeToExecute;
	public:
		AForm();
		AForm(std::string name, int gradeToSign, int gradeToExecute);
		AForm(AForm const & src);
		~AForm();

		AForm &		operator=(AForm const & src);

		std::string			getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				setSigned(bool value);

		void				beSigned(Bureaucrat const & src);
		void				execute(Bureaucrat const & src) const;
		virtual void		executeAction() const = 0;

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormNotSignedException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &	operator<<(std::ostream & o, AForm const & src);

#endif