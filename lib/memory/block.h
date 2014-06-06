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
 * data\block.h - Defines a memory block that provides destination-type functions
 * This file is part of the Wind library for C++.
 */

#ifndef _DATA_BLOCK_H_
#define _DATA_BLOCK_H_


// required headers
#include "..\type\gchar.h"
#include "..\memory\heap.h"
#include <string.h>


namespace wind {


// memory block class
// can be type casted to T*
template <typename T>
class block
{


public:
	// data
	T* Address;
	uint Size;


public:
	// initialization
	inline operator T*() const
	{ return Address; }

	inline block(void* addr=NULL, uint size=0)
	{ Address = addr; Size = size; }

	inline static block Create(T* str)
	{
		if(sizeof(T) == 1) return block(str, strlen(str));
		else if(sizeof(T) == 2) return block(str, wcslen(str));
		// else return block(str, Address.Find(int_Max, 0));
	}

	inline static block Create(T* str, uint len)
	{ return block(str, len); }

	inline void Destroy()
	{ Address = NULL; Size = 0; }


	// functions
	inline bool IsValid()
	{ return Address != NULL; }

	inline block Begin(int off=0, uint size=0)
	{ return block(Address+off, size); }

	inline block End(int off=0, uint size=0)
	{ return block(Address+Size+off, size); }

	inline block BeginFull(int off=0, int sizeOff=0)
	{ return block(Address+off, (uint)(Size+sizeOff)); }

	inline block EndFull(int off=0, int sizeOff=0)
	{ return block(Address+Size+off, (uint)(Size+sizeOff)); }

	inline block Fill(T val)
	{
		uint size = Size;
		if(sizeof(T) == 1) { memset(Address, val, Size); return *this; }
		for(T* ptr=Address; size; ++ptr, --size) *ptr = val;
		return *this;
	}

	inline block FillZero()
	{ memset(Address, 0, Size*sizeof(T)); return *this; }

	inline block Copy(block src)
	{ memcpy(Address, src, src.Size*sizeof(T)); return block(Address, src.Size); }

	inline block Move(block src)
	{ memmove(Address, src, src.Size); return block(Address, src.Size); }

	inline block Append(block src)
	{
		if(Address+Size != src.Address)
		{ block<T>(Address+Size).Move(src); }
		return block(Address, Size+src.Size);
	}

	inline int Compare(block src) const
	{
		uint cmp = (Size < src.Size)? Size : src.Size;
		if(sizeof(T) == 1) cmp = memcmp(Address, src, cmp);
		else
		{
			for(T* dptr=Address, sptr=src; cmp; ++dptr, ++sptr, --cmp)
			{ if(*dptr != *sptr) { cmp = *dptr-*sptr; break; } }
		}
		return (cmp)? cmp : Size - src.Size;
	}

	inline bool Equals(block src) const
	{ return (Size != src.Size)? false : (Compare(src) == 0); }

	inline block Find(T val) const
	{
		uint size = Size;
		if(sizeof(T) == 1) return memchr(Address, val, Size);
		for(T* ptr=Address; size; ++ptr, --size)
		{ if(*ptr == val) return ptr; }
		return NULL;
	}

	inline block Find(block src) const
	{
		uint size = Size - src.Size + 1;
		for(T* ptr=Address; size; ++ptr, --size)
		{ if(block(ptr, src.Size).Equals(src)) return block(ptr, src.Size); }
		return NULL;
	}

	inline block FindLast(T val) const
	{
		uint size = Size;
		for(T* ptr=Address+size-1; size; --ptr, --size)
		{ if(*ptr == val) return ptr; }
		return NULL;
	}

	inline block FindLast(block src) const
	{
		uint size = Address - src.Size + 1;
		for(T* ptr=Address+size-1; size; --ptr, --size)
		{ if(block(ptr, src.Size).Equals(src)) return block(ptr, src.Size); }
		return NULL;
	}

	inline int IndexOf(T val) const
	{
		T* ptr = Find(val);
		return (ptr)? (int)(ptr - Address) : -1;
	}

	inline int IndexOf(block src) const
	{
		T* ptr = Find(src);
		return (ptr)? (int)(ptr - Address) : -1;
	}

	inline int IndexOfLast(T val) const
	{
		T* ptr = FindLast(val);
		return (ptr)? (int)(ptr - Address) : -1;
	}

	inline int IndexOfLast(block src) const
	{
		T* ptr = FindLast(src);
		return (ptr)? (int)(ptr - Address) : -1;
	}

	inline block Reverse()
	{
		uint size = Size/2;
		for(T* fptr=Address, rptr=Address+Size-1; size; ++fptr, --rptr, --size)
		{ *fptr ^= *rptr; *rptr ^= *fptr; *fptr ^= *rptr; }
		return *this;
	}

	inline block ToLowerCase()
	{
		uint len = Length;
		for(T* ptr=Address; len; ++ptr, --len)
		{ *ptr = gchar<T>(*ptr).GetLowerCase(); }
		return *this;
	}

	inline block ToUpperCase()
	{
		uint len = Length;
		for(T* ptr=Address; len; ++ptr, --len)
		{ *ptr = gchar<T>(*ptr).GetUpperCase(); }
		return *this;
	}


}; // end class gstring


} // end namespace wind


#endif /* _DATA_GSTRING_H_ */