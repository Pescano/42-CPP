/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:53:05 by paescano          #+#    #+#             */
/*   Updated: 2023/12/18 16:58:32 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(Serializer const & src) {
	*this = src;
}

Serializer::~Serializer() {
}

Serializer &		Serializer::operator=(Serializer const & src) {
	(void)src;
	return (*this);
}

uintptr_t			Serializer::serialize(Data *ptr) {
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data *				Serializer::deserialize(uintptr_t raw) {
	return (reinterpret_cast<Data *>(raw));
}