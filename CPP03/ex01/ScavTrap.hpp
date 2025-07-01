/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 23:19:50 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 00:55:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
	private:

		void	guardGate(void);

	public:

		ScavTrap(void);
		ScavTrap(std::string);
		~ScavTrap(void);
};
