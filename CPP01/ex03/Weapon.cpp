/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 02:31:47 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 03:18:45 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void) {}
Weapon::Weapon(std::string pType) : _type(pType) {}
Weapon::~Weapon(void) {}

std::string		Weapon::getType(void) const { return (_type); }
void			Weapon::setType(std::string pNewType) { _type = pNewType; }
