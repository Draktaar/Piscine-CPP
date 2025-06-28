/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:06:25 by achu              #+#    #+#             */
/*   Updated: 2025/06/28 23:09:32 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

#pragma once
# ifndef __ZOMBIE_H__
#  define __ZOMBIE_H__

class Zombie
{
	private:

		std::string		_name;

	public:

		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);

		void	announce(void);
};

#endif