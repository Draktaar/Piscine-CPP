/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:05:48 by achu              #+#    #+#             */
/*   Updated: 2025/08/05 13:44:06 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _isSigned(false), _gradeSign(150), _gradeExec(150) {}

Form::Form(const Form& pCopy) : _name(pCopy._name), _isSigned(pCopy._isSigned), _gradeSign(pCopy._gradeSign), _gradeExec(pCopy._gradeExec) {}

Form::Form(std::string pName, bool pIsSigned, int pGradeSign, int pGradeExec)
	: _name(pName),_isSigned(pIsSigned), _gradeSign(pGradeSign), _gradeExec(pGradeExec) {
	if (pGradeSign < 1 || pGradeExec < 1)
		throw (Form::GradeTooHighException());
	else if (pGradeSign > 150 || pGradeExec > 150)
		throw (Form::GradeTooLowException());
} 

Form&	Form::operator=(const Form& pCopy)
{
	if (this != &pCopy)
		_isSigned = pCopy._isSigned;
	return (*this);
}

Form::~Form() {}

std::string		Form::getName() const { return (_name); }
bool			Form::getIsSigned() const { return (_isSigned); }
int				Form::getGradeSign() const { return (_gradeSign); }
int				Form::getGradeExec() const { return (_gradeExec); }

void		Form::beSigned(const Bureaucrat& pBureaucrat)
{
	if (pBureaucrat.getGrade() > getGradeSign())
		throw (GradeTooLowException());
	_isSigned = true;
}

const char*		Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char*		Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

std::ostream&	operator<<(std::ostream& pOut, const Form& pForm)
{
	pOut << "Form: " << pForm.getName() << std::endl;
	pOut << "Signed: " << pForm.getIsSigned() << std::endl;
	pOut << "Grade required to sign: " << pForm.getGradeSign() << std::endl;
	pOut << "Grade required to execute: " << pForm.getGradeExec() << std::endl;
	return (pOut);
}

