/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:36:46 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:25:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __AANIMAL_H__
#  define __AANIMAL_H__

#include <string>

class AAnimal
{
	protected:
		std::string		_type;

	public:

		AAnimal(void);
		AAnimal(std::string pType);
		AAnimal(AAnimal const& pCopy);
		virtual ~AAnimal(void);

		AAnimal&	operator=(AAnimal const& pCopy);

		std::string		getType(void) const;
		virtual void	makeSound(void) const = 0;
};

#endif