/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:24:02 by paescano          #+#    #+#             */
/*   Updated: 2023/12/18 13:07:37 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
}

ScalarConverter::ScalarConverter(ScalarConverter const & src) {
	*this = src;
}

ScalarConverter::~ScalarConverter() {
}

ScalarConverter & ScalarConverter::operator=(ScalarConverter const & src) {
	(void)src;
	return *this;
}

void ScalarConverter::convert(const std::string& input) 
{
	std::string _char = "";
	int _int = 0;
	float _float = 0;
	double _double = 0;

	if (input == "inf" || input == "inff" || \
        input == "+inf" || input == "+inff")
    {
        std::cout << "char:   imposible" << std::endl;
        std::cout << "int:    imposible" << std::endl;
        std::cout << "float:  inff" << std::endl;
        std::cout << "double: inf" << std::endl;
        return;
    }
    else if (input == "-inf" || input == "-inff")
    {
        std::cout << "char:   imposible" << std::endl;
        std::cout << "int:    imposible" << std::endl;
        std::cout << "float:  -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
        return;
    }
    else if (input == "nan" || input == "nanf")
    {
        std::cout << "char:   imposible" << std::endl;
        std::cout << "int:    imposible" << std::endl;
        std::cout << "float:  nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
	else if (input.size() == 1 && std::isprint(input[0]) && !std::isdigit(input[0])) 
	{
		_char = input[0];
		std::cout << "char:   " << _char << std::endl;
		std::cout << "int:    " << static_cast<int>(_char[0]) << std::endl;
		std::cout << "float:  " << static_cast<float>(_char[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(_char[0]) << ".0" << std::endl;
		return;
	}

	_int = std::atoi(input.c_str());
	
	if (_char == "" && std::isprint(_int)) 
	{
		_char = "'";
		_char += static_cast<char>(_int);
		_char += "'";
	} 
	else if (_char == "") 
	{
		_char = "Non displayable";
	}

	if (input[input.length() - 1] == 'f') 
	{
		_float = std::atof(input.c_str());
		_double = static_cast<double>(_float);
	} else 
	{
		_double = std::atof(input.c_str());
		_float = static_cast<float>(_double);
	}

	std::cout << "char:   " << _char << std::endl;	
	std::cout << "int:    " << _int << std::endl;
	if (_float - static_cast<int>(_float) == 0) 
	{
		std::cout << "float:  " << _float << ".0f" << std::endl;
		std::cout << "double: " << _double << ".0" << std::endl;
	} 
	else 
	{
		std::cout << "float:  " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
	}
}
