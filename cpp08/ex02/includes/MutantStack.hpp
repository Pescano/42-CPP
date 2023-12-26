/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:48:09 by paescano          #+#    #+#             */
/*   Updated: 2023/12/26 17:34:17 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		MutantStack<T>() : std::stack<T>() {}
		MutantStack<T>(MutantStack<T> const & src): std::stack<T>(src) {}
		~MutantStack<T>() {}

		MutantStack<T> &	operator=(MutantStack<T> const & src) {
			if (this != &src)
				std::stack<T>::operator=(src);
			return *this;
		}

		iterator	begin() {
			return std::stack<T>::c.begin();
		}

		iterator	end() {
			return std::stack<T>::c.end();
		}
};

#endif
