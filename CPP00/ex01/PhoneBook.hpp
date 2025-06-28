/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 00:50:46 by achu              #+#    #+#             */
/*   Updated: 2025/06/27 14:16:12 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include "Contact.hpp"

class PhoneBook
{
	private:
		Contact _contacts[8];
		int		_registered;

	public:
		PhoneBook(void);

		void	addContact();
		void	showContact() const;
		void	displayContact(int index) const;
		bool	checkContact(std::string cmd) const;
};

#endif