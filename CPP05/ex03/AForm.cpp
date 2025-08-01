/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:58:17 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 15:03:18 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("Form"), _target("Unknown"), _isSigned(false), _gradeSign(150), _gradeExec(150) {}

AForm::AForm(const AForm& pCopy) : _name(pCopy._name), _target(pCopy._target), _isSigned(pCopy._isSigned), _gradeSign(pCopy._gradeSign), _gradeExec(pCopy._gradeExec) {}

AForm::AForm(std::string pName, std::string pTarget, bool pIsSigned, int pGradeSign, int pGradeExec)
	: _name(pName), _target(pTarget), _isSigned(pIsSigned), _gradeSign(pGradeSign), _gradeExec(pGradeExec) {
	if (pGradeSign < 1 || pGradeExec < 1)
		throw (AForm::GradeTooHighException());
	else if (pGradeSign > 150 || pGradeExec > 150)
		throw (AForm::GradeTooLowException());
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

std::string		AForm::getName() const		{ return (_name); }
std::string		AForm::getTarget() const	{ return (_target); }
bool			AForm::getIsSigned() const	{ return (_isSigned); }
int				AForm::getGradeSign() const	{ return (_gradeSign); }
int				AForm::getGradeExecute() const	{ return (_gradeExec); }

void		AForm::beSigned(const Bureaucrat& pBureaucrat)
{
	if (pBureaucrat.getGrade() > getGradeSign())
		throw (AForm::GradeTooLowException());
	_isSigned = true;
	std::cout << pBureaucrat.getName() << " signed " << this->getName() << std::endl;
}

void		AForm::beExecute(const Bureaucrat& pBureaucrat) const
{
	if (pBureaucrat.getGrade() > getGradeExecute())
		throw AForm::GradeTooLowException();
	if (!getIsSigned())
		throw AForm::FormNotSignedException();
	std::cout << pBureaucrat.getName() << " executed " << this->getName() << std::endl;
	paperWork();
}

const char*		AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed !");
}

const char*		AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char*		AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

std::ostream&	operator<<(std::ostream& pOut, const AForm& pForm)
{
	pOut << "Form: " << pForm.getName() << "\n";
	pOut << "To: " << pForm.getTarget() << "\n";
	pOut << "Signed: " << pForm.getIsSigned() << "\n";
	pOut << "Grade required to sign: " << pForm.getGradeSign() << "\n";
	pOut << "Grade required to execute: " << pForm.getGradeExecute() << "\n" << std::endl;
	return (pOut);
}