/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:26 by achu              #+#    #+#             */
/*   Updated: 2025/07/29 13:28:05 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int	main()
{
	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                     COLLOSEUM BATTLE OF THE CLAPTRAP                       #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	ClapTrap	clap("CLP4P-TP");
	ScavTrap	scav("SC4V-TP");
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 1                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	clap.attack(scav.getName());
	scav.takeDamage(clap.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 2                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	scav.guardGate();
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 3                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	clap.attack(scav.getName());
	scav.takeDamage(clap.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 4                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	scav.attack(clap.getName());
	scav.guardGate();
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 5                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	clap.attack(scav.getName());
	scav.takeDamage(clap.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 6                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	scav.attack(clap.getName());
	clap.takeDamage(scav.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                SCAVTRAP WON                                #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;
	return (0);
}