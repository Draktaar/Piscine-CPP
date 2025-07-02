/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:39 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:34:41 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

Animal::Animal(void)
	: _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(std::string pType)
	: _type(pType) {
	std::cout << "Animal " << _type << " parameterized constructor called" << std::endl;
}

Animal::Animal(Animal const& pCopy)
	: _type(pCopy._type) {
	std::cout << "Animal " << _type << " copy constructor called" << std::endl;
}

Animal::~Animal(void)
{
	std::cout << "Animal " << _type << " destructor called" << std::endl;
}

Animal&	Animal::operator=(Animal const& pCopy)
{
	std::cout << "Animal " << _type << " copy operator called" << std::endl;
	if (this != &pCopy)
	{
		_type = pCopy._type;
	}
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (this->_type);
}

void	Animal::makeSound(void) const
{
	std::cout << _type << ": **aseunrcbtunhclisactxz** **garbage noise** " << std::endl;
}
