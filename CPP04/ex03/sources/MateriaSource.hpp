/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:09:00 by achu              #+#    #+#             */
/*   Updated: 2025/07/04 14:32:58 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MATERIA_SOURCE__
#define __MATERIA_SOURCE__

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	private:

		AMateria*	_memorySlots[4];

	public:

		MateriaSource();
		MateriaSource(MateriaSource const& pCopy);

		~MateriaSource();

		MateriaSource&	operator=(MateriaSource const& pCopy);

		void		learnMateria(AMateria* pMateria);
		AMateria*	createMateria(std::string const& type);
};

#endif