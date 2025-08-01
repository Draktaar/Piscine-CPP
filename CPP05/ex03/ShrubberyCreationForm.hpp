/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:58:40 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 09:04:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SHRUBBERY_CREATION_FORM_H__
#define __SHRUBBERY_CREATION_FORM_H__

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : public AForm
{
	private:

		ShrubberyCreationForm();
		void	paperWork(void) const;

	public:

		ShrubberyCreationForm(std::string pTarget);
		ShrubberyCreationForm(const ShrubberyCreationForm& pCopy);
		ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& pCopy);
		~ShrubberyCreationForm();
};

#endif