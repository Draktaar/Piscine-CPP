/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achu <achu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 18:37:50 by achu              #+#    #+#             */
/*   Updated: 2025/07/25 00:52:56 by achu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef __SERIALIZER_H__
#define __SERIALIZER_H__

#include "Data.h"
#include <iostream>
#include <cstdint>

class Serializer
{
	private:
		Serializer(void);
		Serializer(const Serializer& pCopy);
		~Serializer(void);
		Serializer& operator=(const Serializer& pCopy);
		
	public:
		static uintptr_t	serialize(Data* pPtr);
		static Data*		deserialize(uintptr_t pRaw);
};

#endif