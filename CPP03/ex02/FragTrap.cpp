/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:00:56 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 01:58:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) :
	ClapTrap("Default", 100, 100, 30) {
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string pName) :
	ClapTrap(pName, 100, 100, 30) {
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