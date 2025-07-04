/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:13:23 by achu              #+#    #+#             */
/*   Updated: 2025/07/04 14:49:33 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < 4; i++) {
		_memorySlots[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const& pCopy) {
	for (size_t i = 0; i < 4; i++) {
		if (_memorySlots[i] != NULL)
			delete _memorySlots[i];
	}
	for (size_t i = 0; i < 4; i++) {
		_memorySlots[i] = pCopy._memorySlots[i]->clone();
	}
}

MateriaSource::~MateriaSource() {
	for (size_t i = 0; i < 4; i++) {
		if (_memorySlots[i] != NULL)
			delete _memorySlots[i];
	}
}

MateriaSource&	MateriaSource::operator=(MateriaSource const& pCopy)
{
	if (this != &pCopy)
	{
		for (size_t i = 0; i < 4; i++) {
			if (_memorySlots[i] != NULL)
				delete _memorySlots[i];
		}
		for (size_t i = 0; i < 4; i++) {
			_memorySlots[i] = pCopy._memorySlots[i]->clone();
		}
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria *pMateria)
{
	for (size_t i = 0; i < 4; i++) {
		if (_memorySlots[i] == NULL) {
				_memorySlots[i] = pMateria;
				break;
		}
	}
}

AMateria	*MateriaSource::createMateria(std::string const& pType)
{
	for (size_t i = 0; i < 4; i++) {
		if (_memorySlots[i]->getType() == pType)
			return (_memorySlots[i]->clone());
	}
	return (NULL);
}
