/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:41:38 by paescano          #+#    #+#             */
/*   Updated: 2023/11/24 17:02:25 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	this->_index = 0;
	this->_superIndex = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact() {
	if (this->_index < 8) {
		if (PhoneBook::_saveContact(this->_index))
			this->_index++;
	}
	else {
		if (this->_superIndex < 8)
		{
			if (PhoneBook::_saveContact(this->_superIndex))
				this->_superIndex++;
		}
		else if (this->_superIndex == 8)
		{
			if (PhoneBook::_saveContact(0))
				this->_superIndex = 1;
		}
	}
}

void PhoneBook::_printContact(int index){
	std::cout << "First Name: " << this->_contacts[index].getFirstName() << std::endl;
	std::cout << "Last Name: " << this->_contacts[index].getLastName() << std::endl;
	std::cout << "Nickname: " << this->_contacts[index].getNickname() << std::endl;
	std::cout << "Phone Number: " << this->_contacts[index].getPhoneNumber() << std::endl;
	std::cout << "Darkest Secret: " << this->_contacts[index].getDarkestSecret() << std::endl;
}

void PhoneBook::searchContact() {
	int index;
	std::string input;

	if (this->_index == 0) {
		std::cout << "Phonebook is empty!" << std::endl;
		return;
	}
	std::cout << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First Name" << "|";
	std::cout << std::setw(10) << "Last Name" << "|";
	std::cout << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < this->_index; i++) {
		std::cout << std::setw(10) << i << "|";
		_printField(this->_contacts[i].getFirstName());
		std::cout << "|";
		_printField(this->_contacts[i].getLastName());
		std::cout << "|";
		_printField(this->_contacts[i].getNickname());
		std::cout << std::endl;
	}
	while (input.empty())
	{
		std::cout << "Insert contact input: ";
		std::getline(std::cin, input);
		if (std::cin.fail())
			return ;
	}
	if (!_isNumber(input))
	{
		std::cout << "Index must be a number." << std::endl;
		return ;
	}
	index = _strToInt(input);
	if (index >= 0 && index < this->_index)
		_printContact(index);
	else
		std::cout << "Wrong index selected." << std::endl;
}

bool PhoneBook::_saveContact(int index) {
	std::string input;
	std::cout << "First Name: ";
	std::getline(std::cin, input);
	if (std::cin.fail())
		return false;
	this->_contacts[index].setFirstName(input);
	std::cout << "Last Name: ";
		std::getline(std::cin, input);
	if (std::cin.fail())
		return false;
	this->_contacts[index].setLastName(input);
	std::cout << "Nickname: ";
		std::getline(std::cin, input);
	if (std::cin.fail())
		return false;
	this->_contacts[index].setNickname(input);
	while (input.length() != 9 || _isNumber(input) == false)
	{
		std::cout << "Phone Number: ";
		std::getline(std::cin, input);
		if (std::cin.fail())
			return false;
	}
	this->_contacts[index].setPhoneNumber(input);
	std::cout <<  "Darkest Secret: ";
		std::getline(std::cin, input);
	if (std::cin.fail())
		return false;
	this->_contacts[index].setDarkestSecret(input);
	return true;
}

bool PhoneBook::_isNumber(std::string str) {
	if (str.empty())
		return false;
	for (std::string::const_iterator it = str.begin(); it != str.end(); it++)
	{
		if (!std::isdigit(*it))
			return false;
	}
	return true;
}

int	PhoneBook::_strToInt(std::string str)
{
	int	num;

	num = 0;
	for (int i = 0; str[i]; i++)
	{
		num *= 10;
		num += str[i] - '0';
	}
	return num;
}

void PhoneBook::_printField(std::string str) {
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << str;
}