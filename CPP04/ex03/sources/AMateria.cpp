/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:44:28 by achu              #+#    #+#             */
/*   Updated: 2025/07/03 16:10:04 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

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

