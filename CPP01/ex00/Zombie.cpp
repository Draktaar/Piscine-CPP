/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:06:22 by achu              #+#    #+#             */
/*   Updated: 2025/07/28 15:09:46 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie::Zombie(void) : _name("Zombie"){}
Zombie::Zombie(std::string name) : _name(name) {}
Zombie::~Zombie(void)
{
	std::cout << "Bill killed " << _name << "\n";
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ...\n";
}