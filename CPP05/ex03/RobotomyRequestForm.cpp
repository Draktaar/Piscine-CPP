/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:59:44 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 14:58:39 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Robotomy Request Form", "Unknown", false, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(std::string pTarget)
	: AForm("Robotomy Request Form", pTarget, false, 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& pCopy)
	: AForm(pCopy.getName(), pCopy.getTarget(), pCopy.getIsSigned(), 72, 45) {
}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm&		RobotomyRequestForm::operator=(const RobotomyRequestForm& pCopy)
{
	if (this != &pCopy) {
		AForm::operator=(pCopy);
	}
	return (*this);
}

void	RobotomyRequestForm::paperWork(void) const
{
	std::cout << "*drrrrrriiiiiiiillliiiiing*" << std::endl;
	if (std::rand() % 2 == 0)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "The robotomy failed on " << this->getTarget() << "." << std::endl;
}