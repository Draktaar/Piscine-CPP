/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:35 by achu              #+#    #+#             */
/*   Updated: 2025/07/29 17:22:42 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __CLAPTRAP_H__
#define __CLAPTRAP_H__

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
		ClapTrap(std::string pName, int pHealth, int pEnergy, int pAtkDmg);
		ClapTrap(ClapTrap const& pCopy);
		~ClapTrap(void);

		std::string		getName(void) const;
		int				getHealth(void) const;
		int				getEnergy(void) const;
		int				getAtkDmg(void) const;

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap&	operator=(ClapTrap const& pCopy);
};

#endif