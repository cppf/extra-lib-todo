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
 * memory\buffer.h - Defines a memory buffer that provides common associated functionality
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_BUFFER_H_
#define _MEMORY_BUFFER_H_


// required headers
#include "buffer_func.h"


namespace wind {


// memory buffer class
// can be type casted to type*
template <typename T>
class buffer
{


public:
	// data
	T* Address;
	int	Size;
#if HEAP_MODE == MULTI_HEAP
	heap Heap;
#endif


public:
	// initialization
	inline operator T*() const
	{ return Address; }

#if HEAP_MODE == MULTI_HEAP
	inline buffer()
	{ Address = NULL; Size = 0; Heap = heap(); }

	inline buffer(void* addr, uint size, heap hHeap=heap())
	{ Address = (T*) addr; Size = size; Heap = hHeap; }

	inline operator buffer<void>() const
	{ return buffer<void>(Address, Size, Heap); }

	inline void operator=(const buffer<void> &buff)
	{ Address = (T*) buff.Address; Size = buff.Size; Heap = buff.Heap; }

	inline buffer(const buffer<void> &buff)
	{ Address = (T*) buff.Address; Size = buff.Size; Heap = buff.Heap; }

	inline static buffer Create(heap hHeap, uint size, uint flags=0)
	{ return buffer(buffer_Create(hHeap, size, flags), size, hHeap); }

	inline static buffer Create(uint size, uint flags=0)
	{ return buffer(buffer_Create(size, flags), size, heap::Default); }

	inline void Destroy(uint flags=0)
	{ buffer_Destroy(Heap, Address, flags); Address = NULL; Size = 0; Heap.Handle = NULL; }

	inline void Resize(uint size, uint flags=0)
	{ Address = (T*) buffer_Resize(Heap, Address, size, flags); Size = size; }


#else

	inline buffer()
	{ Address = NULL; Size = 0; }

	inline buffer(void* addr, uint size)
	{ Address = (T*) addr; Size = size; }

	inline operator buffer<void>() const
	{ return buffer<void>(Address, Size); }

	inline void operator=(const buffer<void> &blk)
	{ Address = (T*) blk.Address; Size = blk.Size; }

	inline buffer(const buffer<void> &blk)
	{ Address = (T*) blk.Address; Size = blk.Size; }

	inline static buffer Create(heap hHeap, uint size, uint flags=0)
	{ return buffer(buffer_Create(hHeap, size, flags), size); }

	inline static buffer Create(uint size, uint flags=0)
	{ return buffer(buffer_Create(size, flags), size); }

	inline void Destroy(heap hHeap, uint flags=0)
	{ buffer_Destroy(hHeap, Address, flags); Address = NULL; Size = 0; }

	inline void Destroy(uint flags=0)
	{ buffer_Destroy(Address, flags); Address = NULL; Size = 0; }

	inline void Resize(heap hHeap, uint size, uint flags=0)
	{ Address = (T*) buffer_Resize(hHeap, Address, size, flags); Size = size; }

	inline void Resize(uint size, uint flags=0)
	{ Address = (T*) buffer_Resize(Address, size, flags); Size = size; }
#endif


	// functions
	inline void Fill(uint size, byte val)
	{ buffer_Fill(Address, size, val); }

	inline void Fill(byte val)
	{ buffer_Fill(Address, Size, val); }

	inline void FillZero(uint size=Size)
	{ buffer_FillZero(Address, size); }

	inline void Copy(const void* src, uint size)
	{ buffer_Copy(Address, Size, src, size); }

	inline void Move(const void* src, uint size)
	{ buffer_Move(Address, Size, src, size); }

	inline int Compare(const void* addr, uint size) const
	{ return buffer_Compare(Address, addr, size); }

	inline bool Equals(const void* addr, uint size) const
	{ return buffer_Equals(Address, addr, size); }

	inline void* Find(uint size, byte val)
	{ return buffer_Find(Address, val, size); }


}; // end class buffer


} // end namespace wind


#endif /* _MEMORY_BUFFER_H_ */