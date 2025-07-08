/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:05:48 by achu              #+#    #+#             */
/*   Updated: 2025/07/08 15:49:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Form"), _isSigned(false), _gradeSign(150), _gradeExec(150) {}
Form::Form(const Form& pCopy) : _name(pCopy._name), _isSigned(pCopy._isSigned), _gradeSign(pCopy._gradeSign), _gradeExec(pCopy._gradeExec) {}
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
		throw (GradeTooLowExecption());
	_isSigned = true;
}

const char*		Form::GradeTooHighExecption::what() const throw()
{
	return ("Grade too high !");
}

const char*		Form::GradeTooLowExecption::what() const throw()
{
	return ("Grade too low !");
}

std::ostream&	operator<<(std::ostream& pOut, const Form& pForm)
{
	pOut << "Form: " << pForm.getName() << "\n";
	pOut << "Signed: " << pForm.getIsSigned() << "\n";
	pOut << "Grade required to sign: " << pForm.getGradeSign() << "\n";
	pOut << "Grade required to execute: " << pForm.getGradeExec() << "\n" << std::endl;
	return (pOut);
}

