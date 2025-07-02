/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:46 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:25:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __ANIMAL_H__
#  define __ANIMAL_H__

#include <string>

class Animal
{
	protected:
		std::string		_type;

	public:

		Animal(void);
		Animal(std::string pType);
		Animal(Animal const& pCopy);
		virtual ~Animal(void);

		Animal&	operator=(Animal const& pCopy);

		std::string		getType(void) const;

		virtual void	makeSound(void) const;
};

#endif