/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:47:23 by achu              #+#    #+#             */
/*   Updated: 2025/07/04 14:39:28 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ICHARACTER_H__
#define __ICHARACTER_H__

#include <string>

class AMateria;

class ICharacter
{
	public:

		virtual ~ICharacter() {};

		virtual std::string const&		getName() const = 0;
	
		virtual void		equip(AMateria*) = 0;
		virtual void		unequip(int idx) = 0;
		virtual void		use(int idx, ICharacter& target) = 0;
};

#endif
