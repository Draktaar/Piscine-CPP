/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:46:36 by achu              #+#    #+#             */
/*   Updated: 2025/07/28 01:12:49 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __MUTANT_STACK_H__
#define __MUTANT_STACK_H__

#include <deque>
#include <stack>
#include <iterator>

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
	public:

	typedef typename Container::iterator		iterator;
	typedef typename Container::const_iterator	const_iterator;
	
	public:

		MutantStack(void) : std::stack<T, Container>() {};
		MutantStack(const MutantStack& pCopy) : std::stack<T, Container>(pCopy) {};
		~MutantStack(void) {};
		MutantStack&	operator=(const MutantStack& pCopy)
		{
			if (this != &pCopy)
				std::stack<T, Container>::operator=(pCopy);
			return (*this);
		}

		iterator	begin() { return (this->c.begin()); }
		iterator	end() { return (this->c.end()); }

		const_iterator	begin() const { return (this->c.begin()); }
		const_iterator	end() const { return (this->c.end()); }
};

#endif