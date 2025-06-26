/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:12:29 by achu              #+#    #+#             */
/*   Updated: 2025/06/26 14:26:40 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.hpp"

int	FtStrcmp(std::string s1, std::string s2)
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

bool	IsAdd(std::string cmd)
{
	if (FtStrcmp(cmd, "ADD") == 0)
		return (true);
	return (false);
}

bool	IsSearch(std::string cmd)
{
	if (FtStrcmp(cmd, "SEARCH") == 0)
		return (true);
	return (false);
}

bool	IsExit(std::string cmd)
{
	if (FtStrcmp(cmd, "EXIT") == 0)
		return (true);
	return (false);
}

void	InfoMessage(void)
{
	std::cout << "Please use one of the following command:\n";
	std::cout << "ADD: Save a new contact\n";
	std::cout << "SEARCH: Display a specific contact\n";
	std::cout << "EXIT: Quits the program and lose all your friends FOREVER !\n";
	std::cout << std::endl;
}

int	main()
{
	PhoneBook	list;
	std::string	cmd;

	InfoMessage();
	while (1)
	{
		std::getline(std::cin, cmd);
		if (IsAdd(cmd))
			std::cout << "add" << std::endl;
		else if (IsSearch(cmd))
			std::cout << "search" << std::endl;
		else if (IsExit(cmd))
			break;
		else
			InfoMessage();
	}
	return (0);
}
