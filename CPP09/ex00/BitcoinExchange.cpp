/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:00:20 by achu              #+#    #+#             */
/*   Updated: 2025/08/07 13:34:43 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"
#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <list>
#include <limits>

//#****************************************************************************#
//#                             STATIC FUNCTION                                #
//#****************************************************************************#

static std::list<std::string>	split(std::string pStr, const std::string& pDelim)
{
	std::list<std::string>	lTokens;
	std::string				lToken;
	size_t					lPos = 0;

	while ((lPos = pStr.find(pDelim)) != std::string::npos) {
		lToken = pStr.substr(0, lPos);
		if (!lToken.empty())
			lTokens.push_back(lToken);
		pStr.erase(0, lPos + pDelim.length());
	}
	lTokens.push_back(pStr);
	return (lTokens);
}

static std::string		trim(std::string pStr)
{
	size_t	lStart;
	size_t	lEnd;

	lStart = pStr.find_first_not_of(" \t\f\v\n\r");
	if (lStart == std::string::npos)
		pStr.clear();
	pStr.erase(0, lStart);
	lEnd = pStr.find_last_not_of(" \t\f\v\n\r");
	pStr.erase(lEnd + 1);
	return (pStr);
}

static bool		isValidDate(const std::string& pDate)
{
	if (pDate.size() != 10)
		throw BitcoinExchange::InputException();

	if (pDate[4] != '-' && pDate[7] != '-')
		throw BitcoinExchange::InputException();

	for (size_t i = 0; i < pDate.size(); i++) {
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(pDate[i]))
			throw BitcoinExchange::DigitException();
	}

	int		lMonth = std::atoi(pDate.substr(5, 2).c_str());
	int		lDay = std::atoi(pDate.substr(8, 2).c_str());

	if ((lMonth < 1 || 12 < lMonth) || (lDay < 1 || 31 < lDay))
		throw BitcoinExchange::InputException();

	return (true);
}

static bool		isValidNumber(const std::string& pValue)
{
	double	lValue = std::atof(pValue.c_str());

	if (pValue.empty())
		throw BitcoinExchange::InputException();
	for (size_t i = 0; i < pValue.size(); i++) {
		if (!std::isdigit(pValue[i]) && pValue[i] != '.' && pValue[i] != '-'  && pValue[i] != 'f')
			throw BitcoinExchange::DigitException();
	}
	if (lValue < 0)
		throw BitcoinExchange::UnderflowException();
	if (lValue > 1000)
		throw BitcoinExchange::OverflowException();
	return (true);
}

//#****************************************************************************#
//#                        CONSTRUCTOR & DESTRUCTOR                            #
//#****************************************************************************#

BitcoinExchange::BitcoinExchange(void)
{
	throw FileException();
}

BitcoinExchange::BitcoinExchange(const std::string& pFile)
	: _fileName(pFile)
{
	_input.open(_fileName.c_str());
	if (!_input.is_open())
		throw FileException();

	_data.open("data.csv");
	if (!_data.is_open())
		throw FileException();

	loadData();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& pCopy)
	: _fileName(pCopy._fileName)
{
	_input.open(_fileName.c_str());
	if (!_input.is_open())
		throw FileException();
	_data.open("data.csv");
	if (!_data.is_open())
		throw FileException();
}

BitcoinExchange::~BitcoinExchange(void)
{
	if (_input.is_open())
		_input.close();
	if (_data.is_open())
		_data.close();
}

//#****************************************************************************#
//#                             MEMBER FUNCTION                                #
//#****************************************************************************#

void	BitcoinExchange::loadData(void)
{
	std::string		lLine;

	std::getline(_data, lLine);
	while (std::getline(_data, lLine))
	{
		std::list<std::string>				lTokens = split(lLine, ",");
		std::list<std::string>::iterator	lTokenIt = lTokens.begin();

		std::string		lDate = *lTokenIt;
		std::string		lValue = *(++lTokenIt);

		_map[lDate] = std::atof(lValue.c_str());
	}
}

double		BitcoinExchange::calculateBitcoin(const std::string& pDate, const double& pNumber) const
{
	std::map<std::string, double>::const_iterator	lIt = _map.lower_bound(pDate);

	if (lIt == _map.end()) {
		--lIt;
	}
	else if (lIt->first != pDate) {
		if (lIt == _map.begin()) {
			throw DateException();
		}
		--lIt;
	}
	return (lIt->second * pNumber);
}

void	BitcoinExchange::exchange(void)
{
	std::string		lLine;

	std::getline(_input, lLine);
	while (std::getline(_input, lLine))
	{
		try
		{
			if (lLine.empty() || lLine[0] == '#') // skip comment or empty lines
        		continue;
			std::list<std::string>				lTokens = split(lLine, "|");
			std::list<std::string>::iterator	lTokenIt = lTokens.begin();

			std::string	lDate = trim(*lTokenIt);

			if (lTokens.size() < 2)
				throw InputException();
			
			std::string	lNumber = trim(*(++lTokenIt));

			isValidDate(lDate);
			isValidNumber(lNumber);

			double	lNbr = std::atof(lNumber.c_str());
			double	lNewValue = calculateBitcoin(lDate, lNbr);

			std::cout << lDate << " => " << lNumber << " = " << lNewValue << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << e.what() << " => " << lLine << WHITE << std::endl;
			continue;
		}		
	}
}

//#****************************************************************************#
//#                            OPERATOR OVERLOAD                               #
//#****************************************************************************#

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& pCopy)
{
	if (this != &pCopy)
	{
		this->_fileName = pCopy._fileName;
		this->_input.open(_fileName.c_str());
		if (!_input.is_open())
			throw FileException();
		_data.open("data.csv");
		if (!_data.is_open())
			throw FileException();
	}
	return (*this);
}

//#****************************************************************************#
//#                                EXCEPTION                                   #
//#****************************************************************************#

const char*		BitcoinExchange::FileException::what() const throw()
{
	return ("Error: Cannot open file");
}

const char*		BitcoinExchange::InputException::what() const throw()
{
	return ("Error: Bad input");
}

const char*		BitcoinExchange::DigitException::what() const throw()
{
	return ("Error: NAN");
}

const char*		BitcoinExchange::OverflowException::what() const throw()
{
	return ("Error: Overflow Int");
}

const char*		BitcoinExchange::UnderflowException::what() const throw()
{
	return ("Error: Negative Number");
}

const char*		BitcoinExchange::DateException::what() const throw()
{
	return ("Error: No previous date recorded");
}