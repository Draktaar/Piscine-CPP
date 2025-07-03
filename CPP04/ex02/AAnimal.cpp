/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:39 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:34:41 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal(void)
	: _type("Animal") {
	std::cout << "Animal default constructor called" << std::endl;
}

AAnimal::AAnimal(std::string pType)
	: _type(pType) {
	std::cout << "Animal " << _type << " parameterized constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const& pCopy)
	: _type(pCopy._type) {
	std::cout << "Animal " << _type << " copy constructor called" << std::endl;
}

AAnimal::~AAnimal(void) {}

AAnimal&	AAnimal::operator=(AAnimal const& pCopy)
{
	std::cout << "Animal " << _type << " copy operator called" << std::endl;
	if (this != &pCopy)
	{
		_type = pCopy._type;
	}
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (this->_type);
}
