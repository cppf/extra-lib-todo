/* ----------------------------------------------------------------------- *
 *
 *	 Copyright (c) 2014, Subhajit Sahu
 *	 All rights reserved.
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following
 *   conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *
 *     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
 *     CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES,
 *     INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 *     MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 *     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 *     CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *     SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 *     NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 *     HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *     CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 *     OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 *     EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ----------------------------------------------------------------------- */

/* 
 * type\var_func.h - Provides variable related functions
 * This file is part of the Wind library for C++.
 */

#ifndef _TYPE_VAR_FUNC_H_
#define _TYPE_VAR_FUNC_H_


// swap variables
template <typename T>
inline void swap(T& a, T& b)
{
	a ^= b;
	b ^= a;
	a ^= b;
}


// write variables to memory
template <typename Ta>
inline void writeVar(void* dst, Ta a)
{
	*((Ta*)dst) = a;
}

template <typename Ta, typename Tb>
inline void writeVar(void* dst, Ta a, Tb b)
{
	*((Ta*)dst) = a;
	*((Tb*)((char*)dst + sizeof(Ta))) = b;
}

template <typename Ta, typename Tb, typename Tc>
inline void writeVar(void* dst, Ta a, Tb b, Tc c)
{
	*((Ta*)dst) = a;
	*((Tb*)((char*)dst + sizeof(Ta))) = b;
	*((Tc*)((char*)dst + sizeof(Ta) + sizeof(Tb))) = c;
}

template <typename Ta, typename Tb, typename Tc, typename Td>
inline void writeVar(void* dst, Ta a, Tb b, Tc c, Td d)
{
	*((Ta*)dst) = a;
	*((Tb*)((char*)dst + sizeof(Ta))) = b;
	*((Tc*)((char*)dst + sizeof(Ta) + sizeof(Tb))) = c;
	*((Td*)((char*)dst + sizeof(Ta) + sizeof(Tb) + sizeof(Tc))) = d;
}


// read variables from memory
template <typename Ta>
inline void readVar(const void* src, Ta& a)
{
	a = *((Ta*)src);
}

template <typename Ta, typename Tb>
inline void readVar(const void* src, Ta& a, Tb& b)
{
	a = *((Ta*)src);
	b = *((Tb*)((char*)src + sizeof(Ta)));
}

template <typename Ta, typename Tb, typename Tc>
inline void readVar(const void* src, Ta& a, Tb& b, Tc& c)
{
	a = *((Ta*)src);
	b = *((Tb*)((char*)src + sizeof(Ta)));
	c = *((Tc*)((char*)src + sizeof(Ta) + sizeof(Tb)));
}

template <typename Ta, typename Tb, typename Tc, typename Td>
inline void readVar(const void* src, Ta& a, Tb& b, Tc& c, Td& d)
{
	a = *((Ta*)src);
	b = *((Tb*)((char*)src + sizeof(Ta)));
	c = *((Tc*)((char*)src + sizeof(Ta) + sizeof(Tb)));
	d = *((Td*)((char*)src + sizeof(Ta) + sizeof(Tb) + sizeof(Tc)));
}



#endif /* _TYPE_VAR_FUNC_H_ */