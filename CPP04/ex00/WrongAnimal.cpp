/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:39 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:45:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(void)
	: _type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string pType)
	: _type(pType) {
	std::cout << "WrongAnimal " << _type << " parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& pCopy)
	: _type(pCopy._type) {
	std::cout << "WrongAnimal " << _type << " copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal " << _type << " destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const& pCopy)
{
	std::cout << "WrongAnimal " << _type << " copy operator called" << std::endl;
	if (this != &pCopy)
	{
		_type = pCopy._type;
	}
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << _type << ": **aseunrcbtunhclisactxz** **garbage noise** " << std::endl;
}
