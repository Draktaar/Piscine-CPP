/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:20:40 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 22:29:58 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(Brain const& pCopy) {
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = pCopy._ideas[i];
	}
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}

Brain&	Brain::operator=(Brain const& pCopy) {
	std::cout << "Brain assignment operator called" << std::endl;
	if (this != &pCopy)
	{
		for (int i = 0; i < 100; i++) {
			_ideas[i] = pCopy._ideas[i];
	}
	}
	return (*this);
}