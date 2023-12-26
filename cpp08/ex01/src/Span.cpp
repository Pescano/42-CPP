/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:05:46 by paescano          #+#    #+#             */
/*   Updated: 2023/12/26 17:38:23 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(): _n(0) {
}

Span::Span(unsigned int n): _n(n) {
}

Span::Span(Span const & src) {
	*this = src;
}

Span::~Span() {
}

Span &		Span::operator=(Span const & src) {
	if (this != &src) {
		this->_n = src._n;
		this->_v = src._v;
	}
	return *this;
}

void		Span::addNumber(int n) {
	if (this->_v.size() < this->_n)
		this->_v.push_back(n);
	else
		throw Span::FullException();
}

void		Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (this->_v.size() + std::distance(begin, end) <= this->_n)
		this->_v.insert(this->_v.end(), begin, end);
	else
		throw Span::FullException();
}

int			Span::shortestSpan() {
	if (this->_v.size() < 2)
		throw Span::NoFoundException();
	std::sort(this->_v.begin(), this->_v.end());
	int		min = this->_v[1] - this->_v[0];
	for (unsigned int i = 2; i < this->_v.size(); i++) {
		if (this->_v[i] - this->_v[i - 1] < min)
			min = this->_v[i] - this->_v[i - 1];
	}
	return min;
}

int			Span::longestSpan() {
	if (this->_v.size() < 2)
		throw Span::NoFoundException();
	std::sort(this->_v.begin(), this->_v.end());
	return this->_v[this->_v.size() - 1] - this->_v[0];
}

const char*	Span::FullException::what() const throw() {
	return "<FullException> Span is full";
}

const char*	Span::NoFoundException::what() const throw() {
	return "<NoFoundException> Span has no numbers or only one";
}
