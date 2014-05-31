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
 * memory\block.h - Defines a memory block wrapper class that provides common associated functionality
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_BLOCK_H_
#define _MEMORY_BLOCK_H_


// required headers
#include "address.h"


namespace wind {


// memory block wrapper class
// can be type casted to type*
template <typename T>
class block
{


public:
	// data
	T*	Address;
	int	Size;


public:
	// initialization
	inline block(void* addr=NULL, uint size=0)
	{ Address = (T*) addr; Size = size; }

	inline void operator=(void* ptr)
	{ Address = (T*) ptr; Size = 0; }

	inline operator T*() const
	{ return Address; }

	inline static block Create(void* addr=NULL, uint size=0)
	{ return block(addr, size); }

	inline void Destroy()
	{ Address = NULL; Size = 0; }


	// functions
	inline void Fill(uint size, byte val)
	{ block_Fill(Address, size, val); }

	inline void Fill(byte val)
	{ block_Fill(Address, Size, val); }

	inline void FillZero(uint size=Size)
	{ block_FillZero(Address, size); }

	inline void Copy(const void* src, uint size)
	{ block_Copy(Address, Size, src, size); }

	inline void Move(const void* src, uint size)
	{ block_Move(Address, Size, src, size); }

	inline int Compare(const void* addr, uint size) const
	{ return block_Compare(Address, addr, size); }

	inline bool Equals(const void* addr, uint size) const
	{ return block_Equals(Address, addr, size); }

	inline void* Find(uint size, byte val)
	{ return block_Find(Address, val, size); }


}; // end class block


} // end namespace wind


#endif /* _MEMORY_BLOCK_H_ */