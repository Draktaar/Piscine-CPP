/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 01:18:58 by achu              #+#    #+#             */
/*   Updated: 2025/07/25 23:30:48 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.h"
#include "A.h"
#include "B.h"
#include "C.h"
#include <iostream>
#include <cstdlib>

static Base*	generate(void)
{
	Base*	lBase;

	int	i = rand() % 3;
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
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "It is an A class" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "It is an B class" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "It is an C class" << std::endl;
	std::cout << "Neither A, B or C class it is" << std::endl;
}

static void	identify(Base& p)
{
	try
	{
		A&	a = dynamic_cast<A&>(p);
		std::cout << "It is an A class" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}

	try
	{
		B&	b = dynamic_cast<B&>(p);
		std::cout << "It is an B class" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}

	try
	{
		C&	c = dynamic_cast<C&>(p);
		std::cout << "It is an C class" << std::endl;
		return ;
	}
	catch (std::bad_cast&) {}
}

int	main(void)
{
	return (0);
}