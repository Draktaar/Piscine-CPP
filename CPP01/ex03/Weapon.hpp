/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 02:31:24 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 03:18:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __WEAPON_H__
#  define __WEAPON_H__

#include <string>

class Weapon
{
	private:

		std::string	_type;

	public:

		Weapon(void);
		Weapon(std::string pType);
		~Weapon(void);
	
		std::string		getType(void) const;
		void			setType(std::string pNewName);
};

#endif