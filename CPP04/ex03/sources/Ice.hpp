/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 16:09:50 by achu              #+#    #+#             */
/*   Updated: 2025/07/03 16:14:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __ICE_H__
#  define __ICE_H__

#include "AMateria.hpp"

class Ice : public AMateria
{
	private:
		
	public:
		Ice();
		Ice(Ice const& pCopy);
		~Ice();

		Ice&	operator=(Ice const& pCopy);

		AMateria*	clone() const;
		void		use(ICharacter& pTarget);
};

#endif