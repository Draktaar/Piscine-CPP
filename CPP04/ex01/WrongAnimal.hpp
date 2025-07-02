/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:46 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:43:13 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __WRONG_ANIMAL_H__
#  define __WRONG_ANIMAL_H__

#include <string>

class WrongAnimal
{
	protected:
		std::string		_type;

	public:

		WrongAnimal(void);
		WrongAnimal(std::string pType);
		WrongAnimal(WrongAnimal const& pCopy);
		virtual ~WrongAnimal(void);

		WrongAnimal&	operator=(WrongAnimal const& pCopy);

		std::string		getType(void) const;

		virtual void	makeSound(void) const;
};

#endif