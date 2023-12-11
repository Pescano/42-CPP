/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:03:48 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 17:34:46 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class	Animal {
	protected:
		std::string	_type;
	public:
		Animal(void);
		Animal(Animal const & src);
		virtual ~Animal(void);

		Animal &		operator=(Animal const & src);
		
		void			setType(std::string type);
		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif
