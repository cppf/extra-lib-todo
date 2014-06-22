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
#include "heap_func.h"


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
	inline heap(handle hHeap=NULL)
	{ Handle = hHeap; }

	inline static void startup()
	{ Default.Handle = defaultHeap(); }

	inline static void cleanup()
	{ Default.Handle = NULL; }

	inline static heap create(uint startSize=0, uint flags=0)
	{ return createHeap(startSize, flags);; }

	inline void destroy()
	{ destroyHeap(Handle); Handle = NULL; }


	// operator overload
	inline operator handle() const
	{ return Handle; }


	// properties
	inline handle handle()
	{ return Handle; }

	static inline heap default()
	{ return Default; }


	// functions
	inline bool isValid() const
	{ return Handle != NULL; }

	inline void* alloc(uint size, uint flags=0) const
	{ return wind::alloc(Handle, size, flags); }

	inline void* reAlloc(void* addr, uint size, uint flags=0) const
	{ return wind::reAlloc(Handle, addr, size, flags); }

	inline void free(void* addr, uint flags=0) const
	{ wind::free(Handle, addr, flags); }

	inline void optimize(uint flags=0) const
	{ optimizeHeap(Handle, flags); }


}; // end class heap


// static heap data
heap heap::Default;


} // end namespace wind


#endif /* _MEMORY_HEAP_H_ */