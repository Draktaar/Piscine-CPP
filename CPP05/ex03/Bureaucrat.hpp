/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 02:13:12 by achu              #+#    #+#             */
/*   Updated: 2025/07/08 17:01:09 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BUREAUCRAT_H__
#define __BUREAUCRAT_H__

#include <iostream>
#include <string>

class AForm;

class Bureaucrat
{
	private:

		const std::string	_name;
		int					_grade;

	public:

		Bureaucrat() {};
		Bureaucrat(const std::string pName, int pGrade);
		Bureaucrat(const Bureaucrat& pCopy);
		Bureaucrat&	operator=(const Bureaucrat& pCopy);
		~Bureaucrat();
		

		std::string		getName() const;
		int				getGrade() const;

		void			incGrade();
		void			decGrade();
		void			signForm(AForm& pForm) const;
		void			executeForm(const AForm& pForm) const;

		class	GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class	GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& pOut, const Bureaucrat& pBureaucrat);

#endif