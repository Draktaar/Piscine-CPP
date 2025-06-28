/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 13:09:56 by achu              #+#    #+#             */
/*   Updated: 2025/06/27 02:52:21 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void) : _firstName(""), _lastName(""), _nickName(""), _phoneNum(""), _secret("") {}

Contact::Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string srct)
	: _firstName(fn), _lastName(ln), _nickName(nn), _phoneNum(pn), _secret(srct) {}

bool	Contact::fill()
{
	std::cout << "Enter firstname: ";
	std::getline(std::cin, _firstName);
	if (_firstName.empty())
		return (false);

	std::cout << "Enter lastname: ";
	std::getline(std::cin, _lastName);
	if (_lastName.empty())
		return (false);

	std::cout << "Enter nickname: ";
	std::getline(std::cin, _nickName);
	if (_nickName.empty())
		return (false);

	std::cout << "Enter phone number: ";
	std::getline(std::cin, _phoneNum);
	if (_phoneNum.empty())
		return (false);

	std::cout << "Enter secret: ";
	std::getline(std::cin, _secret);
	if (_secret.empty())
		return (false);

	return (true);
}

std::string	Contact::getFirstName() const { return (this->_firstName); }
std::string	Contact::getLastName() const { return (this->_lastName); }
std::string	Contact::getNickName() const { return (this->_nickName); }
std::string	Contact::getPhoneNum() const { return (this->_phoneNum); }
std::string	Contact::getSecret() const { return (this->_secret); }
