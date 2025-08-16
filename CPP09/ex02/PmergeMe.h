/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:00:21 by achu              #+#    #+#             */
/*   Updated: 2025/08/16 12:29:07 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PMERGERME_H__
#define __PMERGERME_H__

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <exception>

class PmergeMe
{
	public:

		PmergeMe(void);
		PmergeMe(const PmergeMe& pCopy);
		~PmergeMe(void);

		template <typename Iterator>
		static void		log(const Iterator& pBegin, const Iterator& pEnd, const std::string &pMessage = "");
	
		template <typename Container>
		static void		fordjohnson(Container& pContainer, int pSeqSize);

		PmergeMe&	operator=(const PmergeMe& pCopy);
};

#include "PmergeMe.tpp"

#endif