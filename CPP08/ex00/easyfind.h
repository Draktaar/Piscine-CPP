/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 23:46:36 by achu              #+#    #+#             */
/*   Updated: 2025/07/27 13:20:08 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <algorithm>
#include <iterator>

template <typename T>
int	easyfind(const T& pContainer, int pSearch)
{
	typename T::const_iterator		it = std::find(pContainer.begin(), pContainer.end(), pSearch);
	if (it == pContainer.end())
		return (-1);
	return (std::distance(pContainer.begin(), it));
}

#endif