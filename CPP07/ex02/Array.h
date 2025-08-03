/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:46:36 by achu              #+#    #+#             */
/*   Updated: 2025/08/03 02:12:53 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ITER_H__
#define __ITER_H__

#include <exception>

template <typename T>
class Array
{
	private:

		T*				_array;
		unsigned int	_size;

	public:

		Array(void);
		Array(unsigned int pLen);
		Array(const Array& pCopy);
		~Array(void);

		int	size(void) const;

		Array&	operator=(const Array& pCopy);
		T&		operator[](unsigned int pIdx);

		class OutOfRangeException : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#include "Array.tpp"

#endif