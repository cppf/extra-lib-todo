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
 * memory\block_func.h - Provides functions associated with a memory block
 * This file is part of the Wind library for C++.
 */

#ifndef _DATA_BLOCK_FUNC_H_
#define _DATA_BLOCK_FUNC_H_


// required headers
#include "..\support\constants.h"
#include "..\support\keywords.h"
#include "..\type\primitives.h"
#include <string.h>


namespace wind {


// non-modifier functions
template <typename T>
inline T block_Compare(const T* dst, const T* src, uint size)
{
	if(sizeof(T) == 1) return memcmp(dst, src, size);
	for(; size; ++dst, ++src, --size)
	{ if(*dst != *src) return *dst - *src; }
	return 0;
}

template <typename T>
inline T* block_Find(const T* dst, uint size, T val)
{
	if(sizeof(T) == 1) return memchr(dst, val, size);
	for(; size; ++dst, --size)
	{ if(*dst == val) return dst; }
	return NULL;
}

template <typename T>
inline T* block_Find(const T* dst, uint dSize, const T* src, uint sSize)
{
	dSize -= sSize - 1;
	for(; dSize; ++dst, --dSize)
	{ if(block_Compare(dst, src, sSize) == 0) return dst; }
	return NULL;
}

template <typename T>
inline T* block_FindAny(const T* dst, uint dSize, const T* src, uint sSize)
{
	for(; dSize; ++dst, --dSize)
	{ if(block_Find(src, sSize, *dst)) return dst; }
	return NULL;
}

template <typename T>
inline T* block_FindLast(const T* dst, uint size, T val)
{
	for(dst+=size-1; size; --dst, --size)
	{ if(*dst == val) return dst; }
	return NULL;
}

template <typename T>
inline T* block_FindLast(const T* dst, uint dSize, const T* src, uint sSize)
{
	dSize -= sSize - 1;
	for(dst+=dSize-1; dSize; --dst, --dSize)
	{ if(block_Compare(dst, src, sSize) == 0) return dst; }
	return NULL;
}

template <typename T>
inline T* block_FindLastAny(const T* dst, uint dSize, const T* src, uint sSize)
{
	for(dst+=dSize-1; dSize; --dst, --dSize)
	{ if(block_Find(src, sSize, *dst)) return dst; }
	return NULL;
}

template <typename T>
inline int block_IndexOf(const T* dst, uint size, T val)
{
	T* ptr = block_Find(dst, size, val);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int block_IndexOf(const T* dst, uint dSize, const T* src, uint sSize)
{
	T* ptr = block_Find(dst, dSize, src, sSize);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int block_IndexOfAny(const T* dst, uint dSize, const T* src, uint sSize)
{
	T* ptr = block_FindAny(dst, dSize, src, sSize);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int block_LastIndexOf(const T* dst, uint size, T val)
{
	T* ptr = block_FindLast(dst, size, val);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int block_LastIndexOf(const T* dst, uint dSize, const T* src, uint sSize)
{
	T* ptr = block_FindLast(dst, dSize, src, sSize);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int block_LastIndexOfAny(const T* dst, uint dSize, const T* src, uint sSize)
{
	T* ptr = block_FindLastAny(dst, dSize, src, sSize);
	return (ptr)? (int)(ptr - dst) : -1;
}


// modifier functions
template <typename T>
inline void block_Fill(T* dst, uint size, T val)
{
	if(sizeof(T) == 1) { memset(dst, val, size); return; }
	for(; size; ++dst, --size) *dst = val;
}

template <typename T>
inline void block_FillZero(T* dst, uint size, T val)
{ memset(dst, 0, size*sizeof(T)); }

template <typename T>
inline void block_Copy(void* dst, const T* src, uint size)
{ memcpy(dst, src, size*sizeof(T)); }

template <typename T>
inline void block_Move(void* dst, const T* src, uint size)
{ memmove(dst, src, size*sizeof(T)); }

template <typename T>
inline void block_Reverse(T* dst, uint size)
{
	for(T* rev=dst+size-1; dst < rev; ++dst, --rev)
	{ *dst ^= *rev; *rev ^= *dst; *dst ^= *rev; }
}



template <typename Tdst, typename Tsrc>
inline void block_Convert(Tdst* dst, const Tsrc* src, uint size)
{
	if(sizeof(Tdst) == sizeof(Tsrc)) { memcpy(dst, src, size*sizeof(Tsrc)); return; }
	for(; size; ++dst, ++src, --size)
	{ *dst = (Tdst) *src; }
}

template <typename Tdst, typename Tsrc>
inline void block_ConvertOv(Tdst* dst, const Tsrc* src, uint size)
{
	memmove(dst, src, size*sizeof(Tsrc));
	if(sizeof(Tdst) == sizeof(Tsrc)) return;
	else if(sizeof(Tdst) < sizeof(Tsrc)) 
	{
		for(; size; ++dst, ++src, --size)
		{ *dst = (Tdst) *src; }
	}
	else
	{
		for(dst+=size-1, src+=size-1; size; --dst, --src, --size)
		{ *dst = (Tdst) *src; }
	}
}


template <typename T>
inline void block_Replace(T* dst, uint size, T find, T replace)
{
	for(; size; ++dst, --size)
	{ if(*dst == find) *dst = replace; }
}

template <typename T>
inline void block_Replace(T* dst, const T* src, uint size, T find, T replace)
{
	for(; size; ++dst, ++src, --size)
	{
		if(*src == find) * dst = replace;
		else *dst = *src;
	}
}

template <typename T>
inline void block_Replace(T* dst, const T* src, uint sSize, T* find, uint fSize, T* replace, uint rSize)
{
	sSize -= fSize - 1;
	for(; sSize; ++dst, ++src, --sSize)
	{
		if(block_Compare(src, find, fSize) != 0) *dst = *src;
		else { block_Copy(dst, replace, rSize); src += fSize-1; dst += rSize-1; }
	}
}

template <typename T>
inline void block_Reverse(T* dst, const T* src, uint size)
{
	for(T* rev=dst+size-1; size; ++dst, --rev, --size)
	{ *dst = *rev; }
}


} // end namespace wind


#endif /* _DATA_BLOCK_FUNC_H_ */