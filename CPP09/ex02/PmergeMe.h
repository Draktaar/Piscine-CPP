/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:00:21 by achu              #+#    #+#             */
/*   Updated: 2025/08/07 17:41:25 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PMERGERME_H__
#define __PMERGERME_H__

#include <string>
#include <vector>
#include <list>
#include <exception>

class PmergeMe
{
	private:

		std::vector<int>		_vector;
		std::list<int>			_list;

	private:

		PmergeMe(void);

	public:

		PmergeMe(const std::string& pExpr);
		PmergeMe(const PmergeMe& pCopy);
		~PmergeMe(void);


		PmergeMe&	operator=(const PmergeMe& pCopy);

		class Exception : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif