/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:55:26 by achu              #+#    #+#             */
/*   Updated: 2025/07/30 19:00:09 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

Character::Character()
	: _name("Default") {
	for (size_t i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	std::cout << "Character: " << _name << " has been created" << std::endl;
}

Character::Character(std::string pName)
	: _name(pName) {
	for (size_t i = 0; i < 4; i++) {
		_inventory[i] = NULL;
	}
	std::cout << "Character: " << _name << " has been created" << std::endl;
}

Character::Character(Character const& pCopy)
	: _name(pCopy.getName()) {
	for (size_t i = 0; i < 4; i++) {
		if (pCopy._inventory[i] != NULL)
			_inventory[i] = pCopy._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	std::cout << "Character: " << _name << " has been copied" << std::endl;
}

Character::~Character() {
	for (size_t i = 0; i < 4; i++) {
		if (_inventory[i] != NULL)
			delete _inventory[i];
	}
	std::cout << "Character: " << _name << " is dead" << std::endl;
}

Character&	Character::operator=(Character const& pCopy)
{
	if (this != &pCopy)
	{
		_name = pCopy.getName();
		for (size_t i = 0; i < 4; i++) {
			if (_inventory[i] != NULL)
				_inventory[i] = pCopy._inventory[i]->clone();
			else
				_inventory[i] = NULL;
		}
	}
	std::cout << "Character: " << _name << " has been deep copied" << std::endl;
	return (*this);
}

std::string const&	Character::getName() const { return (_name); }

void	Character::equip(AMateria* pM)
{
	for (size_t i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = pM;
			std::cout << _name << " has equiped the " << pM->getType() << std::endl;
			return ;
		}
	}
	std::cout << _name << " inventory is full " << std::endl;
	delete pM;
}

void	Character::unequip(int pIdx)
{
	if (0 <= pIdx && pIdx <= 3) {
		std::cout << _name << " has unequiped the " << _inventory[pIdx]->getType() << std::endl;
		delete _inventory[pIdx];
		_inventory[pIdx] = NULL;
		return ;
	}
}

void	Character::use(int pIdx, ICharacter& pTarget)
{
	if (0 <= pIdx && pIdx <= 3) {
		_inventory[pIdx]->use(pTarget);
	}
}