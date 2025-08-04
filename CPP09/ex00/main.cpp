/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:47:00 by achu              #+#    #+#             */
/*   Updated: 2025/08/05 00:43:14 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: ./btc <file>" << std::endl;
		return (1);
	}
	

	iFile.open(av[1]);
	if (!iFile.is_open()) {
		std::cerr << "Error: File cannot be opened" << std::endl;
		return (1);
	}

	std::split();

	iFile.close();
	return (0);
}
