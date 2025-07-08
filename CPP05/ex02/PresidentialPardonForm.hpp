/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:00:55 by achu              #+#    #+#             */
/*   Updated: 2025/07/08 16:22:13 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __PRESIDENTIAL_PARDON_FORM_H__
#define __PRESIDENTIAL_PARDON_FORM_H__

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
	private:

		PresidentialPardonForm();

	public:

		PresidentialPardonForm(std::string pTarget);
		PresidentialPardonForm(const PresidentialPardonForm& pCopy);
		PresidentialPardonForm&	operator=(const PresidentialPardonForm& pCopy);
		~PresidentialPardonForm();
};

#endif