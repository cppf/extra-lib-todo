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
 * memory\block.h - Defines a memory block that provides destination-type functions
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_BLOCK_H_
#define _MEMORY_BLOCK_H_


// required headers
#include "block_func.h"


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

	inline block(block<byte> &blk)
	{ Address = blk.Address; Size = blk.Size; }

	inline operator block<byte>() const
	{ return block<byte>(Address, Size); }

	inline static block Create(void* addr=NULL, uint size=0)
	{ return block(addr, size); }

	inline void Destroy()
	{ Address = NULL; Size = 0; }


	// non-modifier functions
	inline bool IsValid() const
	{ return Address != NULL; }
	
	inline block Part(int off=0, uint size=0) const
	{ return block(Address+off, size); }
	
	inline block Merge(block src) const
	{
		uint psrc = src;
		if(src.Address > Address+Size) block_Copy(psrc=Address+Size, src, src.Size);
		return block(Address, psrc + src.Size - Address);
	}

	inline int Compare(block src) const
	{
		uint cmpSz = (Size < src.Size)? Size : src.Size;
		T cmp = block_Compare(Address, src, cmpSz);
		return (cmp)? cmp : (Size - src.Size);
	}

	inline bool Equals(block src) const
	{ return (Size == src.Size) && (block_Compare(Address, src, Size) == 0); }

	inline block Find(T val) const
	{ return block(block_Find(Address, Size, val), 1); }

	inline block Find(block src) const
	{ return block(block_Find(Address, Size, src, src.Size), src.Size); }

	inline block FindAny(block src) const
	{ return block(block_FindAny(Address, Size, src, src.Size), 1); }

	inline block FindLast(T val) const
	{ return block(block_FindLast(Address, Size, val), 1); }

	inline block FindLast(block src) const
	{ return block(block_FindLast(Address, Size, src, src.Size), src.Size); }

	inline block FindLastAny(block src) const
	{ return block(block_FindLastAny(Address, Size, src, src.Size), 1); }

	inline int IndexOf(T val) const
	{ return block_IndexOf(Address, Size, val); }

	inline int IndexOf(block src) const
	{ return block_IndexOf(Address, Size, src, src.Size); }

	inline int IndexOfAny(block src) const
	{ return block_IndexOfAny(Address, Size, src, src.Size); }

	inline int LastIndexOf(T val) const
	{ return block_LastIndexOf(Address, Size, val); }

	inline int LastIndexOf(block src) const
	{ return block_LastIndexOf(Address, Size, src, src.Size); }

	inline int LastIndexOfAny(block src) const
	{ return block_LastIndexOfAny(Address, Size, src, src.Size); }


	// modifier functions
	inline block Fill(T val)
	{ block_Fill(Address, Size, val); return *this; }

	inline block FillZero()
	{ block_FillZero(Address, Size, val); return *this; }

	inline block CopyFrom(block src)
	{ block_Copy(Address, src, src.Size); return block(Address, src.Size); }

	inline block MoveFrom(block src)
	{ block_Move(Address, src, src.Size); return block(Address, src.Size); }

	inline block Convert(T* type)
	{ block_Convert(Address, Address, Size); return *this; }

	inline block Reverse()
	{ block_Reverse(Address, Size); return *this; }

	inline block ExpandAt(int off, uint size=1)
	{ block_Move(Address+off+size, Address+off, Size-off); return block(Address, Size+size); }

	inline block InsertAt(int off, T val)
	{ block_Move(Address+off+1, Address+off, Size-off); Address[off] = val; return block(Address, Size+1);  }

	inline block InsertAt(int off, block src)
	{ block_Move(Address+off+src.Size, Address+off, Size-off); block_Copy(Address+off, src, src.Size); return block(Address, Size+src.Size); }

	inline block RemoveAt(int off, uint size=1)
	{ block_Move(Address+off, Address+off+size, size); return block(Address, Size-size); }

	inline uint Count(T val)
	{ return block_Count(Address, Size, val); }

	inline block Remove(T val)
	{ uint rmvd = block_Remove(Address, Address, Size, val); return block(Address, Size-rmvd); }

	inline block Remove(block src)
	{  }

	inline block Replace(T find, T replace)
	{ block_Replace(Address, Size, find, replace); return *this; }

	template <typename Tsrc>
	inline block Add(block<Tsrc> src)
	{ block_Convert(Address+Size, src, src.Size); return block(Address, Size+src.Size); }




}; // end class block


} // end namespace wind


#endif /* _MEMORY_BLOCK_H_ */