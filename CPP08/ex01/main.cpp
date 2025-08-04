/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:45:32 by achu              #+#    #+#             */
/*   Updated: 2025/08/04 11:01:39 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include "Span.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::cout << RED << "///// TEST OVERFLOW /////" << WHITE << std::endl;

	try
	{
		Span test0 = Span(2);

		test0.addNumber(6);
		test0.addNumber(3);
		test0.addNumber(17);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << RED << "///// TEST NOTHING OR ONE /////" << WHITE << std::endl;

	try
	{
		Span test1 = Span(1);
		test1.addNumber(6);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << RED << "///// TEST NORMAL /////" << WHITE << std::endl;

	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	std::cout << RED << "///// TEST TEN THOUSAND /////" << WHITE << std::endl;

	try
	{
		Span tou = Span(20000);

		std::srand(static_cast<unsigned int>(std::time(NULL)));
		for (int i = 0; i < 20000; i++) {
			tou.addNumber(std::rand());
		}
		
		std::cout << "Shortest Span: " << tou.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << tou.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	return 0;

}
