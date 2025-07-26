/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:46:36 by achu              #+#    #+#             */
/*   Updated: 2025/07/26 17:45:23 by achu             ###   ########.fr       */
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
		Array&	operator=(const Array& pCopy);

		int	size(void);

		class OutOfBoundException : std::exception {
			public:
				const char*	what() const throw();
		}
};

#endif