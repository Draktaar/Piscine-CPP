/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:46 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:26:34 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __CAT_H__
#  define __CAT_H__


#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
	public:

		Cat(void);
		Cat(std::string pType);
		Cat(Cat const& pCopy);
		~Cat(void);

		Cat&	operator=(Cat const& pCopy);

		void	makeSound(void) const;
};

#endif