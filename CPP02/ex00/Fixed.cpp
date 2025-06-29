/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:37:50 by achu              #+#    #+#             */
/*   Updated: 2025/06/30 01:19:57 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

static const int	_franctionalBits = 8;
 
Fixed::Fixed(void) : _fpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& pCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = pCopy;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits function called" << std::endl;
	return (this->_fpValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

Fixed& Fixed::operator=(const Fixed& pCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &pCopy)
		this->_fpValue = pCopy.getRawBits();
	return (*this);
}
