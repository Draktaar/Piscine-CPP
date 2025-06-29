/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 02:32:06 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 03:24:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

HumanA::HumanA(std::string pName, Weapon& pWeapon) : _name(pName), _weapon(pWeapon) {}
HumanA::~HumanA(void) {}

void	HumanA::attack()
{
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}