/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 02:12:47 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 13:28:31 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(void)
	: ClapTrap("Default_clap_name", FragTrap::defHealth, ScavTrap::defEnergy, FragTrap::defAtkDmg), ScavTrap(), FragTrap(), _name("Default") {
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string pName)
	: ClapTrap(pName + "_clap_name", FragTrap::defHealth, ScavTrap::defEnergy, FragTrap::defAtkDmg), ScavTrap(), FragTrap(), _name(pName) {
	std::cout << "DiamondTrap " << _name << " parameterized constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& pCopy)
	: ClapTrap(pCopy._name, pCopy._health, pCopy._energy, pCopy._atkDmg), ScavTrap(), FragTrap(), _name(pCopy._name) {
	std::cout << "DiamondTrap " << _name << " copy constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << "DiamondTrap " << _name << " destructor called" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(DiamondTrap const& pCopy)
{
	std::cout << "DiamondTrap " << _name << " copy assignment operator called" << std::endl;
	if (this != &pCopy)
	{
		_name = pCopy._name;
		_health = pCopy._health;
		_energy = pCopy._energy;
		_atkDmg = pCopy._atkDmg;
	}
	return (*this);
}

void	DiamondTrap::attack(std::string const& target)
{
	FragTrap::attack(target);
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << _name << " serie-model of " << ClapTrap::_name;
}
