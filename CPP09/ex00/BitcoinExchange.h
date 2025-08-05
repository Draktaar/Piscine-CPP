/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:00:16 by achu              #+#    #+#             */
/*   Updated: 2025/08/05 11:41:39 by achu             ###   ########.fr       */
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

		void	LoadData();
		std::vector<std::string>	Split(const std::string& pStr, const std::string& pDelim);

	public:

		BitcoinExchange(const std::string& pFile);
		BitcoinExchange(const BitcoinExchange& pCopy);
		~BitcoinExchange(void);

		void	Exchage(void);

		BitcoinExchange&	operator=(const BitcoinExchange& pCopy);

		class InputException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class OutputException : public std::exception {
			public:
				const char*	what() const throw();
		};
};

#endif