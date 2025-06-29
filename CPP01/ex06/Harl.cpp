/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 17:00:50 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 20:08:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#include <iostream>

void	Harl::debug(void) {
	std::cout << "[DEBUG]:\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
	std::cout << "I really do!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "[INFO]:\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\n";
	std::cout << "You didn't put enough bacon in my burger!\n";
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "[WARNING]:\n";
	std::cout << "I think I deserve to have some extra bacon for free.\n";
	std::cout << "I've been coming for years, whereas you started working here just last month." << std::endl;
}

void	Harl::error(void) {
	std::cout << "[ERROR]:\n";
	std::cout << "This is unacceptable!\n";
	std::cout << "I want to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	std::string	alerts[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };

	void	(Harl::*cpl[])(void) = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	
	for (int i = 0; i < 4; i++) {
		if (level == alerts[i])
		{
			switch (i)
			{
			case 0:
				(this->*cpl[0])();
				std::cout << "\n";
				/* fall through */
			case 1:
				(this->*cpl[1])();
				std::cout << "\n";
				/* fall through */
			case 2:
				(this->*cpl[2])();
				std::cout << "\n";
				/* fall through */
			case 3:
				(this->*cpl[3])();
				std::cout << "\n";
				break;
			}
			return;
		}
	}
	std::cout << "[Probably complaining about insignificant problems]" << std::endl;
}
