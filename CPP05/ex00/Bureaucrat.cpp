/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 02:13:12 by achu              #+#    #+#             */
/*   Updated: 2025/07/31 15:01:32 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Employee"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string& pName, int pGrade) 
	: _name(pName), _grade(pGrade) {
	if (pGrade < 1)
		throw (GradeTooHighException());
	else if (pGrade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(const Bureaucrat& pCopy)
	: _name(pCopy._name), _grade(pCopy._grade)
{}

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
		throw (GradeTooHighException());
	_grade--;
}

void		Bureaucrat::decGrade()
{
	if (_grade + 1 > 150)
		throw (GradeTooLowException());
	_grade++;
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
	pOut << pBureaucrat.getName() << ", bureaucrat grade " << pBureaucrat.getGrade() << ".";
	return (pOut);
}