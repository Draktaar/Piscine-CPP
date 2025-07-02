#include "Cat.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:39 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 15:26:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

Cat::Cat(void)
	: Animal("Cat") {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string pType)
	: Animal(pType) {
	std::cout << "Cat " << _type << " parameterized constructor called" << std::endl;
}

Cat::Cat(Cat const& pCopy)
	: Animal(pCopy._type) {
	std::cout << "Cat " << _type << " copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << "Cat " << _type << " destructor called" << std::endl;
}

Cat&	Cat::operator=(Cat const& pCopy)
{
	std::cout << "Cat " << _type << " copy operator called" << std::endl;
	if (this != &pCopy)
	{
		_type = pCopy._type;
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << _type << " **meow** **meow**" << std::endl;
}
