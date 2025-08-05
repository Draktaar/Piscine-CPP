/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:26 by achu              #+#    #+#             */
/*   Updated: 2025/08/05 13:45:32 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << RED << "///// TEST SIGN FORM /////" << WHITE << std::endl;

	try
	{
		Form* form = new Form("test", false, 42, 2);
		Bureaucrat	founder("Paul", 42);

		std::cout << *form << std::endl;
		founder.signForm(*form);
		delete form;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << RED << "///// TEST FAIL FORM /////" << WHITE << std::endl;

	try
	{
		Form* form = new Form("test", false, 42, -2);
		delete form;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << RED << "///// TEST FAIL SIGN FORM /////" << WHITE << std::endl;

	try
	{
		Form* form = new Form("test", false, 41, 2);
		Bureaucrat	founder("Paul", 42);

		std::cout << *form << std::endl;
		founder.signForm(*form);
		delete form;
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	return (0);
}
