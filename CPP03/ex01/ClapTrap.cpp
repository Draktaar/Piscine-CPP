/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:35 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 00:58:17 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _name("Default"), _health(100), _energy(50), _atkDmg(20) {
	std::cout << "ClapTrap " << _name << " default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string pName) : _name(pName), _health(100), _energy(50), _atkDmg(20) {
	std::cout << "ClapTrap " << _name << " parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& pCopy) : _name(pCopy._name), _health(pCopy._health), _energy(pCopy._energy), _atkDmg(pCopy._atkDmg) {
	std::cout << "ClapTrap " << _name << " copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "ClapTrap " << _name << " destructor called" << std::endl;
}

void	ClapTrap::attack(std::string const& target)
{
	if (_health <= 0)
	{
		std::cout << "Claptrap " << _name << " is KO!" << std::endl;
		return ;
	}	
	else if (_energy <= 0)
	{
		std::cout << "Claptrap " << _name << " is too tired to do something!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "Claptrap " << _name << " attacks " << target << ", causing " << _atkDmg << " points of damage!" << std::endl;
}
void	ClapTrap::takeDamage(unsigned int amount)
{
	_health -= amount;
	std::cout << "Claptrap " << _name << " has taken " << amount << " damage!" << std::endl;
}
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_health <= 0)
	{
		std::cout << "Claptrap " << _name << " is KO!" << std::endl;
		return ;
	}	
	else if (_energy <= 0)
	{
		std::cout << "Claptrap " << _name << " is too tired to do something!" << std::endl;
		return ;
	}
	_energy--;
	_health += amount;
	std::cout << "Claptrap " << _name << " has repaired " << amount << " health!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const& pCopy)
{
	std::cout << "ClapTrap " << _name << " copy assignment operator called" << std::endl;
	if (this != &pCopy)
	{
		this->_name = pCopy._name;
		this->_health = pCopy._health;
		this->_energy = pCopy._energy;
		this->_atkDmg = pCopy._atkDmg;
	}
	return (*this);
}
