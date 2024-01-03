/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:53:54 by paescano          #+#    #+#             */
/*   Updated: 2024/01/03 15:18:44 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <sstream>
# include <stack>
# include <string>

class RPN
{
	private:
		std::stack<double>	_stack;
		std::string			_input;
		double				_result;
	public:
		RPN();
		RPN(const RPN &src);
		~RPN();

		RPN &	operator=(const RPN &src);

		void	setInput(std::string input);
		void	calculate();
		void	getResult();
};

#endif