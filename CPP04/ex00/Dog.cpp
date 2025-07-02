/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:39 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:31:44 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog(void)
	: Animal("Dog") {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(std::string pType)
	: Animal(pType) {
	std::cout << "Dog " << _type << " parameterized constructor called" << std::endl;
}

Dog::Dog(Dog const& pCopy)
	: Animal(pCopy._type) {
	std::cout << "Dog " << _type << " copy constructor called" << std::endl;
}

Dog::~Dog(void)
{
	std::cout << "Dog " << _type << " destructor called" << std::endl;
}

Dog&	Dog::operator=(Dog const& pCopy)
{
	std::cout << "Dog " << _type << " copy operator called" << std::endl;
	if (this != &pCopy)
	{
		_type = pCopy._type;
	}
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << _type << " **woof** **woof**" << std::endl;
}