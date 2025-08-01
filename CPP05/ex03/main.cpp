/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:26 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 22:48:18 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include "Intern.hpp"	
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));
	std::cout << RED << "///// TEST PRESIDENTIAL PARDON FORM /////" << WHITE << std::endl;

	AForm* presidentialForm = NULL;
	try
	{
		Bureaucrat	president("Zaphod Beeblebrox", 1);
		Bureaucrat	primeMinister("Eric", 9);
		Intern		nobody;

		presidentialForm = nobody.makeForm("Working Permit", "Bob");
		primeMinister.signForm(*presidentialForm);
		president.executeForm(*presidentialForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete presidentialForm;
	std::cout << std::endl;

	std::cout << RED << "///// TEST ROBOTOMY REQUEST FORM /////" << WHITE << std::endl;

	AForm* robotForm = NULL;
	try
	{
		Bureaucrat	founder("Paul", 42);
		Bureaucrat	worker("Bob", 76);
		Intern		nobody;

		robotForm = nobody.makeForm("Robotomy", "Newton");
		founder.signForm(*robotForm);
		founder.executeForm(*robotForm);
		std::cout << std::endl;
		founder.executeForm(*robotForm);
		std::cout << std::endl;
		founder.executeForm(*robotForm);
		std::cout << std::endl;
		worker.executeForm(*robotForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete robotForm;
	std::cout << std::endl;

	std::cout << RED << "///// TEST SHRUBERRY CREATION FORM /////" << WHITE << std::endl;

	AForm* shruberryForm = NULL;
	try
	{
		Bureaucrat	planter("George", 45);
		Bureaucrat	gardener("Vivien", 140);
		Intern		coffeeBoy;

		shruberryForm = coffeeBoy.makeForm("Shruberry", "Home");
		
		//Bureaucrat	anomaly("Vivien", 383); //this will thrown an exception grade too low !

		planter.signForm(*shruberryForm);
		planter.executeForm(*shruberryForm);
		gardener.executeForm(*shruberryForm);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete shruberryForm;
	
	return (0);
}
