/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:07:20 by paescano          #+#    #+#             */
/*   Updated: 2023/12/12 13:13:20 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class Character : public ICharacter
{
	private:
		std::string	_name;
		AMateria	*_inventory[4];
		int			_count;
	public:
		Character();
		Character(std::string const & name);
		Character(Character const & src);
		virtual ~Character();

		Character &			operator=(Character const & src);

		std::string const &	getName() const;
		void				equip(AMateria * m);
		void				unequip(int idx);
		void				use(int idx, ICharacter & target);
};

#endif
