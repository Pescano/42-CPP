/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 17:42:25 by paescano          #+#    #+#             */
/*   Updated: 2023/11/24 13:05:24 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H
# include "Contact.hpp"
# include <iostream>
# include <string>
# include <iomanip>

class PhoneBook {
	public:
		PhoneBook();
		~PhoneBook();

		void addContact();
		void searchContact();

	private:
		Contact _contacts[8];
		int _index;
		int _superIndex;
		void _printContact(int index);
		bool _saveContact(int index);
		bool _isNumber(std::string str);
		int _strToInt(std::string str);
};

#endif