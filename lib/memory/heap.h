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
 * heap.h - Defines a heap wrapper class that provides functions for dynamic memory management
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_HEAP_H_
#define _MEMORY_HEAP_H_


// required headers
#include "heap_func.h"


namespace wind {


// heap wrapper class
// for memory management
class heap
{


public:
	// data
	static heap	Default;
	handle Handle;


public:
	// initialization
	inline static void Begin()
	{ Default.Handle = heap_Begin(); }

	inline static void End()
	{ Default.Handle = NULL; }

	inline operator handle()
	{ return Handle; }

	inline heap(handle hHeap=NULL)
	{ Handle = hHeap; }

	inline static heap Create(uint startSize=0, uint flags=0)
	{ return heap(heap_Create(startSize, flags)); }

	inline void Destroy()
	{ heap_Destroy(Handle); Handle = NULL; }

	// getprocessheaps

	// functions
	inline void* Alloc(uint size, uint flags=0)
	{ return heap_Alloc(Handle, size, flags); }

	inline void* ReAlloc(void* addr, uint size, uint flags=0)
	{ return heap_ReAlloc(Handle, addr, size, flags); }

	inline void Free(void* addr, uint flags=0)
	{ heap_Free(Handle, addr, flags); }

	inline void Optimize(uint flags=0)
	{ heap_Optimize(Handle, flags); }


}; // end class heap


// static heap data
heap heap::Default;


} // end namespace wind


#endif /* _MEMORY_HEAP_H_ */