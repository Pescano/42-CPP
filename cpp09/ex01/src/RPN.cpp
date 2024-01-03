/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 17:53:31 by paescano          #+#    #+#             */
/*   Updated: 2024/01/03 15:17:10 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {
	this->_result = 0;
	this->_input = "";
	this->_stack = std::stack<double>();
}

RPN::RPN(const RPN &src)
{
	*this = src;
}

RPN::~RPN() {
}

RPN &	RPN::operator=(const RPN &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void	RPN::setInput(std::string input)
{
	this->_input = input;
}

void	RPN::calculate()
{
	double	a, b;
	std::istringstream iss(this->_input);
	std::string token;
	while (iss >> token)
	{
		try
		{
			if (token == "(" || token == ")" || token.size() > 1)
				throw std::runtime_error("Invalid expression");
			else if (token == "+" || token == "-" || token == "*"
					|| token == "/")
			{
				if (this->_stack.size() < 2)
					throw std::runtime_error("Invalid expression");
				b = this->_stack.top();
				this->_stack.pop();
				a = this->_stack.top();
				this->_stack.pop();
				if (token == "+")
					this->_stack.push(a + b);
				else if (token == "-")
					this->_stack.push(a - b);
				else if (token == "*")
					this->_stack.push(a * b);
				else if (token == "/")
					this->_stack.push(a / b);
			}
			else if (isdigit(token[0]))
				this->_stack.push(atof(token.c_str()));
			else
				throw std::runtime_error("Invalid expression");
		}
		catch (const std::exception &e)
		{
			std::cerr << "Error: " << e.what() << std::endl;
			exit(1);
		}
	}
	this->_result = this->_stack.top();
}

void	RPN::getResult()
{
	std::cout << this->_result << std::endl;
}