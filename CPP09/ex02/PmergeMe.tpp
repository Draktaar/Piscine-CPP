/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 12:27:13 by achu              #+#    #+#             */
/*   Updated: 2025/08/16 12:31:17 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"

template <typename Container>
static Container	jacobsthal(int pN)
{
	Container	seq;

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

template <typename Container>
void	PmergeMe::fordjohnson(Container& pContainer, int pSeqSize)
{
	//------------------------------------------------------------------------------
	// Merge swap pairs of pairs of pairs
	//------------------------------------------------------------------------------

	int		pairSize = pSeqSize * 2;
	int		maxPair = static_cast<int>(pContainer.size() / pairSize);

	if (maxPair <= 0) //if this recursion cannot create another pair, end the recursion
		return ;

	typename Container::iterator	start = pContainer.begin();
	typename Container::iterator	end = pContainer.begin() + (pairSize * maxPair);

	for (typename Container::iterator it = start; it < end; it += pairSize) // swap the block if the first block is bigger than the second block in a pair to ensure order of sequence inside a block
	{
		if (*(it + pSeqSize - 1) > *(it + pairSize - 1))
			std::swap_ranges(it, it + pSeqSize, it + pSeqSize);
	}

	fordjohnson(pContainer, pSeqSize * 2); // recursively call merge func until not pair can match

	//------------------------------------------------------------------------------
	// Initialization for the main, pend and leftovers
	//------------------------------------------------------------------------------

	Container	main;
	Container	pend;
	Container	left;

	bool	isOdd = static_cast<int>((pContainer.size() / pSeqSize)) % 2 == 1;
	typename Container::iterator	newEnd = end + (isOdd * pSeqSize);

	bool	isPend = true;
	for (typename Container::iterator it = start; it < newEnd; it += pSeqSize) // insert each block to a container, starting with pend then alternating with main
	{
		isPend ? pend.insert(pend.end(), it, it + pSeqSize) : main.insert(main.end(), it, it + pSeqSize);
		isPend = !isPend;
	}
	left.insert(left.end(), newEnd, pContainer.end()); // if it cannot form a block the rest goes to the leftovers

	//------------------------------------------------------------------------------
	// Insert pend inside main using jacobshtal numbers
	//------------------------------------------------------------------------------

	int		seqPendSize = static_cast<int>(pend.size() / pSeqSize); // numbers of sequence inside the Pend

	Container js = jacobsthal<Container>(seqPendSize); // generate the jacobshtal numbers
	js.push_back(seqPendSize); // add the max size of sequence depending on the sequence size inside pend so it can loop reversal for the last number after jacobshtal

	for (typename Container::iterator	it = js.begin() + 2; it < js.end(); it++)
	{
		if (*it == 1) { // rule 1: first block of pend is always inserted in the begin of main
			main.insert(main.begin(), pend.begin(), pend.begin() + pSeqSize);
			continue;
		}
		for (int i = *it; i != *(it - 1); i--)
		{
			Container seqLast;
			for (size_t j = 0; j < main.size(); j += pSeqSize) // create a container with only the last number of a sequence to easily compare to
    			seqLast.push_back(main[j + pSeqSize - 1]);
			
			int	last = *(pend.begin() + (i * pSeqSize - 1)); // binary search the sequence index searching the optimal position using jacobshtal numbers
			typename Container::iterator	pos = std::lower_bound(seqLast.begin(), seqLast.end(), last);

			int	dist = std::distance(seqLast.begin(), pos) * pSeqSize;

			main.insert(main.begin() + dist, pend.begin() + (i - 1) * pSeqSize, pend.begin() + i * pSeqSize); // insert the block to the corresponding placement
		}
	}
	main.insert(main.end(), left.begin(), left.end()); // insert leftovers numbers back to the main
	pContainer = main;
}

template <typename Iterator>
inline void		PmergeMe::log(const Iterator& pBegin, const Iterator& pEnd, const std::string &pMessage)
{
	std::cout << pMessage;
	for (Iterator it = pBegin; it != pEnd; it++) {
		if (it != pBegin && it != pEnd)
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}
