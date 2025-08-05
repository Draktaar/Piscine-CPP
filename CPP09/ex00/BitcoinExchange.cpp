/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:00:20 by achu              #+#    #+#             */
/*   Updated: 2025/08/05 16:15:55 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"
#include <iostream>
#include <string>
#include <vector>

//#****************************************************************************#
//#                        CONSTRUCTOR & DESTRUCTOR                            #
//#****************************************************************************#

BitcoinExchange::BitcoinExchange(void)
{
	throw InputException();
}

BitcoinExchange::BitcoinExchange(const std::string& pFile)
	: _fileName(pFile)
{
	_input.open(_fileName.c_str());
	if (!_input.is_open())
		throw InputException();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& pCopy)
	: _fileName(pCopy._fileName)
{
	_input.open(_fileName.c_str());
	if (!_input.is_open())
		throw InputException();
}

BitcoinExchange::~BitcoinExchange(void)
{
	
}

//#****************************************************************************#
//#                              GETTER-SETTER                                 #
//#****************************************************************************#

//#****************************************************************************#
//#                             MEMBER FUNCTION                                #
//#****************************************************************************#

std::vector<std::string>	BitcoinExchange::Split(const std::string& pStr, const std::string& pDelim)
{
	std::vector<std::string>	lTokens;
	std::string					lToken;
	size_t						lPos = 0;

	while ((lPos = pStr.find(pDelim)) != std::string::npos) {
		
	}
}

//#****************************************************************************#
//#                            OPERATOR OVERLOAD                               #
//#****************************************************************************#

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& pCopy)
{
	
}

//#****************************************************************************#
//#                                EXCEPTION                                   #
//#****************************************************************************#

const char*		BitcoinExchange::InputException::what() const throw()
{
	return ("Invalid input file");
}