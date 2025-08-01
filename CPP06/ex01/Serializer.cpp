/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 00:54:07 by achu              #+#    #+#             */
/*   Updated: 2025/08/01 23:53:00 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.h"

Serializer::uintptr_t	Serializer::serialize(Data* pPtr)
{
	return (reinterpret_cast<uintptr_t>(pPtr));
}

Data*		Serializer::deserialize(uintptr_t pRaw)
{
	return (reinterpret_cast<Data*>(pRaw));
}