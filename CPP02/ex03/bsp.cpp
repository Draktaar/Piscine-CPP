/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 03:41:29 by achu              #+#    #+#             */
/*   Updated: 2025/07/01 21:11:58 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
	Fixed	v0x = c.getPointX() - a.getPointX();
	Fixed	v0y = c.getPointY() - a.getPointY();
	Fixed	v1x = b.getPointX() - a.getPointX();
	Fixed	v1y = b.getPointY() - a.getPointY();
	Fixed	v2x = point.getPointX() - a.getPointX();
	Fixed	v2y = point.getPointY() - a.getPointY();

	Fixed	dot00 = (v0x * v0x) + (v0y * v0y);
	Fixed	dot01 = v1x * v0x + v1y * v0y;
	Fixed	dot02 = v2x * v0x + v2y * v0y;
	Fixed	dot11 = v1x * v1x + v1y * v1y;
	Fixed	dot12 = v2x * v1x + v2y * v1y;

	Fixed	denom = dot11 * dot00 - dot01 * dot01;

	Fixed	u = (dot11 * dot02 - dot01 * dot12) / denom;
	Fixed	v = (dot00 * dot12 - dot01 * dot02) / denom;

	return (u.toFloat() >= 0.0f && v.toFloat() >= 0.0f && (u + v).toFloat() <= 1.0f);
}
