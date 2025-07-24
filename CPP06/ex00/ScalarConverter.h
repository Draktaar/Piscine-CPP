/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 02:00:54 by achu              #+#    #+#             */
/*   Updated: 2025/07/25 00:50:04 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SCALAR_CONVERTER_H__
#define __SCALAR_CONVERTER_H__

#include <string>
#include <exception>

class ScalarConverter
{
	private:

		ScalarConverter();
		ScalarConverter(const ScalarConverter& pCopy);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& pCopy);

	public:

		static void convert(const std::string& pLiteral);

		enum LiteralType
		{
			LITERAL_NAN,
			LITERAL_INFP,
			LITERAL_INFN,
			LITERAL_CHAR,
			LITERAL_INT,
			LITERAL_FLOAT,
			LITERAL_DOUBLE,
			LITERAL_INVALID,
		};
		
		class InvalidLiteralException : std::exception {
			public:
				virtual const char*	what() const throw();
		};
};

#endif