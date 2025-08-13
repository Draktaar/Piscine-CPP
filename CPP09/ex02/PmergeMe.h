/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:00:21 by achu              #+#    #+#             */
/*   Updated: 2025/08/13 20:57:18 by achu             ###   ########.fr       */
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

		

	public:

		PmergeMe(void);
		PmergeMe(const PmergeMe& pCopy);
		~PmergeMe(void);

		static void		logVector(const std::vector<int>& pContainer, const std::string& pMessage);

		static void		mergeVector(std::vector<int>& pContainer, int pLVL);

		static void		insertVector(std::vector<int>& pMain, std::vector<int>& pPend, std::vector<int>& pLeft, std::vector<int>& pContainer, const int& pSeqSize);

		PmergeMe&	operator=(const PmergeMe& pCopy);

		class InvalidException : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif