/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:59:02 by achu              #+#    #+#             */
/*   Updated: 2025/07/08 16:53:20 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

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