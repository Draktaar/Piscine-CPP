/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:46:36 by achu              #+#    #+#             */
/*   Updated: 2025/08/04 09:22:15 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SPAN_H__
#define __SPAN_H__

#include <algorithm>
#include <vector>
#include <exception>

class Span
{
	private:

		std::vector<int>	_span;
		unsigned int		N;

	private:

		Span(void);

	public:

		Span(unsigned int pN);
		Span(const Span& pCopy);
		~Span(void);
		Span&	operator=(const Span& pCopy);

		void	addNumber(int pNum);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		class OverflowException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class EmptyException : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif