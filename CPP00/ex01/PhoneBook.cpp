/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:50:34 by achu              #+#    #+#             */
/*   Updated: 2025/07/28 13:22:02 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static std::string truncInfo(std::string info)
{
	std::string	newInfo;

	newInfo = info;
	if (newInfo.length() > 10)
	{
		newInfo = newInfo.substr(0, 9);
		newInfo.push_back('.');
		return (newInfo);
	}
	newInfo.insert(0, 10 - newInfo.length(), ' ');
	return (newInfo);	
}

PhoneBook::PhoneBook(void) : _registered(0) {}

void	PhoneBook::addContact()
{
	if (!_contacts[_registered % 8].fill()) {
		std::cout << "Contact aborted, empty info detected !\n\n";
	}
	else {
		std::cout << "Contact created successfully !\n\n";
		_registered++;
	}
}

void	PhoneBook::showContact() const
{
	int	maxRegister;

	maxRegister = _registered > 8 ? 8 : _registered;
	std::cout << "---------------------------------------------\n";
	std::cout << "|     Index| Firstname|  Lastname|  Nickname|\n";
	std::cout << "---------------------------------------------\n";
	for (int i = 0; i < maxRegister; i++)
	{
		std::cout << "|         " << i + 1 << "|";
		std::cout << truncInfo(_contacts[i].getFirstName()) << "|";
		std::cout << truncInfo(_contacts[i].getLastName())  << "|";
		std::cout << truncInfo(_contacts[i].getNickName())  << "|\n";
	}
	std::cout << "---------------------------------------------\n";
}

void	PhoneBook::displayContact(int index) const
{
	std::cout << "Firstname: " << _contacts[index - 1].getFirstName() << "\n";
	std::cout << "Lastname: " << _contacts[index - 1].getLastName() << "\n";
	std::cout << "Nickname: " << _contacts[index - 1].getNickName() << "\n";
	std::cout << "Phone Number: " << _contacts[index - 1].getPhoneNum() << "\n";
	std::cout << "Secret: " << _contacts[index - 1].getSecret() << "\n\n";
}

bool	PhoneBook::checkContact(std::string cmd) const
{
	int	maxRegister;

	for (size_t i = 0; i < cmd.length(); i++)
	{
		if (!isdigit(cmd[i])) {
			std::cout << "\n";
			return (false);
		}
	}

	if (std::atoi(cmd.c_str()) == 0) {
		std::cout << "\n";
		return (false);
	}

	maxRegister = _registered > 8 ? 8 : _registered;
	if (maxRegister < std::atoi(cmd.c_str())) {
		std::cout << "Contact does not exist !\n\n";
		return (false);
	}
	return (true);
}
