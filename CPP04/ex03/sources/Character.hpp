/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:11:09 by achu              #+#    #+#             */
/*   Updated: 2025/07/03 17:38:11 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __CHARACTER_H__
#  define __CHARACTER_H__

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include <string>

class Character : public ICharacter
{
	private:

		std::string		_name;
		AMateria*		_inventory[4];

	public:

		Character();
		Character(std::string pName);
		Character(Character const& pCopy);
		~Character();

		Character&	operator=(Character const& pCopy);

		std::string const&		getName() const;

		void		equip(AMateria* pM);
		void		unequip(int pIdx);
		void		use(int pIdx, ICharacter& pTarget);
};

#endif