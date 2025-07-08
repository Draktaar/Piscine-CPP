/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:58:17 by achu              #+#    #+#             */
/*   Updated: 2025/07/08 16:59:20 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Form"), _target("Unknown"), _isSigned(false), _gradeSign(150), _gradeExec(150) {}
AForm::AForm(const AForm& pCopy) : _name(pCopy._name), _target(pCopy._target), _isSigned(pCopy._isSigned), _gradeSign(pCopy._gradeSign), _gradeExec(pCopy._gradeExec) {}
AForm::AForm(std::string pName, std::string pTarget, bool pIsSigned, int pGradeSign, int pGradeExec)
	: _name(pName), _target(pTarget), _isSigned(pIsSigned), _gradeSign(pGradeSign), _gradeExec(pGradeExec) {
	if (pGradeSign < 1 || pGradeExec < 1)
		throw (AForm::GradeTooHighExecption());
	else if (pGradeSign > 150 || pGradeExec > 150)
		throw (AForm::GradeTooLowExecption());
} 

AForm&	AForm::operator=(const AForm& pCopy)
{
	if (this != &pCopy)
	{
		_target = pCopy._target;
		_isSigned = pCopy._isSigned;
	}
	return (*this);
}
AForm::~AForm() {}

std::string		AForm::getName() const { return (_name); }
std::string		AForm::getTarget() const { return (_target); }
bool			AForm::getIsSigned() const { return (_isSigned); }
int				AForm::getGradeSign() const { return (_gradeSign); }
int				AForm::getGradeExec() const { return (_gradeExec); }

void		AForm::beSigned(const Bureaucrat& pBureaucrat)
{
	if (pBureaucrat.getGrade() > getGradeSign())
		throw (AForm::GradeTooLowExecption());
	_isSigned = true;
}

void		AForm::execute(const Bureaucrat& pBureaucrat) const
{
	if (_isSigned != true)
		return ;
	if (pBureaucrat.getGrade() > getGradeExec())
		throw (AForm::GradeTooLowExecption());
}

const char*		AForm::GradeTooHighExecption::what() const throw()
{
	return ("Grade too high !");
}

const char*		AForm::GradeTooLowExecption::what() const throw()
{
	return ("Grade too low !");
}

std::ostream&	operator<<(std::ostream& pOut, const AForm& pForm)
{
	pOut << "Form: " << pForm.getName() << "\n";
	pOut << "To: " << pForm.getTarget() << "\n";
	pOut << "Signed: " << pForm.getIsSigned() << "\n";
	pOut << "Grade required to sign: " << pForm.getGradeSign() << "\n";
	pOut << "Grade required to execute: " << pForm.getGradeExec() << "\n" << std::endl;
	return (pOut);
}