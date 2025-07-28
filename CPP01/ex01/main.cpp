/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:05:48 by achu              #+#    #+#             */
/*   Updated: 2025/07/28 15:15:19 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main()
{
	Zombie	*horde;

	horde = zombieHorde(10, "Zombie");
	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
