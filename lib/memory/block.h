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
	uint Length;


public:
	// initialization
	inline block(void* addr=NULL, uint len=0)
	{ Address = addr; Length = len; }

	template <typename Tsrc>
	inline block(block<Tsrc> &blk)
	{ Address = (T*) blk.Address; Length = blk.Length; }

	inline static block create(void* addr=NULL, uint len=0)
	{ return block(addr, len); }

	inline void destroy()
	{ Address = NULL; Length = 0; }


	// operator overload
	inline operator T*() const
	{ return Address; }

	inline operator block<byte>() const
	{ return block<byte>(Address, Length); }


	// properties
	inline T* address() const
	{ return Address; }

	inline uint size() const
	{ return Length * sizeof(T); }

	inline uint length() const
	{ return Length; }

	inline uint count() const
	{ return Length; }

	inline uint capacity() const
	{ return 0; }


	// non-modifier functions
	inline bool isValid() const
	{ return Address != NULL; }
	
	inline block part(int off=0, uint len=0) const
	{ return block(Address+off, len); }

	inline int compare(block src) const
	{
		uint cmpSz = (Length < src.Length)? Length : src.Length;
		T cmp = wind::compare(Address, src, cmpSz);
		return (cmp)? cmp : (Length - src.Length);
	}

	inline bool equals(block src) const
	{ return (Length == src.Length) && wind::equals(Address, src, Length); }

	inline block find(T val) const
	{ return block(wind::find(Address, Length, val), 1); }

	inline block find(block src) const
	{ return block(wind::find(Address, Length, src, src.Length), src.Length); }

	inline block findAny(block src) const
	{ return block(wind::findAny(Address, Length, src, src.Length), 1); }

	inline block findLast(T val) const
	{ return block(wind::findLast(Address, Length, val), 1); }

	inline block findLast(block src) const
	{ return block(wind::findLast(Address, Length, src, src.Length), src.Length); }

	inline block findLastAny(block src) const
	{ return block(wind::findLastAny(Address, Length, src, src.Length), 1); }

	inline int indexOf(T val) const
	{ return wind::indexOf(Address, Length, val); }

	inline int indexOf(block src) const
	{ return wind::indexOf(Address, Length, src, src.Length); }

	inline int indexOfAny(block src) const
	{ return wind::indexOfAny(Address, Length, src, src.Length); }

	inline int lastIndexOf(T val) const
	{ return wind::lastIndexOf(Address, Length, val); }

	inline int lastIndexOf(block src) const
	{ return wind::lastIndexOf(Address, Length, src, src.Length); }

	inline int lastIndexOfAny(block src) const
	{ return wind::lastIndexOfAny(Address, Length, src, src.Length); }

	inline uint count(T val) const
	{ return wind::count(Address, Length, val); }

	inline uint count(block src) const
	{ return wind::count(Address, Length, src, src.Length); }

	inline uint countAny(block src) const
	{ return wind::countAny(Address, Length, src, src.Length); }


	// modifier functions
	inline block fill(T val)
	{ wind::fill(Address, Length, val); return *this; }

	inline block fillZero()
	{ wind::fillZero(Address, Length); return *this; }

	inline block copyFrom(block src)
	{ wind::copyFrom(Address, src, src.Length); return block(Address, src.Length); }

	inline block moveFrom(block src)
	{ wind::moveFrom(Address, src, src.Length); return block(Address, src.Length); }

	inline block reverse()
	{ wind::reverse(Address, Length); return *this; }
	
	inline block reverseFrom(block src)
	{ wind::reverseFrom(Address, src, src.Length); }

	inline block expandAt(int off, uint len=1)
	{ wind::moveFrom(Address+off+len, Address+off, Length-off); return block(Address, Length+len); }

	inline block insertAt(int off, T val)
	{ block_Move(Address+off+1, Address+off, Size-off); Address[off] = val; return block(Address, Size+1);  }

	inline block insertAt(int off, block src)
	{ block_Move(Address+off+src.Size, Address+off, Size-off); block_Copy(Address+off, src, src.Size); return block(Address, Size+src.Size); }

	inline block RemoveAt(int off, uint size=1)
	{ block_Move(Address+off, Address+off+size, size); return block(Address, Size-size); }

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