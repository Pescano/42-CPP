/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:50:31 by paescano          #+#    #+#             */
/*   Updated: 2023/12/04 13:37:03 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _fixedPointValue(0) {
}

Fixed::Fixed(const int n)
{
	this->_fixedPointValue = n << this->_fractionalBits;
}

Fixed::Fixed(const float n)
{
	this->_fixedPointValue = roundf(n * (1 << this->_fractionalBits));
}

Fixed::Fixed(Fixed const & src)
{
	*this = src;
}

Fixed::~Fixed(void) {
}

Fixed &	Fixed::operator=(Fixed const & fixed)
{
	if (this != &fixed)
		this->_fixedPointValue = fixed.getRawBits();
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Fixed const & fixed)
{
	o << fixed.toFloat();
	return (o);
}

int	 Fixed::getRawBits(void) const
{
	return (this->_fixedPointValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const
{
	return ((float)this->_fixedPointValue / (float)(1 << this->_fractionalBits));
}

int		Fixed::toInt(void) const
{
	return (this->_fixedPointValue >> this->_fractionalBits);
}

bool Fixed::operator>( Fixed const & fixed ) const
{
	return (this->_fixedPointValue > fixed.getRawBits());
}

bool Fixed::operator<( Fixed const & fixed ) const
{
	return (this->_fixedPointValue < fixed.getRawBits());
}

bool Fixed::operator>=( Fixed const & fixed ) const
{
	return (this->_fixedPointValue >= fixed.getRawBits());
}

bool Fixed::operator<=( Fixed const & fixed ) const
{
	return (this->_fixedPointValue <= fixed.getRawBits());
}

bool Fixed::operator==( Fixed const & fixed ) const
{
	return (this->_fixedPointValue == fixed.getRawBits());
}

bool Fixed::operator!=( Fixed const & fixed ) const
{
	return (this->_fixedPointValue != fixed.getRawBits());
}

Fixed Fixed::operator+( Fixed const & fixed ) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-( Fixed const & fixed ) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*( Fixed const & fixed ) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/( Fixed const & fixed ) const
{
	if (fixed.toFloat() == 0)
	{
		std::cout << "Division by 0" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator++( void )
{
	this->_fixedPointValue++;
	return (*this);
}

Fixed Fixed::operator++( int )
{
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed Fixed::operator--( void )
{
	this->_fixedPointValue--;
	return (*this);
}

Fixed Fixed::operator--( int )
{
	Fixed tmp(*this);
	operator--();
	return (tmp);
}


Fixed & Fixed::min( Fixed & f1, Fixed & f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

const Fixed & Fixed::min( Fixed const & f1, Fixed const & f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

Fixed &	Fixed::max( Fixed & f1, Fixed & f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

const Fixed & Fixed::max( Fixed const & f1, Fixed const & f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}
