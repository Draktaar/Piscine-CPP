/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 01:18:58 by achu              #+#    #+#             */
/*   Updated: 2025/08/02 00:04:33 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <iostream>
#include <cstdlib>
#include <typeinfo>

static Base*	generate(void)
{
	Base*	lBase;

	int	i = std::rand() % 3;
	switch (i)
	{
		case 0:
			lBase = new A;
			break;
		case 1:
			lBase = new B;
			break;
		case 2:
			lBase = new C;
			break;
	}

	return (lBase);
}

static void	identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "It is an A class" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "It is an B class" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "It is an C class" << std::endl;
	else
		std::cout << "Neither A, B or C class it is" << std::endl;
}

static void	identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "It is an A class" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}

	try
	{
		B&	b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "It is an B class" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}

	try
	{
		C&	c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "It is an C class" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}

	std::cout << "Neither A, B or C class it is" << std::endl;
}

int	main(void)
{
	Base* a;
	Base* b;
	Base* c;
	Base* d;

	std::cout << "Im generating three completely random Class form A, B or C" << std::endl;
	a = generate();
	b = generate();
	c = generate();
	d = NULL;
	std::cout << std::endl;

	std::cout << "Im going to identify the class with the pointer first" << std::endl;
	identify(a);
	identify(b);
	identify(c);
	identify(d);
	std::cout << std::endl;

	std::cout << "And to confirm this time, I will be using the reference instead" << std::endl;
	identify(*a);
	identify(*b);
	identify(*c);
	identify(*d);
	std::cout << std::endl;
	
	return (0);
}