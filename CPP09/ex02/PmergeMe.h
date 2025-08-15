/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:00:21 by achu              #+#    #+#             */
/*   Updated: 2025/08/15 13:02:49 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PMERGERME_H__
#define __PMERGERME_H__

#include <iostream>
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

		template <typename Iterator>
		static void		log(const Iterator& pBegin, const Iterator& pEnd, const std::string &pMessage = "");
	
		static void		fordjohnsonVector(std::vector<int>& pContainer, int pLVL);
		static void		fordjohnsonList(std::list<int>& pContainer, int pLVL);

		PmergeMe&	operator=(const PmergeMe& pCopy);
};

template <typename Iterator>
inline void		PmergeMe::log(const Iterator& pBegin, const Iterator& pEnd, const std::string &pMessage)
{
	std::cout << pMessage;
	for (Iterator it = pBegin; it != pEnd; it++) {
		if (it != pBegin && it != pEnd)
			std::cout << " ";
		std::cout << *it;
	}
	std::cout << std::endl;
}

#endif