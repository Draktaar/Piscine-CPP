/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 03:29:27 by achu              #+#    #+#             */
/*   Updated: 2025/06/29 16:59:02 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static std::string	replaceAll(const std::string& pLine, const std::string& pSearch, const std::string& pReplace)
{
	int				pos = 0;
	std::string		newLine = pLine;

	while ((pos = newLine.find(pSearch, pos)) != -1)
	{
		newLine.erase(pos, pSearch.length());
		newLine.insert(pos, pReplace);
		pos += pReplace.length();
	}
	return (newLine);
}

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Error: " << av[0] << " <filename> <search> <replace>\n";
		return (1);
	}

	std::string		fileName = av[1];
	std::string		search = av[2];
	std::string		replace = av[3];

	std::ifstream	iFile((fileName).c_str());
	if (!iFile.is_open())
	{
		std::cerr << "Error: " << fileName << "cannot be read" << std::endl;
		return (1);
	}

	std::ofstream	oFile((fileName + ".replace").c_str());
	if (!oFile.is_open())
	{
		std::cerr << "Error: " <<  fileName + ".replace" << "cannot be written" << std::endl;
		return (1);
	}

	std::string		line;
	while (std::getline(iFile, line))
	{
		if ((int)line.find(search) < 0)
			oFile << line << "\n";	
		else
			oFile << replaceAll(line, search, replace) << "\n";
	}

	iFile.close();
	oFile.close();

	return (0);
}
