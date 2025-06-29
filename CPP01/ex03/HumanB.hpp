/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 02:32:06 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 03:27:32 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __HUMAN_B_H__
#  define __HUMAN_B_H__

#include <string>
#include "Weapon.hpp"

class HumanB
{
	private:

		std::string		_name;
		Weapon*			_weapon;

	public:

		HumanB(std::string pName);
		~HumanB(void);

		void	attack();
		void	setWeapon(Weapon pWeapon);
};

#endif