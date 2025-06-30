/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:37:50 by achu              #+#    #+#             */
/*   Updated: 2025/06/30 17:05:48 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_frctBits = 8;
 
Fixed::Fixed(void) : _fpValue(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed& pCopy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = pCopy;
}
Fixed::Fixed(const int& pInt)
{
	std::cout << "Int constructor called" << std::endl;
	_fpValue = pInt << _frctBits;
}
Fixed::Fixed(const float& pFloat)
{
	std::cout << "Float constructor called" << std::endl;
	_fpValue = roundf(pFloat * (1 << _frctBits));
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return (this->_fpValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

float	Fixed::toFloat(void) const
{
	return ((float)_fpValue / (1 << _frctBits));
}

int		Fixed::toInt(void) const
{
	return ((int)_fpValue >> _frctBits);
}

Fixed& Fixed::operator=(const Fixed& pCopy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &pCopy)
		this->_fpValue = pCopy.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& pOs, const Fixed& pFixed)
{
	pOs << pFixed.toFloat();
	return (pOs);
}
