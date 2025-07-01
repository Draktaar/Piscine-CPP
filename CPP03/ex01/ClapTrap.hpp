/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:35 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 00:49:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ClapTrap
{
	protected:

		std::string		_name;
		int				_health;
		int				_energy;
		int				_atkDmg;

	public:

		ClapTrap(void);
		ClapTrap(std::string pName);
		ClapTrap(ClapTrap const& pCopy);
		~ClapTrap(void);

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap&	operator=(ClapTrap const& pCopy);
};