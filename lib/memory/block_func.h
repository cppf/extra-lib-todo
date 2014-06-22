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
#include "..\type\var_func.h"
#include <string.h>


namespace wind {


// non-modifier functions
template <typename T>
inline bool equals(const T* dst, const T* src, uint len)
{ return memcmp(dst, src, len*sizeof(T)) == 0; }

template <typename T>
inline T compare(const T* dst, const T* src, uint len)
{
	if(sizeof(T) == 1) return memcmp(dst, src, len);
	for(; len; ++dst, ++src, --len)
	{ if(*dst != *src) return *dst - *src; }
	return 0;
}

template <typename T>
inline T* find(const T* dst, uint len, T val)
{
	if(sizeof(T) == 1) return memchr(dst, val, len);
	for(; len; ++dst, --len)
	{ if(*dst == val) return dst; }
	return NULL;
}

template <typename T>
inline T* find(const T* dst, uint dlen, const T* src, uint slen)
{
	for(dlen-=slen-1; dlen; ++dst, --dlen)
	{ if(equals(dst, src, slen)) return dst; }
	return NULL;
}

template <typename T>
inline T* findAny(const T* dst, uint dlen, const T* src, uint slen)
{
	for(; dlen; ++dst, --dlen)
	{ if(find(src, slen, *dst)) return dst; }
	return NULL;
}

template <typename T>
inline T* findLast(const T* dst, uint len, T val)
{
	for(dst+=len-1; len; --dst, --len)
	{ if(*dst == val) return dst; }
	return NULL;
}

template <typename T>
inline T* findLast(const T* dst, uint dlen, const T* src, uint slen)
{
	for(dlen-=slen-1, dst+=dlen-1; dlen; --dst, --dlen)
	{ if(equals(dst, src, slen)) return dst; }
	return NULL;
}

template <typename T>
inline T* findLastAny(const T* dst, uint dlen, const T* src, uint slen)
{
	for(dst+=dlen-1; dlen; --dst, --dlen)
	{ if(find(src, slen, *dst)) return dst; }
	return NULL;
}

template <typename T>
inline int indexOf(const T* dst, uint len, T val)
{
	T* ptr = find(dst, len, val);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int indexOf(const T* dst, uint dlen, const T* src, uint slen)
{
	T* ptr = find(dst, dlen, src, slen);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int indexOfAny(const T* dst, uint dlen, const T* src, uint slen)
{
	T* ptr = findAny(dst, dlen, src, slen);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int lastIndexOf(const T* dst, uint len, T val)
{
	T* ptr = findLast(dst, len, val);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int lastIndexOf(const T* dst, uint dlen, const T* src, uint slen)
{
	T* ptr = findLast(dst, dlen, src, slen);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline int lastIndexOfAny(const T* dst, uint dlen, const T* src, uint slen)
{
	T* ptr = findLastAny(dst, dlen, src, slen);
	return (ptr)? (int)(ptr - dst) : -1;
}

template <typename T>
inline uint count(const T* dst, uint len, T val)
{
	uint ctr = 0;
	for(; len; ++dst, --len)
	{ if(*dst == val) ++ctr; }
	return ctr;
}

template <typename T>
inline uint count(const T* dst, uint dlen, const T* src, uint slen)
{
	uint ctr = 0;
	for(dlen -= slen-1; dlen; ++dst, --dlen)
	{ if(equals(dst, src, slen)) ++ctr; }
	return ctr;
}

template <typename T>
inline uint countAny(const T* dst, uint dlen, const T* src, uint slen)
{
	uint ctr = 0;
	for(; dlen; ++dst, --dlen)
	{ if(find(src, slen, *dst) != NULL) ++ctr; }
	return ctr;
}


// modifier functions
template <typename T>
inline void fill(T* dst, uint len, T val)
{
	if(sizeof(T) == 1) { memset(dst, val, len); return; }
	for(; len; ++dst, --len) *dst = val;
}

template <typename T>
inline void fillZero(T* dst, uint len, T val)
{ memset(dst, 0, len*sizeof(T)); }

template <typename Tdst, typename Tsrc>
inline void copyFrom(Tdst* dst, const Tsrc* src, uint len)
{
	if(sizeof(Tdst) == sizeof(Tsrc))
	{ memcpy(dst, src, len*sizeof(Tsrc)); }
	else if(sizeof(Tdst) < sizeof(Tsrc))
	{
		for(; len; ++dst, ++src, --len)
		{ *dst = (Tdst) *src; }
	}
	else
	{
		for(dst+=len-1, src+=len-1; len; --dst, --src, --len)
		{ *dst = (Tdst) *src; }
	}
}

template <typename T>
inline void moveFrom(void* dst, const T* src, uint len)
{ memmove(dst, src, len*sizeof(T)); }

template <typename T>
inline void reverse(T* dst, uint len)
{
	for(T* rev=dst+len-1; dst < rev; ++dst, --rev)
	{ swap(*dst, *rev); }
}

template <typename T>
inline void reverseFrom(T* dst, const T* src, uint len)
{
	for(T* rev=dst+len-1; len; ++dst, --rev, --len)
	{ *dst = *rev; }
}

template <typename T>
inline uint removeFrom(T* dst, const T* src, uint len, T val)
{
	for(; len; ++src, --len)
	{ if(*dst != val) { *dst = *src; ++dst; } }
	return (uint)(src - dst);
}

template <typename T>
inline uint remove(T* dst, uint len, T val)
{ return removeFrom(dst, dst, len, val); }

template <typename T>
inline void replace(T* dst, uint len, T find, T replace)
{
	for(; len; ++dst, --len)
	{ if(*dst == find) *dst = replace; }
}

template <typename T>
inline void replaceFrom(T* dst, const T* src, uint len, T find, T replace)
{
	for(; len; ++dst, ++src, --len)
	{
		if(*src == find) * dst = replace;
		else *dst = *src;
	}
}

template <typename T>
inline void replace(T* dst, const T* src, uint slen, T* find, uint flen, T* replace, uint rlen)
{
	slen -= flen - 1;
	for(; slen; ++dst, ++src, --slen)
	{
		if(compare(src, find, flen) != 0) *dst = *src;
		else { copy(dst, replace, rlen); src += flen-1; dst += rlen-1; }
	}
}


} // end namespace wind


#endif /* _DATA_BLOCK_FUNC_H_ */