/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 02:13:12 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 09:57:09 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Employee"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string pName, int pGrade) 
	: _name(pName), _grade(pGrade) {
	if (pGrade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else if (pGrade > 150)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& pCopy) : _name(pCopy._name), _grade(pCopy._grade) {}

Bureaucrat&		Bureaucrat::operator=(const Bureaucrat& pCopy)
{
	if (this != &pCopy)
		this->_grade = pCopy.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat() {}

std::string		Bureaucrat::getName() const { return (_name); }
int				Bureaucrat::getGrade() const { return (_grade); }

void		Bureaucrat::incGrade()
{
	if (_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	_grade--;
}

void		Bureaucrat::decGrade()
{
	if (_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	_grade++;
}

void		Bureaucrat::signForm(AForm& pForm) const
{
	try
	{
		pForm.beSigned(*this);
	}
	catch (const AForm::FormNotSignedException& e)
	{
		std::cout << getName() << " couldn't sign " << pForm.getName() << " because " << e.what() << std::endl;
	}
}

void		Bureaucrat::executeForm(const AForm& pForm) const
{
	try
	{
		pForm.beExecute(*this);
	}
	catch (const std::exception& e)
	{
		std::cout << getName() << " couldn't execute " << pForm.getName() << " because " << e.what() << std::endl;
	}
}

const char*		Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high !");
}

const char*		Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low !");
}

std::ostream&		operator<<(std::ostream& pOut, const Bureaucrat& pBureaucrat)
{
	pOut << pBureaucrat.getName() << ", bureaucrat grade " << pBureaucrat.getGrade() << "." << std::endl;
	return (pOut);
}