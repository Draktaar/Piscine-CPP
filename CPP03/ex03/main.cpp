/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:26 by achu              #+#    #+#             */
/*   Updated: 2025/07/29 17:49:25 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>

int	main()
{
	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                             SHOWCASE DI4MOND-TP                            #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	ClapTrap		clap("DUMMY CL4P-TP");
	DiamondTrap		diam("DI4M0ND-TP");
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                               STATS CHECK                                  #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	std::cout << "     " << " MATRICULA: " << diam.getNewName();
	std::cout << "     " << RED << " HP: " << WHITE << " " << diam.getHealth();
	std::cout << "     " << YELLOW << " ENER: " << WHITE << " " << diam.getEnergy();
	std::cout << "     " << BLUE << " ATK: " << WHITE << " " << diam.getAtkDmg();
	std::cout << std::endl << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                               ATTACK TEST                                  #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	diam.attack(clap.getName());
	clap.takeDamage(diam.getAtkDmg());
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                             INHERITED POWER                                #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	diam.highFiveGuys();
	diam.guardGate();
	diam.guardGate();
	std::cout << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#                            EXISTENTIAL CRISIS                              #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;

	diam.whoAmI();	
	std::cout << std::endl << std::endl;

	std::cout << "#****************************************************************************#" << std::endl;
	std::cout << "#             END OF THE SHOW NOW GET RID OF ALL THIS SCR4P                  #" << std::endl;
	std::cout << "#****************************************************************************#" << std::endl;
	return (0);
}