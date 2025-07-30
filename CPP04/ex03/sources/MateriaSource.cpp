/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:13:23 by achu              #+#    #+#             */
/*   Updated: 2025/07/30 18:52:35 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>

MateriaSource::MateriaSource() {
	for (size_t i = 0; i < 4; i++) {
		_memorySlots[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const& pCopy) {
	for (size_t i = 0; i < 4; i++) {
		if (pCopy._memorySlots[i] != NULL)
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
			if (pCopy._memorySlots[i] != NULL)
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
			std::cout << "You learned " << pMateria->getType() << std::endl;
			return ;
		}
	}
	delete pMateria;
	std::cout << "You cant learn more Spell" << std::endl;
}

AMateria	*MateriaSource::createMateria(std::string const& pType)
{
	for (size_t i = 0; i < 4; i++) {
		if (_memorySlots[i]->getType() == pType)
			return (_memorySlots[i]->clone());
	}
	return (NULL);
}
