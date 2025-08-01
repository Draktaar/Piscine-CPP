/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:00:40 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 22:58:25 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>
#include <cstdlib>
#include <limits>

static bool	detectInt(const std::string& pLiteral)
{
	size_t	length = pLiteral.length();
	for (size_t i = 0; i < length; i++) {
		if (!std::isdigit(pLiteral[i]))
			return (false);
	}
	return (true);
}

static ScalarConverter::LiteralType	detectType(const std::string& pLiteral)
{
	if (pLiteral == "nan" || pLiteral == "nanf")
		return (ScalarConverter::LITERAL_NAN);
	if (pLiteral == "+inf" || pLiteral == "+inff")
		return (ScalarConverter::LITERAL_INFP);
	if (pLiteral == "-inf" || pLiteral == "-inff")
		return (ScalarConverter::LITERAL_INFN);

	if (pLiteral.length() == 1 && std::isdigit(pLiteral[0]))
		return (ScalarConverter::LITERAL_CHAR);
	if (pLiteral.find('.') != std::string::npos && pLiteral[pLiteral.length() - 1] == 'f')
		return (ScalarConverter::LITERAL_FLOAT);
	if (pLiteral.find('.') != std::string::npos)
		return (ScalarConverter::LITERAL_DOUBLE);
	if (detectInt(pLiteral))
		return (ScalarConverter::LITERAL_INT);

	return (ScalarConverter::LITERAL_INVALID);
}

static void		handleNan( void )
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: nanf\n";
	std::cout << "double: nan" << std::endl;
}

static void		handleInfP( void )
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: +inff\n";
	std::cout << "double: +inf" << std::endl;
}

static void		handleInfN( void )
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: -inff\n";
	std::cout << "double: -inf" << std::endl;
}

static void		handleChar( double pLiteral )
{
	char	lChar = static_cast<char>(pLiteral);

	std::cout << "char: ";
	if (pLiteral < 0 || 255 < pLiteral) {
		std::cout << "impossible\n";
		return ;
	}
	else if (!std::isprint(lChar)) {
		std::cout << "undisplayable\n";
		return ;
	}
	std::cout << "\'" << lChar << "\'\n";
}

static void		handleInt( double pLiteral )
{
	long	lInt = static_cast<long>(pLiteral);

	std::cout << "int: ";
	if (lInt < std::numeric_limits<int>::min() || std::numeric_limits<int>::max() < lInt) {
		std::cout << "overflow\n";
		return ;
	}
	std::cout << lInt << "\n";
}

static void		handleFloat( double pLiteral )
{
	float	lFloat = static_cast<float>(pLiteral);

	std::cout << "float: ";
	if (lFloat < std::numeric_limits<float>::min() || std::numeric_limits<float>::max() < lFloat) {
		std::cout << "overflow" << std::endl;
		return ;
	}
	std::cout << lFloat;
	if (lFloat == static_cast<int>(lFloat))
		std::cout << ".0";
	std::cout << "f\n";
}

static void		handleDouble( double pLiteral )
{
	std::cout << "double: ";
	if (pLiteral < std::numeric_limits<double>::min() || std::numeric_limits<double>::max() < pLiteral) {
		std::cout << "overflow" << std::endl;
		return ;
	}
	std::cout << pLiteral;
	if (pLiteral == static_cast<int>(pLiteral))
		std::cout << ".0";
	std::cout << std::endl;
}

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter& pCopy) { (void)pCopy; }
ScalarConverter::~ScalarConverter() {}
ScalarConverter&	ScalarConverter::operator=(const ScalarConverter& pCopy) { (void)pCopy; return (*this); }

void	ScalarConverter::convert(const std::string& pLiteral)
{
	switch (detectType(pLiteral))
	{
		case (ScalarConverter::LITERAL_INVALID):
			throw ScalarConverter::InvalidLiteralException();

		case (ScalarConverter::LITERAL_NAN):
			handleNan();
			break;
		case (ScalarConverter::LITERAL_INFP):
			handleInfP();
			break;
		case (ScalarConverter::LITERAL_INFN):
			handleInfN();
			break;

		case (ScalarConverter::LITERAL_CHAR):
		case (ScalarConverter::LITERAL_INT):
		case (ScalarConverter::LITERAL_FLOAT):
		case (ScalarConverter::LITERAL_DOUBLE):
			double	lDouble = atof(pLiteral.c_str());
			handleChar(lDouble);
			handleInt(lDouble);
			handleFloat(lDouble);
			handleDouble(lDouble);
			break;
	}
}

const char*		ScalarConverter::InvalidLiteralException::what() const throw()
{
	return ("Error: Invalid Literal");
}