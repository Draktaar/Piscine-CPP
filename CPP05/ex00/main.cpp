/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:26 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 09:24:47 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
	std::cout << RED << "///// TEST GRADE TOO HIGH /////" << WHITE << std::endl;

	Bureaucrat	jacques("Jacques", 2);
	try
	{
		std::cout << jacques << std::endl;
		jacques.incGrade();
		std::cout << jacques << std::endl;
		jacques.incGrade();
		std::cout << jacques << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what()<< std::endl;
	}
	std::cout << jacques << std::endl << std::endl;


	std::cout << RED << "///// TEST GRADE TOO LOW /////" << WHITE << std::endl;

	Bureaucrat	kevin("Kevin", 149);
	try
	{
		std::cout << kevin << std::endl;
		kevin.decGrade();
		std::cout << kevin << std::endl;
		kevin.decGrade();
		std::cout << kevin << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << kevin << std::endl << std::endl;

	std::cout << RED << "///// TEST GRADE OUTOFRANGE /////" << WHITE << std::endl;

	try
	{
		Bureaucrat	olivier("Olivier", 174);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
	return (0);
}
