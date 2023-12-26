/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:05:31 by paescano          #+#    #+#             */
/*   Updated: 2023/12/26 17:34:28 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <iterator>

class Span {
	private:
		unsigned int		_n;
		std::vector<int>	_v;
		Span();
	public:
		Span(unsigned int n);
		Span(Span const & src);
		~Span();

		Span &		operator=(Span const & src);

		void		addNumber(int n);
		void		addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int			shortestSpan();
		int			longestSpan();

		class		FullException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class		NoFoundException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif
