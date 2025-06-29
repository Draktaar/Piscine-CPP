/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 02:32:06 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 03:24:19 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __HUMAN_A_H__
#  define __HUMAN_A_H__

#include <string>
#include "Weapon.hpp"

class HumanA
{
	private:

		std::string		_name;
		Weapon&			_weapon;

	public:

		HumanA(std::string pName, Weapon& pWeapon);
		~HumanA(void);

		void	attack();
};

#endif