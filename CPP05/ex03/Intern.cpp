/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:04:07 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 22:47:35 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& pCopy)
{
	(void)pCopy;
}

Intern&		Intern::operator=(const Intern& pCopy)
{
	(void)pCopy;
	return (*this);
}

Intern::~Intern() {}

AForm*	Intern::newPresidential(const std::string& pTarget) const
{
	return (new PresidentialPardonForm(pTarget));
}

AForm*	Intern::newRobotomy(const std::string& pTarget) const
{
	return (new RobotomyRequestForm(pTarget));
}

AForm*	Intern::newShrubbery(const std::string& pTarget) const
{
	return (new ShrubberyCreationForm(pTarget));
}

AForm*	Intern::makeForm(const std::string& pFormName, const std::string& pTarget) const
{
	std::string		forms[3] = {
		"Presidential",
		"Robotomy",
		"Shruberry",
	};

	AForm*	(Intern::*tab[3])(const std::string& pTarget) const = {
		&Intern::newPresidential,
		&Intern::newRobotomy,
		&Intern::newShrubbery,
	};

	for (size_t i = 0; i < 3; i++) {
		if (pFormName == forms[i]) {
			std::cout << "Intern created the " << forms[i] << " form" << std::endl;
			return ((this->*tab[i])(pTarget));
		}
	}
	throw FormNotFoundException();
	return (NULL);
}

const char*		Intern::FormNotFoundException::what() const throw()
{
	return ("Intern couldnt found the form you requested");
}