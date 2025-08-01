/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:57:40 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 09:53:44 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __AFORM_H__
#define __AFORM_H__

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
	private:

		const std::string	_name;
		std::string			_target;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExec;

	protected:

		AForm();
		AForm(const AForm& pCopy);
		AForm(std::string pName, std::string pTarget, bool pIsSigned, int pGradeSign, int pGradeExec);
		AForm&	operator=(const AForm& pCopy);
	
		virtual void	paperWork(void) const = 0;
	
	public:

		virtual ~AForm();

		std::string		getName() const;
		std::string		getTarget() const;
		bool			getIsSigned() const;
		int				getGradeSign() const;
		int				getGradeExecute() const;

		void	beSigned(const Bureaucrat& pBureaucrat);
		void	beExecute(const Bureaucrat& pBureaucrat) const;
		
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public  std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& pOut, const AForm& pForm);


#endif