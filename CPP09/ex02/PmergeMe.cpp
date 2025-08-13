/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:00:21 by achu              #+#    #+#             */
/*   Updated: 2025/08/14 00:32:34 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <list>

//#****************************************************************************#
//#                             STATIC FUNCTION                                #
//#****************************************************************************#

static std::vector<int>	jacobsthal(int pN)
{
	std::vector<int>	seq;

	if (pN < 0)
		return (seq);
	seq.push_back(0);

	if (pN == 0)
		return (seq);
	seq.push_back(1);

	int		temp = 0;
	for (int i = 2; i < pN; i++) {
		temp = seq[i - 1] + 2 * seq[i - 2];
		if (temp > pN)
		 	break;
		seq.push_back(temp);
	}
	return (seq);
}

//#****************************************************************************#
//#                        CONSTRUCTOR & DESTRUCTOR                            #
//#****************************************************************************#

PmergeMe::PmergeMe(void)
{
	throw InvalidException();
}

PmergeMe::PmergeMe(const PmergeMe& pCopy)
{
	
}

PmergeMe::~PmergeMe(void)
{
	
}

//#****************************************************************************#
//#                             MEMBER FUNCTION                                #
//#****************************************************************************#

void	PmergeMe::logVector(const std::vector<int>& pContainer, const std::string& pMessage)
{
	std::cout << pMessage;
	for (std::vector<int>::const_iterator it = pContainer.begin(); it != pContainer.end(); it++) {
		if (it != pContainer.begin() && it != pContainer.end())
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

void	PmergeMe::insertVector(std::vector<int>& main, std::vector<int>& pend, std::vector<int>& left, std::vector<int>& pContainer, const int& pSeqSize)
{
	
}

void	PmergeMe::mergeVector(std::vector<int>& pContainer, int pSeqSize)
{
	int		pairSize = pSeqSize * 2;
	int		maxPair = static_cast<int>(pContainer.size() / pairSize);

	if (maxPair <= 0) //if this recursion cannot create another pair, end the recursion
		return ;

	bool	isOdd = maxPair % 2 == 1; //gives the bool isOdd of total of 2 pairs

	std::vector<int>::iterator	start = pContainer.begin();
	std::vector<int>::iterator	end = pContainer.begin() + (pairSize * maxPair);

	for (std::vector<int>::iterator it = start; it < end; it += pairSize)
	{
		if (*(it + pSeqSize - 1) > *(it + pairSize - 1))
			std::swap_ranges(it, it + pSeqSize, it + pSeqSize);
	}

	mergeVector(pContainer, pSeqSize * 2);

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------

	std::vector<int>	main;
	std::vector<int>	pend;
	std::vector<int>	left;

	bool	newIsOdd = static_cast<int>((pContainer.size() / pSeqSize)) % 2 == 1;
	std::vector<int>::iterator	newEnd = end + (newIsOdd * pSeqSize);

	bool	isPend = true;
	for (std::vector<int>::iterator it = start; it < newEnd; it += pSeqSize)
	{
		isPend ? pend.insert(pend.end(), it, it + pSeqSize) : main.insert(main.end(), it, it + pSeqSize);
		isPend = !isPend;
	}
	left.insert(left.end(), newEnd, pContainer.end());
	std::cout << "Pend: ";
	for (std::vector<int>::iterator it = pend.begin(); it < pend.end(); it += 1)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Main: ";
	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it += 1)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << "Left: ";
	for (std::vector<int>::iterator it = left.begin(); it < left.end(); it += 1)
		std::cout << *it << " ";
	std::cout << std::endl;

	//------------------------------------------------------------------------------
	//------------------------------------------------------------------------------

	int		seqPendSize = static_cast<int>(pend.size() / pSeqSize); // Numbers of sequence inside the Pend

	std::vector<int> js = jacobsthal(seqPendSize);
	js.push_back(seqPendSize);

	for (std::vector<int>::iterator	it = js.begin() + 2; it < js.end(); it++)
	{
		if (*it == 1) {
			main.insert(main.begin(), pend.begin(), pend.begin() + pSeqSize);
			continue;
		}
		for (int i = *it; i != *(it - 1); i--)
		{
			std::vector<int> block_last_elements;
			for (size_t j = 0; j < main.size(); j += pSeqSize)
    			block_last_elements.push_back(main[j + pSeqSize - 1]);
			
			int	last = *(pend.begin() + (i * pSeqSize - 1));
			std::vector<int>::iterator	pos = std::lower_bound(block_last_elements.begin(), block_last_elements.end(), last);

			int	dist = std::distance(block_last_elements.begin(), pos) * pSeqSize;

			main.insert(main.begin() + dist, pend.begin() + (i - 1) * pSeqSize, pend.begin() + i * pSeqSize);
		}
	}
	std::cout << std::endl;

	main.insert(main.end(), left.begin(), left.end());
	pContainer = main;

	for (std::vector<int>::iterator it = main.begin(); it < main.end(); it += 1)
		std::cout << *it << " ";
	std::cout << std::endl;
	std::cout << std::endl;
}

//#****************************************************************************#
//#                            OPERATOR OVERLOAD                               #
//#****************************************************************************#

PmergeMe&	PmergeMe::operator=(const PmergeMe& pCopy)
{
	if (this != &pCopy)
	{
		
	}
	return (*this);
}

//#****************************************************************************#
//#                                EXCEPTION                                   #
//#****************************************************************************#

const char*		PmergeMe::InvalidException::what() const throw()
{
	return ("Error: ");
}