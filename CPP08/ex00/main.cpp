/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:45:32 by achu              #+#    #+#             */
/*   Updated: 2025/07/27 13:14:29 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.h"
#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> numbers;
    numbers.push_back(3);
    numbers.push_back(7);
    numbers.push_back(42);

    int index = easyfind(numbers, 42);
    if (index != -1)
        std::cout << "Found at index: " << index << std::endl;
    else
        std::cout << "Not found." << std::endl;

    return 0;

	return (0);
}
