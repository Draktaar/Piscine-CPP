/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 23:44:05 by achu              #+#    #+#             */
/*   Updated: 2025/08/07 13:38:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __RPN_H__
#define __RPN_H__

#include <string>
#include <stack>
#include <exception>

class RPN
{
	private:

		std::stack<int>		_stack;
		std::string			_expr;

	private:

		RPN(void);

		void	ops(char pOperator);
		void	checkExpr(void) const;

	public:

		RPN(const std::string& pExpr);
		RPN(const RPN& pCopy);
		~RPN(void);

		void	resolve(void);

		RPN&	operator=(const RPN& pCopy);

		class ZeroDivException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class OperandException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class ArithmeticException : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif