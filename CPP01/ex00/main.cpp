/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:05:48 by achu              #+#    #+#             */
/*   Updated: 2025/07/28 15:12:45 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Zombie.hpp"

Zombie*		newZombie(std::string name);
void		randomChump(std::string name);

int	main()
{
	Zombie	*hunter;
	Zombie	z;

	hunter = newZombie("Hunter");
	hunter->announce();
	randomChump("Jockey");
	delete hunter;
	return (0);
}
