/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:42:58 by paescano          #+#    #+#             */
/*   Updated: 2024/01/02 15:29:55 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <string>
# include <map>
# include <ctime>
# include <cctype>

class BitcoinExchange
{
	private:
		std::map<std::string, float> _map;
		
		std::map<std::string, float>	parseBD();
		void							exitError(std::string error);
		void							checkDataFile(std::string line);
		void							printData(std::string date, float value);
		bool							checkDate(std::string date);
		bool							checkDelim(std::string line);
		bool							checkYear(std::string year);
		bool							checkMonth(std::string month);
		bool							checkDay(std::string day, std::string month, std::string year);
		bool							checkValue(std::string value);
		std::string						decreaseDate(std::string date);
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();

		BitcoinExchange &	operator=(const BitcoinExchange &src);

		void 				converter(std::string input_file);
		void 				printMap();
};

#endif
