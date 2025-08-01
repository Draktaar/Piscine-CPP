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
	: Animal("Cat"), _brain(new Brain) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(std::string pType)
	: Animal(pType), _brain(new Brain) {
	std::cout << "Cat " << _type << " parameterized constructor called" << std::endl;
}

Cat::Cat(Cat const& pCopy)
	: Animal(pCopy), _brain(new Brain(*pCopy._brain)) {
	std::cout << "Cat " << _type << " copy constructor called" << std::endl;
}

Cat::~Cat(void)
{
	std::cout << _type << " destructor called" << std::endl;
	delete _brain;
}

Cat&	Cat::operator=(Cat const& pCopy)
{
	std::cout << "Cat " << _type << " copy operator called" << std::endl;
	if (this != &pCopy)
	{
		_type = pCopy._type;
		delete _brain;
		_brain = new Brain(*pCopy._brain);
	}
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << _type << " **meow** **meow**" << std::endl;
}

void	Cat::fillIdeas(void)
{
	_brain->_ideas[0] = "eat";
	_brain->_ideas[1] = "poop";
	_brain->_ideas[2] = "play";
	_brain->_ideas[3] = "sleep";
}

void		Cat::getIdeas(int pIdx) const
{
	if (pIdx < 0 || 99 < pIdx) {
		std::cerr << "Error: Accessing Ideas that are out of range" << std::endl;
		return ;
	}
	std::cout << _brain->_ideas[pIdx] << std::endl;
}
