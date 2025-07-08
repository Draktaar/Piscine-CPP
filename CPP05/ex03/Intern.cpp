/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:04:07 by achu              #+#    #+#             */
/*   Updated: 2025/07/08 19:27:39 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

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
		"Shrubbery",
	};

	AForm*	(Intern::*tab[3])(const std::string& pTarget) const = {
		&Intern::newPresidential,
		&Intern::newRobotomy,
		&Intern::newShrubbery,
	};

	for (size_t i = 0; i < 3; i++) {
		if (pFormName == forms[i])
			return ((this->*tab[i])(pTarget));
	}
	std::cerr << "The Intern didn't found the form you are looking for, are you sure you search the write one ?" << std::endl;
	return (NULL);
}