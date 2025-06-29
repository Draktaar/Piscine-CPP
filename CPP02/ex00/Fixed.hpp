/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 21:37:58 by achu              #+#    #+#             */
/*   Updated: 2025/06/30 01:00:56 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __FIXED_H__
#  define __FIXED_H__

class Fixed
{
	private:

		int					_fpValue;
		static const int	_frclBits;

	public:

		Fixed(void);
		Fixed(const Fixed& pCopy);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		Fixed& operator=(const Fixed& pCopy);
};

#endif