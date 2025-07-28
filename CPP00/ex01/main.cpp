/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:12:29 by achu              #+#    #+#             */
/*   Updated: 2025/07/28 13:22:43 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

static int	strcmp(std::string s1, std::string s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

static void	infoMessage(void)
{
	std::cout << "Use one of the following command:\n";
	std::cout << "ADD: Save a new contact\n";
	std::cout << "SEARCH: Display a specific contact\n";
	std::cout << "EXIT: Quits the program and lose all your friends FOREVER !\n\n";
}

int	main()
{
	PhoneBook		book;
	std::string		cmd;

	infoMessage();
	while (1)
	{
		if (!std::getline(std::cin, cmd))
			return (0);
		if (!strcmp(cmd, "EXIT"))
			break;
		else if (!strcmp(cmd, "ADD"))
			book.addContact();
		else if (!strcmp(cmd, "SEARCH"))
		{
			book.showContact();
			std::cout << "Input the index to display more information about the contact:\n";
			std::cout << "(To return to the menu, press any other keys that are not an index)\n";
			std::getline(std::cin, cmd);
			if (book.checkContact(cmd))
				book.displayContact(std::atoi(cmd.c_str()));
			infoMessage();
		}
	}
	return (0);
}
