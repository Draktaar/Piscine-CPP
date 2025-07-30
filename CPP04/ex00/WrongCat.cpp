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

#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(void)
	: WrongAnimal("WrongCat") {
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string pType)
	: WrongAnimal(pType) {
	std::cout << "WrongCat " << _type << " parameterized constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const& pCopy)
	: WrongAnimal(pCopy) {
	std::cout << "WrongCat " << _type << " copy constructor called" << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat " << _type << " destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const& pCopy)
{
	std::cout << "Wrong Cat " << _type << " copy operator called" << std::endl;
	if (this != &pCopy)
	{
		_type = pCopy._type;
	}
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << _type << " **meow** **meow**" << std::endl;
}
