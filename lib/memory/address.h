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
 * memory\address.h - Defines a memory address that provides destination-type functions
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_ADDRESS_H_
#define _MEMORY_ADDRESS_H_


// required headers
#include <stdlib.h>
#include <string.h>
#include "..\type\primitives.h"


namespace wind {


// memory address class
// can be type casted to type*
template <typename T>
class address
{


public:
	// data
	T* Value;
	

public:
	// initialization
	inline operator T*() const
	{ return Value; }

	inline address(const void* addr=NULL)
	{ Value = (T*) addr; }

	inline static address Create(const void* addr=NULL)
	{ return address(addr); }

	inline void Destroy()
	{ Value = NULL; }


	// functions
	inline bool IsValid()
	{ return Value != NULL; }

	inline address Begin(int off=0)
	{ return address(Value+off); }

	inline address End(int off=0)
	{ return address(Value+off); }

	inline address Fill(T val, uint size)
	{
		if(sizeof(T) == 1) { memset(Value, val, size); return *this; }
		for(T* ptr=Value; size; ++ptr, --size) *ptr = val;
		return *this;
	}

	inline address FillZero(uint size)
	{ memset(Value, 0, size*sizeof(T)); return *this; }

	inline address Copy(const void* src, uint size)
	{ memcpy(Value, src, size*sizeof(T)); return *this; }

	inline address Copy(uint dstSize, const void* src, uint size)
	{ memcpy_s(Value, dstSize*sizeof(T), src, size*sizeof(T)); return *this; }

	inline address Move(const void* src, uint size)
	{ memmove(Value, src, size*sizeof(T)); return *this; }

	inline address Move(uint dstSize, const void* src, uint size)
	{ memmove_s(Value, dstSize*sizeof(T), src, size*sizeof(T)); return *this; }

	inline int Compare(const T* addr, uint size) const
	{
		if(sizeof(T) == 1) return memcmp(Value, addr, size);
		for(T* ptr=Value; size; ++ptr, ++addr, --size)
		{ if(*ptr != *addr) return *ptr-*addr; }
		return 0;
	}

	inline bool Equals(const T* addr, uint size) const
	{ return Compare(Value, addr, size) == 0; }

	inline address Find(T val, uint size) const
	{
		if(sizeof(T) == 1) return address(memchr(Value, val, size));
		for(T* ptr=Value; size; ++ptr, --size)
		{ if(*ptr == val) return address(ptr); }
		return NULL;
	}

	inline address FindLast(T val, uint size) const
	{
		for(T* ptr=Value+size-1; size; --ptr, --size)
		{ if(*ptr == val) return address(ptr); }
		return NULL;
	}

	inline int IndexOf(T val, uint size) const
	{
		T* ptr = Find(val, size);
		return (ptr)? (int)(ptr - Value) : -1;
	}

	inline int IndexOfLast(T val, uint size) const
	{
		T* ptr = FindLast(val, size);
		return (ptr)? (int)(ptr - Value) : -1;
	}


}; // end class address


} // end namespace wind


#endif /* _MEMORY_ADDRESS_H_ */