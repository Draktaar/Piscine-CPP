/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:37:58 by achu              #+#    #+#             */
/*   Updated: 2025/06/30 17:02:37 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __FIXED_H__
#  define __FIXED_H__

#include <iostream>

class Fixed
{
	private:

		int					_fpValue;
		static const int	_frctBits;

	public:

		Fixed(void);
		Fixed(const Fixed& pCopy);
		Fixed(const int& pInt);
		Fixed(const float& pFloat);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed& 					operator=(const Fixed& pCopy);
		friend std::ostream&	operator<<(std::ostream& pOs, const Fixed& pFixed);
};

#endif