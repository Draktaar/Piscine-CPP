/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:45:32 by achu              #+#    #+#             */
/*   Updated: 2025/08/08 11:46:12 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"
#include <iostream>

class Awesome
{
	public:
		Awesome( void): _n( 42) { return; }
		int get( void) const {return this->_n; }

	private:
		int	_n;
};
std::ostream& operator<<( std::ostream & o, Awesome const & rhs) { o << rhs.get(); return o; }

template< typename T>
void print( T const & x)
{
	std::cout << x << std::endl;
	return;
}

template <typename T>
void	printNbr(const T& pNbr)
{
	std::cout << pNbr << std::endl;
}

template <typename T>
void	decrement(T& pNbr)
{
	pNbr -= 10;
}

int main(void)
{
	int	number[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	std::cout << "/// Before ///" << std::endl;
	iter(number, 10, printNbr<int>);
	iter(number, 5, decrement<int>);

	std::cout << "/// After ///" << std::endl;
	iter(number, 10, printNbr<int>);
	

	int tab[] = { 0, 1, 2, 3, 4 };

	Awesome tab2[5];

	iter(tab, 5, print<int>); iter(tab2, 5, print<int>);

	return (0);
}
