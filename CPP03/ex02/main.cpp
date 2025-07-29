/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:26 by achu              #+#    #+#             */
/*   Updated: 2025/07/29 17:04:25 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                     COLLOSEUM BATTLE OF THE CLAPTRAP                       #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	FragTrap	frag("FR4G-TP");
	ScavTrap	scav("SC4V-TP");
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 1                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	frag.highFiveGuys();
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 2                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	scav.attack(frag.getName());
	frag.takeDamage(scav.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 3                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	frag.attack(scav.getName());
	scav.takeDamage(frag.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 4                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	scav.guardGate();
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 5                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	frag.attack(scav.getName());
	scav.takeDamage(frag.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 6                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	scav.beRepaired(20);
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 7                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	frag.attack(scav.getName());
	scav.takeDamage(frag.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 8                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	scav.guardGate();
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 9                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	frag.attack(scav.getName());
	scav.takeDamage(frag.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 9                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	scav.attack(scav.getName());
	std::cout << std::endl;

	
	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                  ROUND 9                                   #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	frag.attack(scav.getName());
	scav.takeDamage(frag.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                                FRAGTRAP WON                                #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;
	return (0);
}