/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:46 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:44:19 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __WRONG_CAT_H__
#  define __WRONG_CAT_H__


#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
	public:

		WrongCat(void);
		WrongCat(std::string pType);
		WrongCat(WrongCat const& pCopy);
		~WrongCat(void);

		WrongCat&	operator=(WrongCat const& pCopy);

		void	makeSound(void) const;
};

#endif