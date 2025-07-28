/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:37:16 by achu              #+#    #+#             */
/*   Updated: 2025/07/28 19:11:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int	main()
{
	Fixed			a;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                           INCREMENT & DECREMENT                            #" << std::endl;
	std::cout << "#****************************************************************************#\n" << std::endl;
	
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << a-- << std::endl;
	std::cout << a << std::endl;
	std::cout << --a << "\n" << std::endl;

	
	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  MAX ~ MIN                                 #" << std::endl;
	std::cout << "#****************************************************************************#\n" << std::endl;

	Fixed const		b(Fixed(5.05f) * Fixed(2));

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "Maximum compare to a and b: " << Fixed::max(a, b) << std::endl;
	std::cout << "Minimum compare to a and b: " << Fixed::min(a, b) << "\n" << std::endl;
	
	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ARITHMETICS                               #" << std::endl;
	std::cout << "#****************************************************************************#\n" << std::endl;
	
	std::cout << "Two Fixed constructor multiplied 5x5: "<< Fixed(5) * Fixed(5) << std::endl;

	Fixed	c(2.5f);
	Fixed	d(2);

	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "c + d = " << c + d << std::endl;
	std::cout << "c - d = " << c - d << std::endl;
	std::cout << "c * d = " << c * d << std::endl;
	std::cout << "c / d = " << c / d << "\n" << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  COMPARATORS                               #" << std::endl;
	std::cout << "#****************************************************************************#\n" << std::endl;

	Fixed	e(26.3f);
	Fixed	f(67.9f);

	if (e > f)
		std::cout << "e is bigger then f" << std::endl;
	else if (e < f)
		std::cout << "e is smaller then e" << std::endl;
	else if (e == f)
		std::cout << "e is equal to e" << std::endl;

	if (e != f)
		std::cout << "e is not equal to e" << std::endl;

	Fixed	g(674);
	Fixed	h(674);

	if (g >= h)
		std::cout << "g is bigger or equal to h" << std::endl;
	else if (g <= h)
		std::cout << "g is smaller or equal to h" << std::endl;
	
	return (0);
}
