/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:37:16 by achu              #+#    #+#             */
/*   Updated: 2025/07/28 19:18:29 by achu             ###   ########.fr       */
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

	Point const	point0(1.85f, 3.29f); // barely outside the triangle
	Point const	point1(3.33f, 10.0f); // way outside the triangle
	Point const	point2(0.16f, 4.61f); // barely inside the triangle
	Point const	point3(0.0f, 3.0f); // on the edge of the triangle

	if (bsp(a, b, c, point0))
		std::cout << "Point 0 is inside the triangle" << std::endl;
	else
		std::cout << "Point 0 is not inside the triangle" << std::endl;

	if (bsp(a, b, c, point1))
		std::cout << "Point 1 is inside the triangle" << std::endl;
	else
		std::cout << "Point 1 is not inside the triangle" << std::endl;

	if (bsp(a, b, c, point2))
		std::cout << "Point 2 is inside the triangle" << std::endl;
	else
		std::cout << "Point 2 is not inside the triangle" << std::endl;

	if (bsp(a, b, c, point3))
		std::cout << "Point 3 is inside the triangle" << std::endl;
	else
		std::cout << "Point 3 is not inside the triangle" << std::endl;
	return (0);
}
