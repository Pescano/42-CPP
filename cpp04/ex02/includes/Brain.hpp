/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:26:13 by paescano          #+#    #+#             */
/*   Updated: 2023/12/11 16:11:58 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_H
# define BRAIN_H

#include <iostream>
#include <string>

class Brain
{
	private:
		std::string _ideas[100];
	public:
		Brain(void);
		Brain(Brain const & src);
		~Brain(void);

		Brain &		operator=(Brain const & src);
		std::string	getIdea(int index) const;
		void 		setIdea(int index, std::string idea);
};

#endif
