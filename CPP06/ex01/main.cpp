/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:54:39 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 23:53:16 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"
#include "Data.h"
#include <iostream>

int main(void)
{
	Data monster;
	monster.id = 3145;
	monster.name = "Behemoth";

	std::cout << "Monster ID: " << monster.id << std::endl;
	std::cout << "Monster Name: " << monster.name << std::endl;
	
	Serializer::uintptr_t adress = Serializer::serialize(&monster);
	std::cout << "Monster Adress: " << adress << std::endl;

	Data *creature = Serializer::deserialize(adress);
	std::cout << "Creature ID: " << creature->id << std::endl;
	std::cout << "Creature Name: " << creature->name << std::endl;
	std::cout << "Creature Adress: " << Serializer::serialize(creature) << std::endl;
	return (0);
}