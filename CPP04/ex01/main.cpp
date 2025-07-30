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
	std::cout << RED << "///// TEST AVEC 100 ANIMALS /////" << WHITE << std::endl;
	Animal*	cage[100];

	for (int i = 0; i < 50; i ++) {
		cage[i] = new Dog();
	}
	for (int i = 50; i < 100; i++) {
		cage[i] = new Cat();
	}
	
	for (int i = 0; i < 100; i++) {
		delete cage[i];
	}

	std::cout << RED << "///// TEST AVEC BRAIN /////" << WHITE << std::endl;
	Dog* woof = new Dog();

	woof->fillIdeas();
	woof->getIdeas(-1);
	woof->getIdeas(0);
	woof->getIdeas(1);
	woof->getIdeas(2);
	woof->getIdeas(3);
	woof->getIdeas(4);
	woof->getIdeas(100);
	woof->makeSound();
	std::cout << std::endl;

	Dog* bark = new Dog(*woof);

	bark->getIdeas(0);
	bark->getIdeas(1);
	bark->getIdeas(2);
	bark->getIdeas(3);
	bark->makeSound();
	
	delete bark;
	delete woof;
	
	return 0;
}