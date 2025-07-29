/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:00:56 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 13:06:56 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

const int	FragTrap::defHealth = 100;
const int	FragTrap::defEnergy = 100;
const int	FragTrap::defAtkDmg = 30;

FragTrap::FragTrap(void) :
	ClapTrap("Default", defHealth, defEnergy, defAtkDmg) {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string pName) :
	ClapTrap(pName, defHealth, defEnergy, defAtkDmg) {
	std::cout << "FragTrap " << _name << " parameterized constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const& pCopy) :
	ClapTrap(pCopy._name, pCopy._health, pCopy._energy, pCopy._atkDmg) {
	std::cout << "FragTrap " << _name << " parameterized constructor called" << std::endl;
}

FragTrap::~FragTrap(void) {
	std::cout << "FragTrap " << _name << " destructor called" << std::endl;
}

void	FragTrap::highFiveGuys(void) {
	if (_health <= 0)
	{
		std::cout << "FragTrap " << _name << " is out of service!" << std::endl;
		return ;
	}	
	std::cout << "FragTrap " << _name << " wants to high five! It would be very mean of you to attack him now." << std::endl;
}

void	FragTrap::attack(std::string const& target)
{
	if (_health <= 0) {
		std::cout << "FragTrap " << _name << " is out of service!" << std::endl;
		return ;
	}	
	else if (_energy <= 0) {
		std::cout << "FragTrap " << _name << " is too tired to do something!" << std::endl;
		return ;
	}
	_energy--;
	std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _atkDmg << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	_health -= amount;
	if (_health > 0)
		std::cout << "FragTrap " << _name << " has taken " << amount << " damage!" << std::endl;
	else
		std::cout << "FragTrap " << _name << " is now KO" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &pCopy)
{
	std::cout << "FragTrap " << _name << " copy assignment operator called" << std::endl;
	if (this != &pCopy)
	{
		this->_name = pCopy._name;
		this->_health = pCopy._health;
		this->_energy = pCopy._energy;
		this->_atkDmg = pCopy._atkDmg;
	}
	return (*this);
}