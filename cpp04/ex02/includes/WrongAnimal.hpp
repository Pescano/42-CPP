/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:04:48 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 13:28:53 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_H
# define WRONG_ANIMAL_H

# include <iostream>
# include <string>

class WrongAnimal
{
	protected:
		std::string _type;
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const & src);
		~WrongAnimal(void);

		WrongAnimal &	operator=(WrongAnimal const & src);

		void			setType(std::string type);
		std::string		getType(void) const;
		void			makeSound(void) const;
};

#endif
