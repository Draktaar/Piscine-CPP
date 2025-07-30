/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:26 by achu              #+#    #+#             */
/*   Updated: 2025/07/30 18:59:02 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include "sources/MateriaSource.hpp"
#include "sources/Ice.hpp"
#include "sources/Cure.hpp"
#include "sources/Character.hpp"
#include <iostream>

int main()
{
	std::cout << RED << "///// TEST WIZARD CAST ICE BALL /////" << WHITE << std::endl;

	MateriaSource*	inv = new MateriaSource();
	inv->learnMateria(new Ice());

	AMateria*		iceBall = inv->createMateria("ice");
	Character*		wiz = new Character("Wizard");
	Character		goblin("Goblin");

	wiz->equip(iceBall);
	wiz->use(0, goblin);

	goblin.~Character();
	delete inv;
	delete wiz;

	std::cout << std::endl;

	std::cout << RED << "///// TEST SPELL SLOT FULL /////" << WHITE << std::endl;
	MateriaSource*	slots = new MateriaSource();
	slots->learnMateria(new Ice());
	slots->learnMateria(new Cure());
	slots->learnMateria(new Ice());
	slots->learnMateria(new Cure());
	slots->learnMateria(new Ice());

	MateriaSource* newSlots = new MateriaSource(*slots);
	newSlots->learnMateria(new Ice());

	delete newSlots;
	delete slots;

	std::cout << std::endl;

	std::cout << RED << "///// TEST INVENTORY /////" << WHITE << std::endl;
	Character*		demon = new Character("Demon");
	demon->equip(new Ice());
	demon->equip(new Ice());
	demon->equip(new Ice());
	demon->equip(new Ice());
	demon->equip(new Ice());

	Character*		mage = new Character(*demon);
	mage->equip(new Ice());
	mage->unequip(0);
	mage->equip(new Cure());
	mage->use(0, *mage);

	delete mage;
	delete demon;

	std::cout << std::endl;
	
	std::cout << RED << "///// SUBJECT TEST /////" << WHITE << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
