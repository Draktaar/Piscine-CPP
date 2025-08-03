/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 17:22:40 by achu              #+#    #+#             */
/*   Updated: 2025/08/03 02:08:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.h"
#include <iostream>

template <typename T>
Array<T>::Array(void)
	: _array(NULL), _size(0)
{}

template <typename T>
Array<T>::Array(unsigned int pLen)
	: _size(pLen)
{
	_array = new T[pLen];
	for (unsigned int i = 0; i < pLen; i++)
		_array[i] = 0;
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
	if (_array != NULL)
		delete[] _array;
}

template <typename T>
int	Array<T>::size(void) const
{
	return (_size);
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array &pCopy)
{
	if (this != &pCopy)
	{
		if (_array != NULL)
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
T&		Array<T>::operator[](unsigned int pIdx)
{
	if (pIdx >= _size)
		throw typename Array<T>::OutOfRangeException();
	return (_array[pIdx]);
}

template <typename T>
const char*	Array<T>::OutOfRangeException::what() const throw()
{
	return ("Error: Out of range !");
}