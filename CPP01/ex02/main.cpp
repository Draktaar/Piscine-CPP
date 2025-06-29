/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:05:48 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 02:27:45 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "Memory adress of the string variable: " << &brain << std::endl;
	std::cout << "Memory adress held by string pointer: " << stringPTR << std::endl;
	std::cout << "Memory adress held by string reference: " << &stringREF << std::endl;

	std::cout << "Value of the string variable: " << brain << std::endl;
	std::cout << "Value pointed to by string pointer: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by string reference: " << stringREF << std::endl;

	return (0);
}
