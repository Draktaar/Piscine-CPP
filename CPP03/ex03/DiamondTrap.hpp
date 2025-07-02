/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 02:13:01 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 13:23:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	private:

		std::string		_name;

	public:

		DiamondTrap(void);
		DiamondTrap(std::string pName);
		DiamondTrap(DiamondTrap const& pCopy);
		~DiamondTrap(void);

		DiamondTrap&	operator=(DiamondTrap const& pCopy);

		void	attack(std::string const& target);
		void	whoAmI(void);
};
