/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:05:53 by achu              #+#    #+#             */
/*   Updated: 2025/07/08 15:49:50 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __FORM_H__
#define __FORM_H__

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	private:

		const std::string	_name;
		bool				_isSigned;
		const int			_gradeSign;
		const int			_gradeExec;
	
	public:

		Form();
		Form(const Form& pCopy);
		Form&	operator=(const Form& pCopy);
		~Form();

		std::string		getName() const;
		bool			getIsSigned() const;
		int				getGradeSign() const;
		int				getGradeExec() const;

		void	beSigned(const Bureaucrat& pBureaucrat);

		class GradeTooHighExecption : std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowExecption : std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream&	operator<<(std::ostream& pOut, const Form& pForm);

#endif