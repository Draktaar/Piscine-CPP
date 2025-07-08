/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:59:44 by achu              #+#    #+#             */
/*   Updated: 2025/07/08 19:20:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

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