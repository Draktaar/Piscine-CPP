/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:44:25 by achu              #+#    #+#             */
/*   Updated: 2025/07/03 16:10:50 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __AMATERIA_H__
#  define __AMATERIA_H__

#include "ICharacter.hpp"
#include <string>

class AMateria
{
	protected:

		std::string		_type;

	protected:

		AMateria();
		AMateria(std::string pType);
		AMateria(AMateria const& pCopy);

	public:
		
		virtual ~AMateria();

		AMateria&	operator=(AMateria const& pCopy);

		std::string const&		getType() const;
		
		virtual AMateria*		clone() const = 0;
		virtual void			use(ICharacter& pTarget);
};

#endif