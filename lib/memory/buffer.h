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
 * memory\buffer.h - Defines a memory buffer that provides destination-type functions
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_BUFFER_H_
#define _MEMORY_BUFFER_H_


// required headers
#include "heap.h"
#include "address.h"


namespace wind {


// memory buffer class
// can be type casted to type*
template <typename T>
class buffer
{


public:
	// data
	address<T> Address;
	int	Size;
	heap Heap;


public:
	// initialization
	inline operator T*() const
	{ return Address.Value; }

	inline operator address<T>() const
	{ return Address; }

	inline buffer()
	{ Address = NULL; Size = 0; Heap = heap(); }

	inline buffer(void* addr, uint size, heap hHeap=heap())
	{ Address = addr; Size = size; Heap = hHeap; }

	inline operator buffer<void>() const
	{ return buffer<void>(Address, Size, Heap); }

	inline buffer(const buffer<void> &buff)
	{ Address = buff.Address.Value; Size = buff.Size; Heap = buff.Heap; }

	inline static buffer Create(heap hHeap, uint size, uint flags=0)
	{ return buffer(hHeap.Alloc(size, flags), size, hHeap); }

	inline static buffer Create(uint size, uint flags=0)
	{ return buffer((heap::Default).Alloc(size, flags), size, heap::Default); }

	inline void Destroy(uint flags=0)
	{ if(Heap.IsValid()) Heap.Free(Address, flags); Address = NULL; Size = 0; Heap.Handle = NULL; }

	inline bool Resize(uint size, uint flags=0)
	{
		if(Heap.IsValid()) Address = Heap.ReAlloc(Address, size, flags);
		if(Heap.IsValid() || size <= Size) { Size = size; return true; }
		return false;
	}


	// functions
	inline bool IsValid()
	{ return Address.IsValid(); }

	inline bool CanGrow()
	{ return Heap.IsValid(); }

	inline void Fill(uint size, byte val)
	{ Address.Fill(size, val); }

	inline void Fill(byte val)
	{ Address.Fill(Size, val); }

	inline void FillZero(uint size=Size)
	{ Address.FillZero(size); }

	inline void Copy(const void* src, uint size)
	{ Address.Move(Size, src, size); }

	inline void Move(const void* src, uint size)
	{ Address.Move(Size, src, size); }

	inline int Compare(const void* addr, uint size) const
	{ return Address.Compare(addr, size); }

	inline bool Equals(const void* addr, uint size) const
	{ return Address.Equals(addr, size); }

	inline void* Find(uint size, byte val)
	{ return Address.Find(size, val); }


}; // end class buffer


} // end namespace wind


#endif /* _MEMORY_BUFFER_H_ */