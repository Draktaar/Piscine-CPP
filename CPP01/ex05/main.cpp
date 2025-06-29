/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 03:29:27 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 19:33:44 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Harl.hpp"

int	main()
{
	Harl			harl;
	std::string		cmd;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::cout << "\nThere are four command to choose: (Other commands will be ignored !)\nDEBUG\nINFO\nWARNING\nERROR\n";
	std::getline(std::cin, cmd);
	harl.complain(cmd);

	return (0);
}
