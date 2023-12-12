/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:49:23 by paescano          #+#    #+#             */
/*   Updated: 2023/12/12 13:01:13 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include <string>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(std::string const & type);
		AMateria(AMateria const & src);
		virtual ~AMateria();

		AMateria &			operator=(AMateria const & src);

		std::string const &	getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter & target) = 0;
};

#endif
