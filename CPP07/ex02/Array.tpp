/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:22:40 by achu              #+#    #+#             */
/*   Updated: 2025/07/28 00:42:54 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"
#include <iostream>

template <typename T>
Array<T>::Array(void)
	: _array(nullptr), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int pLen)
	: _size(pLen)
{
	_array = new T[pLen];
}

template <typename T>
Array<T>::Array(const Array& pCopy)
	: _size(pCopy._size)
{
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++) {
		_array[i] = pCopy._array[i];
	}
}

template <typename T>
Array<T>::~Array(void)
{
	if (_array != nullptr)
		delete[] _array;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array &pCopy)
{
	if (this != &pCopy)
	{
		if (_array != nullptr)
			delete[] _array;
		
		if (pCopy._size != 0)
		{
			_size = pCopy._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_array[i] = pCopy._array[i];
			}
		}
	}
	return (*this);
}

template <typename T>
int	Array<T>::size(void) const
{
	return (_size);
}