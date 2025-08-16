/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:47:00 by achu              #+#    #+#             */
/*   Updated: 2025/08/16 12:32:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"
#include <iostream>
#include <cstdlib>

template <typename Container>
static Container	parseArgs(int pAc, const char** pAv)
{
	Container	seq;
	int			nbr;

	for (int i = 1; i < pAc; i++)
	{
		nbr = std::atoi(pAv[i]);
		seq.push_back(nbr);
	}
	return (seq);
}

static bool		checkArgv(std::string pAv)
{
	std::string		lDigit = "0123456789";
	return (pAv.find_first_not_of(lDigit) == std::string::npos);
}

int main(int ac, const char **av)
{
	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe <number>" << std::endl;
		return (1);
	}

	for (int i = 1; i < ac; i++)
	{
		if (!checkArgv(av[i])) {
			std::cerr << av[i] << std::endl;
			return (1);
		}
	}

	try
	{
		std::vector<int>	_vector = parseArgs<std::vector <int> >(ac, av);
		std::deque<int>		_deque = parseArgs<std::deque <int> >(ac, av);

		PmergeMe::log(_vector.begin(), _vector.end(), "Before: ");
		PmergeMe::log(_deque.begin(), _deque.end(), "Before: ");
		PmergeMe::fordjohnson(_vector, 1);
		PmergeMe::fordjohnson(_deque, 1);
		PmergeMe::log(_vector.begin(), _vector.end(), "After: ");
		PmergeMe::log(_deque.begin(), _deque.end(), "After: ");

	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
