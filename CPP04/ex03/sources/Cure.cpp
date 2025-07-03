/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:15:43 by achu              #+#    #+#             */
/*   Updated: 2025/07/03 16:54:29 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

Cure::Cure()
	: AMateria::AMateria("cure") {
}

Cure::Cure(Cure const& pCopy)
	: AMateria::AMateria(pCopy) {
}

Cure::~Cure() {}

Cure&	Cure::operator=(Cure const& pCopy)
{
	if (this != &pCopy)
	{
		_type = pCopy.getType();
	}
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure);
}

void		Cure::use(ICharacter& pTarget)
{
	std::cout << "* heals " << pTarget.getName() << "'s wounds *" << std::endl;
}