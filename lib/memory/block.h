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
#include "block_func.h"
#include "address.h"


namespace wind {


// memory block wrapper class
// can be type casted to type*
template <typename T>
class block
{


public:
	// data
	address<T> Address;
	int	Size;
#if HEAP_MODE == MULTI_HEAP
	heap Heap;
#endif


public:
	// initialization
	inline operator address<T>() const
	{ return Address; }

#if HEAP_MODE == MULTI_HEAP
	inline operator block<void>() const
	{ return block<void>(Address, Size, Heap); }

	inline void operator=(const block<void> &blk)
	{ Address = blk.Address; Size = blk.Size; Heap = blk.Heap; }

	inline block(const block<void> &blk)
	{ Address = blk.Address; Size = blk.Size; Heap = blk.Heap; }

	inline block()
	{ Address = NULL; Size = 0; Heap = heap(); }

	inline block(void* addr, uint size, heap hHeap=heap())
	{ Address = addr; Size = size; Heap = hHeap; }

	inline static block Create(heap hHeap, uint size, uint flags=0)
	{ return block(block_Create(hHeap, size, flags), size, hHeap); }

	inline static block Create(uint size, uint flags=0)
	{ return block(block_Create(size, flags), size, heap::Default); }

	inline void Destroy(uint flags=0)
	{ block_Destroy(Heap, Address, flags); Address = NULL; Size = 0; Heap.Handle = NULL; }

	inline void Resize(uint size, uint flags=0)
	{ Address = block_Resize(Heap, Address, size, flags); Size = size; }


#else

	inline operator block<void>() const
	{ return block<void>(Address, Size); }

	inline void operator=(const block<void> &blk)
	{ Address = blk.Address; Size = blk.Size; }

	inline block(const block<void> &blk)
	{ Address = blk.Address; Size = blk.Size; }

	inline block()
	{ Address = NULL; Size = 0; }

	inline block(void* addr, uint size)
	{ Address = addr; Size = size; }

	inline static block Create(heap hHeap, uint size, uint flags=0)
	{ return block(block_Create(hHeap, size, flags), size); }

	inline static block Create(uint size, uint flags=0)
	{ return block(block_Create(size, flags), size); }

	inline void Destroy(heap hHeap, uint flags=0)
	{ block_Destroy(hHeap, Address, flags); Address = NULL; Size = 0; }

	inline void Destroy(uint flags=0)
	{ block_Destroy(Address, flags); Address = NULL; Size = 0; }

	inline void Resize(heap hHeap, uint size, uint flags=0)
	{ Address = block_Resize(hHeap, Address, size, flags); Size = size; }

	inline void Resize(uint size, uint flags=0)
	{ Address = block_Resize(Address, size, flags); Size = size; }
#endif


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