/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:04:01 by achu              #+#    #+#             */
/*   Updated: 2025/07/08 19:26:12 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __INTERN_H__
#define __INTERN_H__

#include "AForm.hpp"
#include <string>

class Intern
{
	private:

		AForm*		newPresidential(const std::string& pTarget) const;
		AForm*		newRobotomy(const std::string& pTarget) const;
		AForm*		newShrubbery(const std::string& pTarget) const;
	
	public:
		Intern() {};
		Intern(const Intern& pCopy) {};
		~Intern() {};
		Intern&	operator=(const Intern& pCopy) {};

		AForm*	makeForm(const std::string& pFormName, const std::string& pTarget) const;
};

#endif
