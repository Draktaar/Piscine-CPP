/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:45:32 by achu              #+#    #+#             */
/*   Updated: 2025/08/03 00:52:31 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.h"
#include <iostream>

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
	
	return (0);
}
