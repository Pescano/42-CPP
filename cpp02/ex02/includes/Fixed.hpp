/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:50:45 by paescano          #+#    #+#             */
/*   Updated: 2023/12/04 11:53:38 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <ostream>
# include <cmath>

class Fixed
{
	private:
		int					_fixedPointValue;
		static const int	_fractionalBits = 8;
	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);
		Fixed(Fixed const & src);
		~Fixed(void);

		Fixed &	operator=(Fixed const & fixed);
		bool operator>( Fixed const & fixed ) const;
		bool operator<( Fixed const & fixed ) const;
		bool operator>=( Fixed const & fixed ) const;
		bool operator<=( Fixed const & fixed ) const;
		bool operator==( Fixed const & fixed ) const;
		bool operator!=( Fixed const & fixed ) const;
		Fixed operator+( Fixed const & fixed ) const;
		Fixed operator-( Fixed const & fixed ) const;
		Fixed operator*( Fixed const & fixed ) const;
		Fixed operator/( Fixed const & fixed ) const;
		Fixed operator++( void );
		Fixed operator++( int );
		Fixed operator--( void );
		Fixed operator--( int );

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed & min( Fixed & f1, Fixed & f2);
		static const Fixed & min( Fixed const & f1, Fixed const & f2);
		static Fixed & max( Fixed & f1, Fixed & f2);
		static const Fixed & max( Fixed const & f1, Fixed const & f2);
};

std::ostream &	operator<<(std::ostream & o, Fixed const & fixed);

#endif