/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 20:05:57 by achu              #+#    #+#             */
/*   Updated: 2025/07/24 17:20:02 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.h"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: ./convert <string>" << std::endl;
		return (1);
	}

	try {
		ScalarConverter::convert(av[1]);	
	}
	catch (const ScalarConverter::InvalidLiteralException& pE) {
		std::cerr << pE.what() << std::endl;		
	}
	return (0);
}