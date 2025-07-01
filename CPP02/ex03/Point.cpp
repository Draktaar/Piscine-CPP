/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 03:41:08 by achu              #+#    #+#             */
/*   Updated: 2025/07/01 13:29:30 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0) {}
Point::Point(const float pX, const float pY) : _x(pX), _y(pY) {}
Point::Point(const Point& pCopy) : _x(pCopy._x), _y(pCopy._y) {}
Point::~Point(void) {}

const Fixed&	Point::getPointX(void) const { return (_x); }
const Fixed&	Point::getPointY(void) const { return (_y); }