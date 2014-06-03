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

	inline void Fill(uint size, byte val)
	{ memset(Value, val, size); }

	inline void FillZero(uint size)
	{ memset(Value, 0, size); }

	inline void Copy(const void* src, uint size)
	{ memcpy(Value, src, size); }

	inline void Copy(uint dstSize, const void* src, uint size)
	{ memcpy_s(Value, dstSize, src, size); }

	inline void Move(const void* src, uint size)
	{ memmove(Value, src, size); }

	inline void Move(uint dstSize, const void* src, uint size)
	{ memmove_s(Value, dstSize, src, size); }

	inline int Compare(const void* addr, uint size) const
	{ return memcmp(Value, addr, size); }

	inline bool Equals(const void* addr, uint size) const
	{ return memcmp(Value, addr, size) == 0; }

	inline void* Find(uint size, byte val)
	{ return memchr(Value, val, size); }


}; // end class address


} // end namespace wind


#endif /* _MEMORY_ADDRESS_H_ */