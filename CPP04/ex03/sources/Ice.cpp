#include "Ice.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:15:46 by achu              #+#    #+#             */
/*   Updated: 2025/07/03 16:15:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

Ice::Ice()
	: AMateria::AMateria("ice") {
}

Ice::Ice(Ice const& pCopy)
	: AMateria::AMateria(pCopy) {
}

Ice::~Ice() {}

Ice&	Ice::operator=(Ice const& pCopy)
{
	if (this != &pCopy)
	{
		_type = pCopy.getType();
	}
	return (*this);
}

AMateria*	Ice::clone() const
{
	AMateria*	spell = new Ice;
	return (spell);
}

void		Ice::use(ICharacter& pTarget)
{
	std::cout << "* shoots an ice bolt at " << pTarget.getName() << "*" << std::endl;
}

