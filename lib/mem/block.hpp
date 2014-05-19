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
 * block.hpp - block memory operations
 */

#ifndef _MEM_BLOCK_HPP_
#define _MEM_BLOCK_HPP_


// required headers
#include <stdlib.h>
#include <string.h>
#include "..\make\const.hpp"
#include "..\type\basic.hpp"
#if OS == WINDOWS
#include <Windows.h>
#endif


namespace wind
{


// memory info
#if OS == WINDOWS
HANDLE	mem_Heap;
#endif


// memory prepare
inline void mem_Begin()
{
#if OS == WINDOWS
	mem_Heap = GetProcessHeap();
#endif
}


// functions
inline void mem_Set(void* dst, uint size, byte val)
{ memset(dst, val, size); }

inline void mem_Fill(void* dst, uint size, byte val)
{ mem_Set(dst, size, val); }

inline word mem_Compare(const void* ptr1, const void* ptr2, uint size)
{ return (byte) memcmp(ptr1, ptr2, size); }

inline void mem_Copy(void* dst, const void* src, uint size)
{ memcpy(dst, src, size); }

inline void mem_Copy(void* dst, uint dstSize, const void* src, uint size)
{ memcpy_s(dst, dstSize, src, size); }

inline void mem_Move(void* dst, const void* src, uint size)
{ memmove(dst, src, size); }

inline void mem_Move(void* dst, uint dstSize, const void* src, uint size)
{ memmove_s(dst, dstSize, src, size); }

inline void* mem_IndexOf(void* ptr, uint size, byte val)
{ return memchr(ptr, val, size); }

inline void* mem_Find(void* ptr, uint size, byte val)
{ return mem_IndexOf(ptr, size, val); }

inline bool mem_Equals(const void* ptr1, const void* ptr2, uint size)
{ return !mem_Compare(ptr1, ptr2, size); }

inline void mem_Init(void* dst, uint size)
{ mem_Set(dst, size, 0); }


// memory flags
#if OS == WINDOWS
#ifndef INITIALIZE
#define	INITIALIZE			HEAP_ZERO_MEMORY
#endif // !INITIALIZE
#else // NONE
#ifndef INITIALIZE
#define	INITIALIZE			0x0008
#endif // !INITIALIZE
#endif


// allocate
#if OS == WINDOWS
inline void* mem_Alloc(HANDLE heap, uint size, uint flags)
{ return HeapAlloc(heap, flags, size); }

inline void* mem_Alloc(uint size, uint flags)
{ return mem_Alloc(mem_Heap, size, flags); }

inline void* mem_Alloc(uint size)
{ return mem_Alloc(mem_Heap, size, 0); }

#else // NONE
inline void* mem_Alloc(uint heap, uint size, uint flags)
{
	unused(heap);
	if(flags & INITIALIZE) return calloc(size, 1);
	else return malloc(size);
}

inline void* mem_Alloc(uint size, uint flags)
{ return mem_Alloc(0, size, flags); }

inline void* mem_Alloc(uint size)
{ return mem_Alloc(0, size, 0); }
#endif


// reallocate
#if OS == WINDOWS
inline void* mem_ReAlloc(HANDLE heap, void* ptr, uint size, uint flags)
{ return HeapReAlloc(heap, flags, ptr, size); }

inline void* mem_ReAlloc(void* ptr, uint size, uint flags)
{ return mem_ReAlloc(mem_Heap, ptr, size, flags); }

inline void* mem_ReAlloc(void* ptr, uint size)
{ return mem_ReAlloc(mem_Heap, ptr, size, 0); }

#else // NONE
inline void* mem_ReAlloc(uint heap, void* ptr, uint size, uint flags)
{
	unused(heap);
	ptr = realloc(ptr, size);
	if(flags & INITIALIZE) mem_Init(ptr, size);
	return ptr;
}

inline void* mem_ReAlloc(void* ptr, uint size, uint flags)
{ return mem_ReAlloc(mem_Heap, ptr, size, flags); }

inline void* mem_ReAlloc(void* ptr, uint size, uint flags)
{ return mem_ReAlloc(mem_Heap, ptr, size, 0); }
#endif


// free
#if OS == WINDOWS
inline void mem_Free(HANDLE heap, void* ptr)
{ HeapFree(heap, 0, ptr); }

inline void mem_Free(void* ptr)
{ mem_Free(mem_Heap, ptr); }

#else // NONE

inline void mem_Free(uint heap, void* ptr)
{
	unused(heap);
	free(ptr);
}

inline void mem_Free(void* ptr)
{ mem_Free(ptr); }
#endif


// compact
#if OS == WINDOWS
inline uint mem_Compact(HANDLE heap)
{ return HeapCompact(heap, 0); }

inline uint mem_Compact()
{ return mem_Compact(mem_Heap); }

#else

inline uint mem_Compact(uint heap)
{
	unused(heap);
	return 0;
}

inline uint mem_Compact()
{ return mem_Compact(mem_Heap); }
#endif


} // end namespace wind


#endif /* _MEM_BLOCK_HPP_ */