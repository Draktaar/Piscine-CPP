/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 01:01:03 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 13:06:56 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:

		static const int	defHealth;
		static const int	defEnergy;
		static const int	defAtkDmg;

	public:

		FragTrap(void);
		FragTrap(std::string);
		FragTrap(FragTrap const& pCopy);
		~FragTrap(void);

		void	highFiveGuys(void);

		FragTrap&	operator=(FragTrap const& pCopy);
};
