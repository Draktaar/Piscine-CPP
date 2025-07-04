/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:55:26 by achu              #+#    #+#             */
/*   Updated: 2025/07/04 14:54:56 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
	: _name("Default") {
	for (size_t i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(std::string pName)
	: _name(pName) {
	for (size_t i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
}

Character::Character(Character const& pCopy)
	: _name(pCopy.getName()) {
	for (size_t i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	for (size_t i = 0; i < 4; i++) {
		_inventory[i] = pCopy._inventory[i]->clone();
	}
}

Character::~Character() {
	for (size_t i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
}

Character&	Character::operator=(Character const& pCopy)
{
	if (this != &pCopy)
	{
		_name = pCopy.getName();
		for (size_t i = 0; i < 4; i++) {
			if (_inventory[i] != NULL)
				delete _inventory[i];
		}
		for (size_t i = 0; i < 4; i++) {
			_inventory[i] = pCopy._inventory[i]->clone();
		}
	}
	return (*this);
}

std::string const&	Character::getName() const { return (_name); }

void	Character::equip(AMateria* pM)
{
	for (size_t i = 0; i < 4; i++) {
		if (_inventory[i] == NULL)
		{
			_inventory[i] = pM;
			break;
		}
	}
}

void	Character::unequip(int pIdx)
{
	if (0 <= pIdx && pIdx <= 3) {
		_inventory[pIdx] = NULL;
	}
}

void	Character::use(int pIdx, ICharacter& pTarget)
{
	if (0 <= pIdx && pIdx <= 3) {
		_inventory[pIdx]->use(pTarget);
	}
}