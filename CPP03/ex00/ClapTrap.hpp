/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 22:46:35 by achu              #+#    #+#             */
/*   Updated: 2025/07/29 17:30:41 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WHITE	"\e[0m"
#define BLUE	"\e[44m"
#define	RED		"\e[41m"

#define BLUE_TEXT(text)	(std::string("\e[44m ") + (text) + " \e[0m")
#define RED_TEXT(text)	(std::string("\e[44m ") + (text) + " \e[0m")

#include <string>

class ClapTrap
{
	private:

		std::string		_name;
		int				_health;
		int				_energy;
		int				_atkDmg;

	public:

		ClapTrap(void);
		ClapTrap(std::string pName);
		ClapTrap(ClapTrap const& pCopy);
		~ClapTrap(void);

		void	attack(std::string const& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

		ClapTrap&	operator=(ClapTrap const& pCopy);
};