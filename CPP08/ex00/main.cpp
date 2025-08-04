/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:45:32 by achu              #+#    #+#             */
/*   Updated: 2025/08/04 08:56:45 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include "easyfind.h"
#include <iostream>
#include <vector>

int main(void)
{
	std::cout << RED << "///// TEST NOTHING /////" << WHITE << std::endl;
	std::vector<int> test0;
	int idx0 = easyfind(test0, 42);
	if (idx0 != -1)
		std::cout << "Found at index: " << idx0 << std::endl;
	else
		std::cout << "Not found." << std::endl;

	std::cout << RED << "///// TEST FOUND /////" << WHITE << std::endl;
	std::vector<int> test1;
	test1.push_back(3);
	test1.push_back(7);
	test1.push_back(42);

	int idx1 = easyfind(test1, 42);
	if (idx1 != -1)
		std::cout << "Found at index: " << idx1 << std::endl;
	else
		std::cout << "Not found." << std::endl;

	std::cout << RED << "///// TEST NOTFOUND /////" << WHITE << std::endl;
	std::vector<int> test2;
	test2.push_back(3);
	test2.push_back(7);
	int idx2 = easyfind(test2, 42);
	if (idx2 != -1)
		std::cout << "Found at index: " << idx2 << std::endl;
	else
		std::cout << "Not found." << std::endl;
	return (0);
}
