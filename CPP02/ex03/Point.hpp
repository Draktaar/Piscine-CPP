/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 03:41:22 by achu              #+#    #+#             */
/*   Updated: 2025/07/01 13:28:48 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __POINT_H__
#  define __POINT_H__

#include "Fixed.hpp"

class Point
{
	private:

		const Fixed 		_x;
		const Fixed 		_y;

	public:

		Point(void);
		Point(const float pX, const float pY);
		Point(const Point& pCopy);
		~Point(void);

		const Fixed&	getPointX(void) const;
		const Fixed&	getPointY(void) const;

		Point&	operator=(const Point& pCopy);	
};

#endif