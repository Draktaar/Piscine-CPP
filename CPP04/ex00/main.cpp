/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:26 by achu              #+#    #+#             */
/*   Updated: 2025/07/02 17:47:26 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int	main()
{
	std::cout << RED << "///// TEST AVEC 2 ANIMALS /////" << WHITE << std::endl;

	Animal	a0;
	Animal	a1(a0);

	a0.makeSound();
	a1.makeSound();
	std::cout << std::endl;

	std::cout << RED << "///// TEST AVEC 2 CAT /////" << WHITE << std::endl;

	Cat		c0;
	Cat		c1(c0);

	c0.makeSound();
	c1.makeSound();
	std::cout << std::endl;

	std::cout << RED << "///// TEST AVEC 2 DOG /////" << WHITE << std::endl;

	Dog		d0;
	Dog		d1(d0);

	d0.makeSound();
	d1.makeSound();
	std::cout << std::endl;

	std::cout << RED << "///// TEST AVEC 2 WRONG ANIMALS /////" << WHITE << std::endl;

	WrongAnimal	wa0;
	WrongAnimal	wa1(wa0);

	wa0.makeSound();
	wa1.makeSound();
	std::cout << std::endl;

	std::cout << RED << "///// TEST AVEC 2 WRONG CAT /////" << WHITE << std::endl;

	WrongCat		wc0;
	WrongCat		wc1(wc0);

	wc0.makeSound();
	wc1.makeSound();
	std::cout << std::endl;

	std::cout << RED << "///// TEST DU SUJET /////" << WHITE << std::endl;

	const Animal*	meta = new Animal();
	const Animal*	i = new Cat();
	const Animal*	j = new Dog();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;

	const WrongAnimal*	wrong = new WrongAnimal();
	const WrongAnimal*	cat = new WrongCat();

	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	wrong->makeSound();

	delete wrong;
	delete cat;
	
	return 0;
}