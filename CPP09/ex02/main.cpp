/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:47:00 by achu              #+#    #+#             */
/*   Updated: 2025/08/07 17:43:45 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.h"
#include <iostream>

int main(int ac, char **av)
{
	if (ac < 2) {
		std::cerr << "Usage: ./PmergeMe <number>" << std::endl;
		return (1);
	}

	try
	{
		
	} catch(const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return (1);
	}
	
	return (0);
}
