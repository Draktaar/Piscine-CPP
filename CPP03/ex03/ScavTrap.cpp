/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:19:43 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 13:06:44 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

const int	ScavTrap::defHealth = 100;
const int	ScavTrap::defEnergy = 50;
const int	ScavTrap::defAtkDmg = 20;

ScavTrap::ScavTrap(void) :
	ClapTrap("Default", defHealth, defEnergy, defAtkDmg), _isGuardGate(false) {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string pName) :
	ClapTrap(pName, defHealth, defEnergy, defAtkDmg), _isGuardGate(false){
	std::cout << "ScavTrap " << _name << " parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& pCopy) :
	ClapTrap(pCopy._name, pCopy._health, pCopy._energy, pCopy._atkDmg), _isGuardGate(pCopy._isGuardGate) {
	std::cout << "ScavTrap " << _name << " copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap(void) {
	std::cout << "ScavTrap " << _name << " destructor called" << std::endl;
}

void	ScavTrap::attack(std::string const& target)
{
	if (_health <= 0) {
		std::cout << "ScavTrap " << _name << " is out of service!" << std::endl;
		return ;
	}	
	else if (_energy <= 0) {
		std::cout << "ScavTrap " << _name << " is too tired to do something!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _atkDmg << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_health <= 0) {
		std::cout << "ScavTrap " << _name << " is out of service!" << std::endl;
		return ;
	}
	if (!_isGuardGate)
		std::cout << "ScavTrap " << _name << " is in guard gate mod!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is out of guard gate mod!" << std::endl;
	_isGuardGate = !_isGuardGate;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const& pCopy)
{
	std::cout << "ScavTrap " << _name << " copy assignment operator called" << std::endl;
	if (this != &pCopy)
	{
		this->_name = pCopy._name;
		this->_health = pCopy._health;
		this->_energy = pCopy._energy;
		this->_atkDmg = pCopy._atkDmg;
		this->_isGuardGate = pCopy._isGuardGate;
	}
	return (*this);
}