/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:00:20 by achu              #+#    #+#             */
/*   Updated: 2025/08/05 11:42:51 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.h"
#include <iostream>
#include <string>

BitcoinExchange::BitcoinExchange(void)
{
	throw InputException();
}

BitcoinExchange::BitcoinExchange(const std::string& pFile)
{
	_iFile.open(pFile);
	if (!_iFile.is_open())
		throw InputException();

	_oFile.open("");
	if (!_oFile.is_open())
		throw OutputException();
}