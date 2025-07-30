/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 21:28:15 by achu              #+#    #+#             */
/*   Updated: 2025/07/30 14:30:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __BRAIN_H__
#  define __BRAIN_H__

#include <string>

class Brain
{
	public:

		std::string		_ideas[100];

	public:

		Brain(void);
		Brain(Brain const& pCopy);
		~Brain(void);

		Brain&	operator=(Brain const& pCopy);
};

#endif