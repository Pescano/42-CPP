/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:09:06 by paescano          #+#    #+#             */
/*   Updated: 2023/12/12 13:13:58 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <iostream>
# include <string>
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_inventory[4];
		int			_count;
	public:
		MateriaSource();
		MateriaSource(MateriaSource const & src);
		virtual ~MateriaSource();

		MateriaSource &		operator=(MateriaSource const & src);

		void				learnMateria(AMateria *m);
		AMateria *			createMateria(std::string const & type);
};

#endif
