/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:43:34 by paescano          #+#    #+#             */
/*   Updated: 2024/01/03 15:20:07 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	this->_map = parseBD();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
		*this = src;
	return (*this);
}

void	BitcoinExchange::printMap()
{
	for (std::map<std::string, float>::iterator it = _map.begin(); it != _map.end(); ++it)
		std::cout << "Date: " << it->first << ", Value: " << std::fixed << std::setprecision(2) << it->second << std::endl;
}

void	BitcoinExchange::exitError(std::string error)
{
	std::cerr << "Error: " << error << std::endl;
	exit(1);
}

std::string BitcoinExchange::decreaseDate(std::string date)
{
	std::stringstream ss(date), conc;
	std::string year, month, day;
	getline(ss, year, '-');
	getline(ss, month, '-');
	getline(ss, day);
	int y = atoi(year.c_str()), m = atoi(month.c_str()), d = atoi(day.c_str());
	if (d > 1)
		d--;
	else {
		m--;
		if (m == 2 && (y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
			d = 29;
		else if (m == 2)
			d = 28;
		else if (m == 0) {
			d = 31;
			m = 12;
			y--;
		} else {
			if (m == 4 || m == 6 || m == 9 || m == 11)
				d = 30;
			else
				d = 31;
		}
	}
	conc << y << '-' << std::setw(2) << std::setfill('0') << m << '-' << std::setw(2) << std::setfill('0') << d;
	return conc.str();
}

void BitcoinExchange::printData(std::string date, float value)
{
	if (_map.find(date) != _map.end())
		std::cout << date << " => " << std::fixed << std::setprecision(2) << value << " = " << value * _map[date]<< std::endl;
	else if (date == "2009-01-01")
		std::cout << "Error: No data available for this date." << std::endl;
	else
		printData(decreaseDate(date), value);
}

bool	BitcoinExchange::checkDelim(std::string line)
{
	if (line.find(" | ") != 10)
	{
		std::cerr << "Error: Wrong delimiter format." << std::endl;
		return (false);
	}
	return (true);
}

bool	BitcoinExchange::checkYear(std::string year)
{
	int	y = atoi(year.c_str());
	if (y < 2009)
		return (false);
	return (true);
}

bool	BitcoinExchange::checkMonth(std::string month)
{
	int	m = atoi(month.c_str());
	if (m > 12 || m < 1)
		return (false);
	return (true);
}

bool	BitcoinExchange::checkDay(std::string day, std::string month, std::string year)
{
	int d = atoi(day.c_str());
	if (d > 31 || d < 1)
		return (false);
	if (month == "02" && d > 29)
	{
		int y = atoi(year.c_str());
		if (!(y % 4 == 0 && (y % 100 != 0 || y % 400 == 0)))
			return (false);
	}
	if ((month == "04" || month == "06" || month == "09" || month == "11") && d > 30)
		return (false);
	return (true);
}

bool BitcoinExchange::checkValue(std::string value)
{
	if (value.find("-") == 0)
	{
		std::cout << "Error: Not a positive number." << std::endl;
		return (false);
	}
	int i = 0;
	bool decimal = false;
	while (value[i])
	{
		if (!isdigit(value[i]) && value[i] != '.')
		{
			std::cout << "Error: Not a valid number." << std::endl;
			return false;
		}
		if (value[i] == '.')
		{
			if (decimal)
			{
				std::cout << "Error: Only one decimal point allowed." << std::endl;
				return false;
			}
			decimal = true;
		}
		i++;
	}
	float	val = atof(value.c_str());
	if (value.size() > 4 || val > 1000)
	{
		std::cout << "Error: Too large a number." << std::endl;
		return (false);
	}
	return (true);
}


bool BitcoinExchange::checkDate(std::string date)
{
	try
	{
		std::stringstream ss(date);
		std::string year, month, day;

		getline(ss, year, '-');
		if (year.size() != 4 || !isdigit(year[0]) || !isdigit(year[1]) || !isdigit(year[2]) || !isdigit(year[3]))
			throw std::invalid_argument(" Invalid year format");
		getline(ss, month, '-');
		if (month.size() != 2 || !isdigit(month[0]) || !isdigit(month[1]))
			throw std::invalid_argument(" Invalid month format");
		getline(ss, day);
		if (day.size() != 2 || !isdigit(day[0]) || !isdigit(day[1]))
			throw std::invalid_argument(" Invalid day format");
		if (!checkYear(year))
			throw std::invalid_argument(" Invalid year value");
		if (!checkMonth(month))
			throw std::invalid_argument(" Invalid month value");
		if (!checkDay(day, month, year))
			throw std::invalid_argument(" Invalid day value");
		return true;
	}
	catch (const std::invalid_argument& e)
	{
		std::cerr << "Error: Bad input:" << e.what() << " => " << date << std::endl;
		return false;
	}
}

void	BitcoinExchange::checkDataFile(std::string line)
{
	std::stringstream ss(line);
	std::string date, delim, value;
	ss >> date >> delim >> value;
	if (!checkDate(date))
		return ;
	if (!checkDelim(line))
		return ;
	if (!checkValue(value))
		return ;
	printData(date, atof(value.c_str()));
}

void	BitcoinExchange::converter(std::string inputFile)
{
	std::ifstream	ifs(inputFile.c_str());
	std::string		line;
	if (!ifs.is_open())
		exitError("Could not open input file.");
	getline(ifs, line);
	if (line.compare("date | value") != 0)
		exitError("Wrong input file format.");
	while (getline(ifs, line))
		checkDataFile(line);
	ifs.close();
	return ;
}

std::map<std::string, float> BitcoinExchange::parseBD()
{
	std::ifstream ifs("data.csv");
	std::map<std::string, float> map;
	std::string line;
	if (!ifs.is_open())
		exitError("Could not open database file.");
	while (std::getline(ifs, line)) {
		if (!line.compare("date,exchange_rate"))
			continue;
		std::istringstream lineStream(line);
		std::string date, value;
		std::getline(lineStream, date, ',');
		std::getline(lineStream, value);
		try {
			map[date] = atof(value.c_str());
		} catch (const std::exception &e) {
			ifs.close();
			exitError("Could not parse database file.");
		}
	}
	ifs.close();
	return (map);
}