/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 17:24:02 by paescano          #+#    #+#             */
/*   Updated: 2023/12/19 12:49:03 by paescano         ###   ########.fr       */
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
	bool isFloat = true;
	bool isDouble = true;
	bool isInt = true;

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

	try
	{
		_int = std::stoi(input);
	}
	catch(const std::exception& e)
	{
		isInt = false;
	}
	
	if (isInt)
	{
		if (std::isprint(_int))
		{
			_char = "'";
			_char += static_cast<char>(_int);
			_char += "'";
		}
		else
			_char = "Non displayable";
	}
	else
		_char = "imposible";

	std::cout << "char:   " << _char << std::endl;
	if (isInt)
		std::cout << "int:    " << _int << std::endl;
	else
		std::cout << "int:    imposible" << std::endl;

	if (input[input.length() - 1] == 'f') 
	{
		try
		{
			_float = std::stof(input.c_str());
			_double = static_cast<double>(_float);
		}
		catch(const std::exception& e)
		{
			isFloat = false;
		}
	} else 
	{
		try
		{
			_double = std::stod(input.c_str(), NULL);
			_float = static_cast<float>(_double);
		}
		catch(const std::exception& e)
		{
			isDouble = false;
		}
	}

	if (!isFloat || !isDouble) 
	{
		std::cout << "float:  imposible" << std::endl;
		std::cout << "double: imposible" << std::endl;
		return;
	}

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
