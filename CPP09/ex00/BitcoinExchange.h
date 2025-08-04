/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:00:16 by achu              #+#    #+#             */
/*   Updated: 2025/08/05 00:44:27 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BITCOINT_EXCHANGE_H__
#define __BITCOINT_EXCHANGE_H__

#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <exception>

class BitcoinExchange
{
	private:

		std::map<std::string, double>	_map;
		std::fstream	_iFile;
		std::fstream	_oFile;

	private:

		BitcoinExchange(void);
		std::vector<std::string>	Split(const std::string& pStr, const std::string& p);

	public:

		BitcoinExchange(std::string pFile);
		BitcoinExchange(const BitcoinExchange& pCopy);
		~BitcoinExchange(void);

		

		BitcoinExchange&	operator=(const BitcoinExchange& pCopy);

		class FileException : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif