/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:59:42 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 09:04:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __ROBOTOMY_REQUEST_FORM_H__
#define __ROBOTOMY_REQUEST_FORM_H__

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
	private:

		RobotomyRequestForm();
		void	paperWork(void) const;

	public:

		RobotomyRequestForm(std::string pTarget);
		RobotomyRequestForm(const RobotomyRequestForm& pCopy);
		RobotomyRequestForm&	operator=(const RobotomyRequestForm& pCopy);
		~RobotomyRequestForm();
};

#endif