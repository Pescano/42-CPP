/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:08:19 by paescano          #+#    #+#             */
/*   Updated: 2023/12/12 15:13:30 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class AMateria;

class ICharacter
{
	public:
		virtual						~ICharacter() {}
		virtual std::string const &	getName() const = 0;
		virtual void				equip(AMateria * m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter & target) = 0;
};

#endif
