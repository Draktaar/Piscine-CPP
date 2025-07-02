/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:19:50 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 01:41:02 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		void	guardGate(void);

		ScavTrap &operator=(const ScavTrap &src);
};
