/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:59:56 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 09:04:37 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("Presidential Pardon Form", "Unknown", false, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(std::string pTarget)
	: AForm("Presidential Pardon Form", pTarget, false, 25, 5)
{}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& pCopy)
	: AForm(pCopy.getName(), pCopy.getTarget(), pCopy.getIsSigned(), 25, 5)
{}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm&		PresidentialPardonForm::operator=(const PresidentialPardonForm& pCopy)
{
	if (this != &pCopy) {
		AForm::operator=(pCopy);
	}
	return (*this);
}

void	PresidentialPardonForm::paperWork(void) const
{
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}