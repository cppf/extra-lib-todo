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
 * mem\address.h - memory address wrapper class
 */

#ifndef _MEM_ADDRESS_H_
#define _MEM_ADDRESS_H_


// required headers
#include "memF.h"


#ifdef __cplusplus
namespace wind {
#endif


// memory address wrapper class
// can be type casted to type*
template <typename T>
class address
{


public:
	// address value
	T* Value;


public:
	// initialization
	inline address(void* addr=NULL)
	{ Value = (T*) addr; }

	inline void operator=(void* addr)
	{ Value = (T*) addr; }

	inline operator T*() const
	{ return Value; }


	// functions
	inline void Fill(uint size, byte val)
	{ mem_Fill(Value, size, val); }

	inline void FillZero(uint size)
	{ mem_FillZero(Value, size); }

	inline void Copy(const void* src, uint size)
	{ mem_Copy(Value, src, size); }

	inline void Copy(uint dstSize, const void* src, uint size)
	{ mem_Copy(Value, dstSize, src, size); }

	inline void Move(const void* src, uint size)
	{ mem_Move(Value, src, size); }

	inline void Move(uint dstSize, const void* src, uint size)
	{ mem_Move(Value, dstSize, src, size); }

	inline int Compare(const void* addr, uint size) const
	{ return mem_Compare(Value, addr, size); }

	inline bool Equals(const void* addr, uint size) const
	{ return mem_Compare(Value, addr, size); }

	inline void* Find(uint size, byte val)
	{ return mem_Find(Value, size, val); }


}; // end class address


#ifdef __cplusplus
} // end namespace wind
#endif


#endif /* _MEM_ADDRESS_H_ */