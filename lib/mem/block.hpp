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
 * block.hpp - memory block wrapper
 */

#ifndef _MEM_BLOCK_HPP_
#define _MEM_BLOCK_HPP_


// required headers
#include "..\make\const.hpp"
#include "..\type\basic.hpp"
#include "address.hpp"
#if OS == WINDOWS
#include <Windows.h>
#endif


namespace wind
{


// memory block wrapper class
// can be type casted to type*
template <typename T>
class block
{
public:


	// block value
	T*	Address;
	int	Size;


	// for type conversion
	inline block(T* addr=NULL, uint size=0)
	{ Address = addr; Size = size; }

	inline void operator=(T* ptr)
	{ Address = ptr; Size = 0; }

	inline operator T*() const
	{ return Address; }


	// block operations
#if OS == WINDOWS
	inline void Fill(uint size, byte val)
	{ FillMemory(Value, size, val); }

	inline void FillZero(uint size)
	{ ZeroMemory(Value, size); }

	inline void CopyFrom(const void* src, uint size)
	{ CopyMemory(Value, src, size); }

	inline void MoveFrom(const void* src, uint size)
	{ MoveMemory(Value, src, size); }

#else // OS != WINDOWS
	inline void Fill(uint size, byte val)
	{ memset(Value, size, val); }

	inline void FillZero(uint size)
	{ memset(Value, size, 0); }

	inline void CopyFrom(const void* src, uint size)
	{ memcpy(Value, src, size); }

	inline void MoveFrom(const void* src, uint size)
	{ memmove(Value, src, size); }
#endif

	inline int Compare(const void* ptr, uint size) const
	{ return memcmp(Value, ptr, size); }

	inline bool Equals(const void* ptr, uint size) const
	{ return !Compare(ptr, size); }

	inline void CopyFrom(uint dstSize, const void* src, uint size)
	{ memcpy_s(Value, dstSize, src, size); }

	inline void MoveFrom(uint dstSize, const void* src, uint size)
	{ memmove_s(Value, dstSize, src, size); }

	inline void* Find(uint size, byte val)
	{ return memchr(Value, val, size); }


}; // end class pointer


} // end namespace wind


#endif /* _MEM_POINTER_HPP_ */