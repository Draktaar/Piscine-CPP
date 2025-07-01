/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:37:50 by achu              #+#    #+#             */
/*   Updated: 2025/07/01 21:10:07 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int	Fixed::_frctBits = 8;

//#****************************************************************************#
//#                        CONSTRUCTOR & DESTRUCTOR                            #
//#****************************************************************************#

Fixed::Fixed(void) : _fpValue(0) {}
Fixed::Fixed(const Fixed& pCopy) {
	*this = pCopy;
}
Fixed::Fixed(const int& pInt) {
	_fpValue = pInt << _frctBits;
}
Fixed::Fixed(const float& pFloat) {
	_fpValue = roundf(pFloat * (1 << _frctBits));
}
Fixed::~Fixed(void) {}

//#****************************************************************************#
//#                              GETTER-SETTER                                 #
//#****************************************************************************#

int Fixed::getRawBits(void) const
{
	return (this->_fpValue);
}

void Fixed::setRawBits(int const raw)
{
	this->_fpValue = raw;
}

//#****************************************************************************#
//#                             MEMBER FUNCTION                                #
//#****************************************************************************#

float	Fixed::toFloat(void) const
{
	return ((float)_fpValue / (1 << _frctBits));
}

int		Fixed::toInt(void) const
{
	return ((int)_fpValue >> _frctBits);
}

Fixed& Fixed::min(Fixed& pFixed1, Fixed& pFixed2)
{
	return (pFixed1.getRawBits() < pFixed2.getRawBits() ? pFixed1 : pFixed2);
}

const Fixed& Fixed::min(const Fixed& pFixed1, const Fixed& pFixed2)
{
	return (pFixed1.getRawBits() < pFixed2.getRawBits() ? pFixed1 : pFixed2);
}

Fixed &Fixed::max(Fixed &pFixed1, Fixed &pFixed2)
{
	return (pFixed1.getRawBits() > pFixed2.getRawBits() ? pFixed1 : pFixed2);
}

const Fixed& Fixed::max(const Fixed& pFixed1, const Fixed& pFixed2)
{
	return (pFixed1.getRawBits() > pFixed2.getRawBits() ? pFixed1 : pFixed2);
}

//#****************************************************************************#
//#                            OPERATOR OVERLOAD                               #
//#****************************************************************************#

Fixed&		Fixed::operator=(const Fixed& pCopy)
{
	if (this != &pCopy)
		this->_fpValue = pCopy.getRawBits();
	return (*this);
}

std::ostream&		operator<<(std::ostream& pOs, const Fixed& pFixed)
{
	pOs << pFixed.toFloat();
	return (pOs);
}

bool		Fixed::operator>(const Fixed& pFixed) const
{
	return (this->_fpValue > pFixed._fpValue);
}

bool		Fixed::operator>=(const Fixed& pFixed) const
{
	return (this->_fpValue >= pFixed._fpValue);
}

bool		Fixed::operator<(const Fixed& pFixed) const
{
	return (this->_fpValue < pFixed._fpValue);
}

bool		Fixed::operator<=(const Fixed& pFixed) const
{
	return (this->_fpValue <= pFixed._fpValue);
}

bool		Fixed::operator==(const Fixed& pFixed) const
{
	return (this->_fpValue == pFixed._fpValue);
}

bool		Fixed::operator!=(const Fixed& pFixed) const
{
	return (this->_fpValue != pFixed._fpValue);
}

Fixed		Fixed::operator+(const Fixed& pFixed) const
{
	Fixed	result;

	result.setRawBits(this->_fpValue + pFixed._fpValue);
	return (result);
}

Fixed		Fixed::operator-(const Fixed& pFixed) const
{
	Fixed	result;

	result.setRawBits(this->_fpValue - pFixed._fpValue);
	return (result);
}

Fixed		Fixed::operator*(const Fixed& pFixed) const
{
	Fixed	result;

	result.setRawBits((_fpValue * pFixed._fpValue) >> _frctBits);
	return (result);
}

Fixed		Fixed::operator/(const Fixed& pFixed) const
{
	if (pFixed._fpValue == 0)
        return (Fixed(0));

	Fixed	result;
	result.setRawBits((_fpValue << _frctBits) / pFixed._fpValue);
	return (result);
}

Fixed&		Fixed::operator++()
{
	this->_fpValue++;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_fpValue++;
	return (tmp);
}

Fixed&		Fixed::operator--()
{
	this->_fpValue--;
	return (*this);
}

Fixed		Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_fpValue--;
	return (tmp);
}
