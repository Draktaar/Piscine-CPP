/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:19:50 by achu              #+#    #+#             */
/*   Updated: 2025/07/29 13:31:59 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCAVTRAP_H__
#define __SCAVTRAP_H__

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
	private:

		bool	_isGuardGate;

	public:

		ScavTrap(void);
		ScavTrap(std::string);
		ScavTrap(ScavTrap const& pCopy);
		~ScavTrap(void);

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	guardGate(void);

		ScavTrap &operator=(const ScavTrap &src);
};

#endif