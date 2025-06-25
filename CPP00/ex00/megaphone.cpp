/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 13:58:23 by achu              #+#    #+#             */
/*   Updated: 2025/06/26 00:03:33 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	caps(std::string arg)
{
	std::string	message = arg;

	for (size_t i = 0; message[i]; i++)
	{
		if ('a' <= message[i] && message[i] <= 'z')
			message[i] -= 32;
	}
	return (message);
}

int	main(int ac, char **av)
{
	if (ac <= 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < ac; i++)
		std::cout << caps(av[i]);
	std::cout << std::endl;
	return (0);
}
