/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:59:02 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 15:06:35 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>

static const char tree[] = 
"       _-_\n"
"    /~~   ~~\\\n"
" /~~         ~~\\\n"
"{               }\n"
" \\  _-     -_  /\n"
"   ~  \\\\ //  ~\n"
"_- -   | | _- _\n"
"  _ -  | |   -_\n"
"      // \\\\\n";

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("Shrubbery Creation Form", "Unknown", false, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string pTarget)
	: AForm("Shrubbery Creation Form", pTarget, false, 145, 137) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& pCopy)
	: AForm(pCopy.getName(), pCopy.getTarget(), pCopy.getIsSigned(), 145, 137) {
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm&		ShrubberyCreationForm::operator=(const ShrubberyCreationForm& pCopy)
{
	if (this != &pCopy) {
		AForm::operator=(pCopy);
	}
	return (*this);
}

void	ShrubberyCreationForm::paperWork(void) const
{
	std::ofstream	oFile((getTarget() + "_shruberry").c_str());
	if (oFile)
		oFile << tree;
}