/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 15:12:54 by achu              #+#    #+#             */
/*   Updated: 2025/07/27 18:18:16 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.h"
#include <algorithm>
#include <vector>
#include <limits>

Span::Span(void)
	: N(0)
{}

Span::Span(unsigned int pN)
	: N(pN)
{}

Span::Span(const Span& pCopy)
	: N(pCopy.N)
{
	std::copy(pCopy._span.begin(), pCopy._span.end(), _span.begin());
}

Span::~Span(void)
{}

Span&	Span::operator=(const Span& pCopy)
{
	if (this != &pCopy)
	{
		N = pCopy.N;
		std::copy(pCopy._span.begin(), pCopy._span.end(), _span.begin());
	}
	return (*this);
}

void	Span::addNumber(int pNum)
{
	if (_span.size() >= N)
		throw (OverflowException());
	_span.push_back(pNum);
}

int		Span::shortestSpan(void) const
{
	if (_span.size() < 2)
		throw (EmptyException());

	std::vector<int>	lCopy(_span.begin(), _span.end());
	std::sort(lCopy.begin(), lCopy.end());

	int	shortestValue = std::numeric_limits<int>::max();
	std::vector<int>::iterator	i;

	for (i = lCopy.begin(); i != lCopy.end() - 1; ++i)
	{
		int	temp = std::abs(*i - *(i + 1));
		if (temp < shortestValue)
			shortestValue = temp;
	}
	return (shortestValue);
}

int		Span::longestSpan(void) const
{
	if (_span.size() < 2)
		throw (EmptyException());

	std::vector<int>::const_iterator	maxIt = std::max_element(_span.begin(), _span.end());
	std::vector<int>::const_iterator	minIt = std::min_element(_span.begin(), _span.end());

	return (*maxIt - *minIt);
}

const char*	Span::OverflowException::what() const throw()
{
	return ("Error: Adding exceed maximum container capacity.");
}

const char*	Span::EmptyException::what() const throw()
{
	return ("Error: Empty or one number inside the container.");
}