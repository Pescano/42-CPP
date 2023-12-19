/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:53:24 by paescano          #+#    #+#             */
/*   Updated: 2023/12/18 17:01:26 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(Serializer const & src);
		~Serializer();

		Serializer &		operator=(Serializer const & src);
	public:
		static uintptr_t    serialize(Data *ptr);
		static Data *       deserialize(uintptr_t raw);
};

#endif
