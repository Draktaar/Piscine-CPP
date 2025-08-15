/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:00:21 by achu              #+#    #+#             */
/*   Updated: 2025/08/15 01:00:07 by achu             ###   ########.fr       */
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

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe& pCopy)
{
	(void)pCopy;
}

PmergeMe::~PmergeMe(void) {}

//#****************************************************************************#
//#                             MEMBER FUNCTION                                #
//#****************************************************************************#

void	PmergeMe::fordjohnsonVector(std::vector<int>& pContainer, int pSeqSize)
{
	//------------------------------------------------------------------------------
	// Merge swap pairs of pairs of pairs
	//------------------------------------------------------------------------------

	int		pairSize = pSeqSize * 2;
	int		maxPair = static_cast<int>(pContainer.size() / pairSize);

	if (maxPair <= 0) //if this recursion cannot create another pair, end the recursion
		return ;

	std::vector<int>::iterator	start = pContainer.begin();
	std::vector<int>::iterator	end = pContainer.begin() + (pairSize * maxPair);

	for (std::vector<int>::iterator it = start; it < end; it += pairSize) // swap the block if the first block is bigger than the second block in a pair to ensure order of sequence inside a block
	{
		if (*(it + pSeqSize - 1) > *(it + pairSize - 1))
			std::swap_ranges(it, it + pSeqSize, it + pSeqSize);
	}

	fordjohnsonVector(pContainer, pSeqSize * 2); // recursively call merge func until not pair can match

	//------------------------------------------------------------------------------
	// Initialization for the main, pend and leftovers
	//------------------------------------------------------------------------------

	std::vector<int>	main;
	std::vector<int>	pend;
	std::vector<int>	left;

	bool	isOdd = static_cast<int>((pContainer.size() / pSeqSize)) % 2 == 1;
	std::vector<int>::iterator	newEnd = end + (isOdd * pSeqSize);

	bool	isPend = true;
	for (std::vector<int>::iterator it = start; it < newEnd; it += pSeqSize) // insert each block to a container, starting with pend then alternating with main
	{
		isPend ? pend.insert(pend.end(), it, it + pSeqSize) : main.insert(main.end(), it, it + pSeqSize);
		isPend = !isPend;
	}
	left.insert(left.end(), newEnd, pContainer.end()); // if it cannot form a block the rest goes to the leftovers

	//------------------------------------------------------------------------------
	// Insert pend inside main using jacobshtal numbers
	//------------------------------------------------------------------------------

	int		seqPendSize = static_cast<int>(pend.size() / pSeqSize); // numbers of sequence inside the Pend

	std::vector<int> js = jacobsthal(seqPendSize); // generate the jacobshtal numbers
	js.push_back(seqPendSize); // add the max size of sequence depending on the sequence size inside pend so it can loop reversal for the last number after jacobshtal

	for (std::vector<int>::iterator	it = js.begin() + 2; it < js.end(); it++)
	{
		if (*it == 1) { // rule 1: first block of pend is always inserted in the begin of main
			main.insert(main.begin(), pend.begin(), pend.begin() + pSeqSize);
			continue;
		}
		for (int i = *it; i != *(it - 1); i--)
		{
			std::vector<int> seqLast;
			for (size_t j = 0; j < main.size(); j += pSeqSize) // create a container with only the last number of a sequence to easily compare to
    			seqLast.push_back(main[j + pSeqSize - 1]);
			
			int	last = *(pend.begin() + (i * pSeqSize - 1)); // binary search the sequence index searching the optimal position using jacobshtal numbers
			std::vector<int>::iterator	pos = std::lower_bound(seqLast.begin(), seqLast.end(), last);

			int	dist = std::distance(seqLast.begin(), pos) * pSeqSize;

			main.insert(main.begin() + dist, pend.begin() + (i - 1) * pSeqSize, pend.begin() + i * pSeqSize); // insert the block to the corresponding placement
		}
	}
	main.insert(main.end(), left.begin(), left.end()); // insert leftovers numbers back to the main
	pContainer = main;
}

//#****************************************************************************#
//#                            OPERATOR OVERLOAD                               #
//#****************************************************************************#

PmergeMe&	PmergeMe::operator=(const PmergeMe& pCopy)
{
	(void)pCopy;
	return (*this);
}