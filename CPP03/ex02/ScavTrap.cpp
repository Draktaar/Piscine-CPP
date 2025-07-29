/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:19:43 by achu              #+#    #+#             */
/*   Updated: 2025/07/29 17:01:55 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(void)
	: ClapTrap("Default", 100, 50, 20), _isGuardGate(false) {
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string pName)
	: ClapTrap(pName, 100, 50, 20), _isGuardGate(false){
	std::cout << "ScavTrap " << _name << " parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const& pCopy)
	: ClapTrap(pCopy._name, pCopy._health, pCopy._energy, pCopy._atkDmg), _isGuardGate(pCopy._isGuardGate) {
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
		std::cout << "ScavTrap " << _name << " has no more juice to do anything else!" << std::endl;
		return ;
	}
	else if (_isGuardGate) {
		std::cout << "ScavTrap " << _name << " is in guard mod, therefore he cannot attack!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _atkDmg << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	if (_isGuardGate) {
		_energy-=50;
		std::cout << "ScavTrap " << _name << " has blocked the incoming damage!" << std::endl;
		if (_energy <= 0) {
			_isGuardGate = false;
			std::cout << "ScavTrap " << _name << "'s guard gate has been shattered ! He's now exposed !" << std::endl;
		}
		return ;
	}
	_health -= amount;
	if (_health > 0)
		std::cout << "ScavTrap " << _name << " has taken " << amount << " damage!" << std::endl;
	else
		std::cout << "ScavTrap " << _name << " is now KO" << std::endl;
}

void	ScavTrap::guardGate(void)
{
	if (_health <= 0) {
		std::cout << "ScavTrap " << _name << " is out of service!" << std::endl;
		return ;
	}
	else if (_energy <= 0) {
		std::cout << "ScavTrap " << _name << " tried to guard gate but it failed!" << std::endl;
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