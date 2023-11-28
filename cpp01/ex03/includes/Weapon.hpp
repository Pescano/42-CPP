/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:10:42 by paescano          #+#    #+#             */
/*   Updated: 2023/11/28 13:30:52 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
private:
	std::string	_type;
public:
	Weapon( void );
	Weapon( std::string type );
	~Weapon( void );
	const std::string&	getType( void ) const;
	void	setType( std::string type );
};
#endif
	