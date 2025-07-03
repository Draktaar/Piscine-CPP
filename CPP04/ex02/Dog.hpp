/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:46 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:26:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __DOG_H__
#  define __DOG_H__


#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
{
	private:

		Brain*	_brain;

	public:

		Dog(void);
		Dog(std::string pType);
		Dog(Dog const& pCopy);
		~Dog(void);

		Dog&	operator=(Dog const& pCopy);

		void	makeSound(void) const;
};

#endif