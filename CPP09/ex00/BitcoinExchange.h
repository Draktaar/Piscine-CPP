/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 23:00:16 by achu              #+#    #+#             */
/*   Updated: 2025/08/07 16:33:37 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __BITCOINT_EXCHANGE_H__
#define __BITCOINT_EXCHANGE_H__

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"
#define YELLOW	"\e[43m"

#include <fstream>
#include <string>
#include <map>
#include <exception>

class BitcoinExchange
{
	private:

		std::map<std::string, double>	_map;

		std::string		_fileName;
		std::ifstream	_input;
		std::ifstream	_data;

	private:

		BitcoinExchange(void);

		void			loadData(void);
		double			calculateBitcoin(const std::string& pDate, const double& pNumber) const;

	public:

		BitcoinExchange(const std::string& pFile);
		BitcoinExchange(const BitcoinExchange& pCopy);
		~BitcoinExchange(void);

		void	exchange(void);
		BitcoinExchange&	operator=(const BitcoinExchange& pCopy);

		class FileException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class InputException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class DigitException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class OverflowException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class UnderflowException : public std::exception {
			public:
				const char*	what() const throw();
		};

		class DateException : public std::exception {
			public:
				const char*	what() const throw();
		};

};

#endif