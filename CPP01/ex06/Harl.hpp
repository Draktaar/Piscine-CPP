/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:00:56 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 17:50:01 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# ifndef __HARL_H__
#  define __HARL_H__

#include <string>

class Harl
{
	private:

		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);

	public:

		void	complain(std::string level);

};

#endif