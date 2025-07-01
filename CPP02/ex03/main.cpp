/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:37:16 by achu              #+#    #+#             */
/*   Updated: 2025/07/01 21:11:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(const Point& a, const Point& b, const Point& c, const Point& point);

int	main()
{
	Point const	a(0.0f, 0.0f);
	Point const	b(0.0f, 5.0f);
	Point const	c(5.0f, 0.0f);

	Point const	point0(1.42f, 3.29f);
	Point const	point1(3.33f, 10.0f);

	if (bsp(a, b, c, point0))
		std::cout << "Point 0 is inside the triangle" << std::endl;
	if (bsp(a, b, c, point1))
		std::cout << "Point 1 is inside the triangle" << std::endl;
	return (0);
}
