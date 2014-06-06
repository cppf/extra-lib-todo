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
#include "block.h"


namespace wind {


// memory buffer class
// can be type casted to type*
template <typename T>
class buffer : public block<T>
{


public:
	// data
	heap Heap;


public:
	// initialization
	inline buffer(void* addr=NULL, uint size=0)
	{ Address = NULL; Size = 0; Heap = heap(); }

	inline buffer(void* addr, uint size, heap hHeap=heap())
	{ Address = addr; Size = size; Heap = hHeap; }

	inline operator buffer<byte>() const
	{ return buffer<byte>(Address, Size, Heap); }

	inline buffer(const buffer<byte> &buff)
	{ Address = buff.Address.Value; Size = buff.Size; Heap = buff.Heap; }

	inline static buffer Create(heap hHeap, uint size, uint flags=0)
	{ return buffer(hHeap.Alloc(size, flags), size, hHeap); }

	inline static buffer Create(uint size, uint flags=0)
	{ return buffer((heap::Default).Alloc(size, flags), size, heap::Default); }

	inline void Destroy(uint flags=0)
	{
		if(Heap.IsValid()) Heap.Free(Address, flags);
		Address = NULL; Size = 0; Heap.Handle = NULL;
	}

	inline bool Resize(uint size, uint flags=0)
	{
		if(Heap.IsValid()) { Address = Heap.ReAlloc(Address, size, flags); }
		if(Heap.IsValid() || size <= Size) { Size = size; return true; }
		return false;
	}


	// functions
	inline bool IsValid()
	{ return Address.IsValid(); }

	inline bool CanGrow()
	{ return Heap.IsValid(); }

	inline buffer Begin(int off=0, uint size=0)
	{ return buffer(Address+off, size); }

	inline buffer End(int off=0, uint size=0)
	{ return buffer(Address+Size+off, size); }

	inline buffer BeginFull(int off=0, int sizeOff=0)
	{ return buffer(Address+off, (uint)(Size+sizeOff)); }

	inline buffer EndFull(int off=0, int sizeOff=0)
	{ return buffer(Address+Size+off, (uint)(Size+sizeOff)); }

	inline void Fill(T val, uint size=Size)
	{ Address.Fill(val, size); }

	inline void FillZero(uint size=Size)
	{ Address.FillZero(size); }

	inline void Copy(const void* src, uint size=Size)
	{ Address.Move(Size, src, size); }

	inline void Move(const void* src, uint size=Size)
	{ Address.Move(Size, src, size); }

	inline int Compare(const T* addr, uint size=Size) const
	{ return Address.Compare(addr, size); }

	inline bool Equals(const T* addr, uint size=Size) const
	{ return Address.Equals(addr, size); }

	inline address<T> Find(T val, uint size=Size) const
	{ return Address.Find(val, size); }

	inline address<T> FindLast(T val, uint size=Size) const
	{ return Address.FindLast(val, size); }

	inline int IndexOf(T val, uint size=Size) const
	{ return Address.IndexOf(val, size); }

	inline int IndexOfLast(T val, uint size=Size) const
	{ return Address.IndexOfLast(val, size); }


}; // end class buffer


} // end namespace wind


#endif /* _MEMORY_BUFFER_H_ */