/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:47:00 by achu              #+#    #+#             */
/*   Updated: 2025/08/17 00:52:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>

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
	if (ac < 3) {
		std::cerr << "Usage: ./PmergeMe <number>" << std::endl;
		return (1);
	}

	for (int i = 1; i < ac; i++)
	{
		if (!checkArgv(av[i])) {
			std::cerr << "Error: Only Integer" << std::endl;
			return (1);
		}
	}

	try
	{
		std::vector<int>	_vector = parseArgs<std::vector <int> >(ac, av);
		std::deque<int>		_deque = parseArgs<std::deque <int> >(ac, av);

		PmergeMe::log(_vector.begin(), _vector.end(), "Before:  ");

		std::clock_t startVec = std::clock();
		PmergeMe::fordjohnson(_vector, 1);
		std::clock_t endVec = std::clock();

		std::clock_t startDeque = std::clock();
		PmergeMe::fordjohnson(_deque, 1);
		std::clock_t endDeque = std::clock();

		PmergeMe::log(_vector.begin(), _vector.end(), "After:   ");

		double durationVec = static_cast<double>(endVec - startVec) / 1000;
		std::cout << "Time to process a range of " << _vector.size()  << " elements with std::vector : " << durationVec << " µs" << std::endl;

		double durationDeque = static_cast<double>(endDeque - startDeque) / 1000;
		std::cout << "Time to process a range of " << _deque.size()  << " elements with std::deque : " << durationDeque << " µs" << std::endl << std::endl;

	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
