/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:03:58 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 16:08:52 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal {
	private:
		Brain *_brain;
	public:
		Cat(void);
		Cat(Cat const & src);
		~Cat(void);

		Cat &	operator=(Cat const & src);
		
		void	makeSound(void) const;
};

#endif