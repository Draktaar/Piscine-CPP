/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:45:32 by achu              #+#    #+#             */
/*   Updated: 2025/08/03 02:19:32 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include "Array.h"
#include <iostream>

int main(void)
{
	std::cout << RED << "///// TEST EXCEPTION /////" << WHITE << std::endl;
	try
	{
		Array<int>	lArray;
		std::cout << lArray[7] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << RED << "///// TEST DEFAULT VALUE /////" << WHITE << std::endl;
	try
	{
		Array<int>	lArray(1);
		std::cout << lArray[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << RED << "///// TEST COPY /////" << WHITE << std::endl;
	try
	{
		Array<int>	lArray(10);
		for (size_t i = 0; i < 10; i++)
			lArray[i] = i;

		Array<int> lCopy = lArray;
		for (size_t i = 0; i < 10; i++)
			std::cout << lCopy[i] << " ";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << RED << "///// TEST FUNCTION SIZE() /////" << WHITE << std::endl;
	try
	{
		Array<int>	lArray(10);

		std::cout << lArray.size() << std::endl;
		std::cout << lArray.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
