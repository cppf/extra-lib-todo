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
#define mem_Set			memset
#define	mem_Fill		memset
#define mem_Compare		memcmp
#define mem_Copy		memcpy
#define mem_Move		memmove
#define mem_IndexOf		memchr
#define mem_Find		memchr

#define	mem_Equals(mem1, mem2, size)	(!mem_Compare(mem1, mem2, size))
#define	mem_Init(dst, size)				mem_Set(dst, size, 0)


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
#define	mem_Alloc3(heap, size, flags)	HeapAlloc(heap, flags, size)
#define	mem_Alloc2(size, flags)			HeapAlloc(mem_Heap, flags, size)
#define	mem_Alloc1(size)				HeapAlloc(mem_Heap, 0, size)
#else // NONE
inline void* mem_Alloc3F(uint size, uint flags)
{
	if(flags & INITIALIZE) return calloc(size, 1);
	else return malloc(size);
}
#define	mem_Alloc3(heap, size, flags)	mem_Alloc3F(size, flags)
#define	mem_Alloc2(size, flags)			mem_Alloc3F(size, flags)
#define	mem_Alloc1(size)				malloc(size)
#endif

#define	mem_Alloc(...)	\
macro_Fn(macro_Fn3(__VA_ARGS__, mem_Alloc3, mem_Alloc2, mem_Alloc1)(__VA_ARGS__))


// reallocate
#if OS == WINDOWS
#define	mem_ReAlloc4(heap, ptr, size, flags)	HeapReAlloc(heap, flags, ptr, size)
#define	mem_ReAlloc3(ptr, size, flags)			HeapReAlloc(mem_Heap, flags, ptr, size)
#define	mem_ReAlloc2(ptr, size)					HeapReAlloc(mem_Heap, 0, ptr, size)
#else // NONE
inline void* mem_ReAlloc4F(void* ptr, uint size, uint flags)
{
	ptr = realloc(ptr, size);
	if(flags & INITIALIZE) mem_Init(ptr, size);
	return ptr;
}
#define	mem_ReAlloc4(heap, ptr, size, flags)	mem_ReAlloc4F(ptr, size, flags)
#define	mem_ReAlloc3(ptr, size, flags)			mem_ReAlloc4F(ptr, size, flags)
#define	mem_ReAlloc2(ptr, size)					realloc(ptr, size)
#endif

#define	mem_Alloc(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, mem_ReAlloc4, mem_ReAlloc3, mem_ReAlloc2)(__VA_ARGS__))


// free
#if OS == WINDOWS
#define	mem_Free2(heap, ptr)	HeapFree(heap, 0, ptr)
#define	mem_Free1(ptr)			HeapFree(mem_Heap, 0, ptr)
#else // NONE
#define	mem_Free2(heap, ptr)	free(ptr)
#define	mem_Free1(ptr)			free(ptr)
#endif

#define	mem_Free(...)	\
macro_Fn(macro_Fn2(__VA_ARGS__, mem_Free2, mem_Free1))(__VA_ARGS__)


// compact
#if OS == WINDOWS
#define	mem_Compact1(heap)		HeapCompact(heap, 0)
#define	mem_Compact0()			HeapCompact(mem_Heap, 0)
#else
#define	mem_Compact1(heap)
#define	mem_Compact0()
#endif

#define	mem_Compact(...)	\
macro_Fn(macro_Fn1(__VA_ARGS__, mem_Compact1, mem_Compact0))(__VA_ARGS__)


#endif /* _MEM_BLOCK_HPP_ */