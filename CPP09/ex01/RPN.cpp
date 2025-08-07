/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:44:07 by achu              #+#    #+#             */
/*   Updated: 2025/08/07 13:38:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.h"
#include <iostream>
#include <cstdlib>
#include <string>

//#****************************************************************************#
//#                        CONSTRUCTOR & DESTRUCTOR                            #
//#****************************************************************************#

RPN::RPN(void)
{
	
}

RPN::RPN(const std::string& pExpr)
	: _expr(pExpr)
{
	checkExpr();
}

RPN::RPN(const RPN& pCopy)
	: _expr(pCopy._expr)
{
	
}

RPN::~RPN(void)
{
	
}

//#****************************************************************************#
//#                             MEMBER FUNCTION                                #
//#****************************************************************************#

void	RPN::ops(char pOperator)
{
	int	a, b;
	int	result;

	if (_stack.size() < 2)
		throw OperandException();

	b = _stack.top(); _stack.pop();
	a = _stack.top(); _stack.pop();
	switch (pOperator)
	{
		case '+':
			result = a + b;
			break;
		case '-':
			result = a - b;
			break;
		case '*':
			result = a * b;
			break;
		case '/':
			if (b == 0)
				throw ZeroDivException();
			result = a / b;
			break;
	}
	_stack.push(result);
}

void	RPN::checkExpr(void) const
{
	std::string		lAuthorized = " \t\f\v\n\r0123456789+-*/";
	size_t			lCheck;

	lCheck = _expr.find_first_not_of(lAuthorized);
	if (lCheck != std::string::npos)
		throw ArithmeticException();
}

void	RPN::resolve(void)
{
	const char* buf = _expr.c_str();

	while (*buf)
	{
		while (*buf == ' ')
			buf++;
		if (std::isdigit(*buf))
			_stack.push(static_cast<int>(*buf - '0'));
		else if (*buf == '+' || *buf == '-' || *buf == '*' || *buf == '/')
			ops(*buf);
		++buf;
		if (*buf != ' ' && *buf != '\0')
			throw ArithmeticException();
	}
	if (_stack.size() > 1)
		throw OperandException();
	std::cout << _stack.top() << std::endl;
}

//#****************************************************************************#
//#                            OPERATOR OVERLOAD                               #
//#****************************************************************************#

RPN&	RPN::operator=(const RPN& pCopy)
{
	if (this != &pCopy)
	{
		this->_expr = pCopy._expr;
	}
	return (*this);
}

//#****************************************************************************#
//#                                EXCEPTION                                   #
//#****************************************************************************#

const char*		RPN::ZeroDivException::what() const throw()
{
	return ("Error: Devided by Zero");
}

const char*		RPN::OperandException::what() const throw()
{
	return ("Error: Not enough operands");
}

const char*		RPN::ArithmeticException::what() const throw()
{
	return ("Error: Invalid Expression");
}