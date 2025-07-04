/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:09:52 by achu              #+#    #+#             */
/*   Updated: 2025/07/04 14:32:51 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CURE_H__
#define __CURE_H__

#include "AMateria.hpp"

class Cure : public AMateria
{
	private:
		
	public:
		Cure();
		Cure(Cure const& pCopy);
		~Cure();

		Cure&	operator=(Cure const& pCopy);

		AMateria*	clone() const;
		void		use(ICharacter& pTarget);
};

#endif