/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:44:28 by achu              #+#    #+#             */
/*   Updated: 2025/07/04 14:44:56 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

AMateria::AMateria()
	: _type("Unknown") {
}

AMateria::AMateria(std::string pType)
	: _type(pType) {
}

AMateria::AMateria(AMateria const& pCopy)
	: _type(pCopy._type) {
}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(AMateria const& pCopy)
{
	if (this != &pCopy)
	{
		_type = pCopy._type;
	}
	return (*this);
}

std::string const&	AMateria::getType() const { return (_type); }

void	AMateria::use(ICharacter& pTarget)
{
	std::cout << "* random spell are targetting" << pTarget.getName() << std::endl;
}
