/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:14:40 by paescano          #+#    #+#             */
/*   Updated: 2023/11/23 18:08:12 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
}

Contact::~Contact() {
}

void Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

void Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

void Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() {
	return this->_firstName;
}

std::string Contact::getLastName() {
	return this->_lastName;
}

std::string Contact::getNickname() {
	return this->_nickname;
}

std::string Contact::getPhoneNumber() {
	return this->_phoneNumber;
}

std::string Contact::getDarkestSecret() {
	return this->_darkestSecret;
}