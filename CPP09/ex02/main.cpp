/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:47:00 by achu              #+#    #+#             */
/*   Updated: 2025/08/13 21:47:32 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"
#include <iostream>
#include <cstdlib>

static bool		checkArgv(std::string pAv)
{
	std::string		lDigit = "0123456789";
	return (pAv.find_first_not_of(lDigit) == std::string::npos);
}

static std::vector<int>	parseVector(int pAc, const char** pAv)
{
	std::vector<int>	seq;
	int					lValue;

	for (int i = 1; i < pAc; i++)
	{
		lValue = std::atoi(pAv[i]);
		seq.push_back(lValue);
	}
	return (seq);
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
		std::vector<int>	_vector = parseVector(ac, av);
		//PmergeMe::logVector(_vector, "Before: ");
		PmergeMe::mergeVector(_vector, 1);

	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
