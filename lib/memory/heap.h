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
 * heap.h - Defines a heap that provides destination-type functions for dynamic memory management
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_HEAP_H_
#define _MEMORY_HEAP_H_


// required headers
#include "..\support\keywords.h"
#include "..\support\constants.h"
#include "..\type\primitives.h"
#if OS == WINDOWS
#include <Windows.h>
#else
#include <stdlib.h>
#endif


namespace wind {


// heap class for memory management
// can be type casted to handle
class heap
{


public:
	// data
	static heap	Default;
	handle Handle;


public:
	// initialization
	inline operator handle()
	{ return Handle; }

	inline heap(handle hHeap=NULL)
	{ Handle = hHeap; }

#if OS == WINDOWS
	inline static void Begin()
	{ Default.Handle = GetProcessHeap(); }

	inline static void End()
	{ Default.Handle = NULL; }

	inline static heap Create(uint startSize=0, uint flags=0)
	{ return heap(HeapCreate(flags, startSize, 0)); }

	inline void Destroy()
	{ HeapDestroy(Handle); Handle = NULL; }

#else // OS != WINDOWS

	inline static void Begin()
	{ Default.Handle = (handle) 1; }

	inline static void End()
	{ Default.Handle = NULL; }

	inline static heap Create(uint startSize=0, uint flags=0)
	{ unusedpar(startSize); unusedpar(flags); return heap((handle) 1); }

	inline void Destroy()
	{ Handle = NULL; }
#endif // OS == WINDOWS

	// functions
	inline bool IsValid()
	{ return Handle != NULL; }

#if OS == WINDOWS
	inline void* Alloc(uint size, uint flags=0)
	{ return HeapAlloc(Handle, flags, size); }

	inline void* ReAlloc(void* addr, uint size, uint flags=0)
	{ return HeapReAlloc(Handle, flags, addr, size); }

	inline void Free(void* addr, uint flags=0)
	{ HeapFree(Handle, flags, addr); }

	inline void Optimize(uint flags=0)
	{ HeapCompact(Handle, flags); }

	// getprocessheaps
#else // OS != WINDOWS
	inline void* Alloc(uint size, uint flags=0)
	{ unusedpar(flags); return malloc(size); }

	inline void* ReAlloc(void* addr, uint size, uint flags=0)
	{ unusedpar(flags); return realloc(addr, size); }

	inline void Free(void* addr, uint flags=0)
	{ unusedpar(flags); free(addr); }

	inline void Optimize(uint flags=0)
	{ unusedpar(flags); }

	// getprocessheaps
#endif // OS == WINDOWS


}; // end class heap


// static heap data
heap heap::Default;


} // end namespace wind


#endif /* _MEMORY_HEAP_H_ */