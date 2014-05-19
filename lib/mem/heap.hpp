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
 * heap.hpp - heap wrapper
 */

#ifndef _MEM_HEAP_HPP_
#define _MEM_HEAP_HPP_


// required headers
#include "..\make\const.hpp"
#include "..\type\basic.hpp"
#if OS == WINDOWS
#include <Windows.h>
#endif


namespace wind
{


// heap wrapper class
// for memory allocation ...
class heap
{


// flags
#if OS == WINDOWS
#define	EXECUTE_ENABLED			HEAP_CREATE_ENABLE_EXECUTE,
#define	GENERATES_EXCEPTIONS	HEAP_GENERATE_EXCEPTIONS,
#define	NOT_SERIALIZED			HEAP_NO_SERIALIZE
#define	INITIALIZED				HEAP_ZERO_MEMORY
#else
#define	EXECUTE_ENABLED			0x00040000
#define	GENERATES_EXCEPTIONS	0x00000004
#define	NOT_SERIALIZED			0x00000001
#define	INITIALIZED				0x00000008
#endif


// default handle, heap handle
public:
#if OS == WINDOWS
	static heap	Default;
	HANDLE		Handle;
#endif


public:
#if OS == WINDOWS
	// static functions
	inline static void Begin()
	{ *( (HANDLE*)&Default ) = GetProcessHeap(); }

	inline static heap GetDefault()
	{ return heap::Default; }

	// getprocessheaps


	// create and destroy
	inline heap(uint initialSize=0, uint maxSize=0, uint flags=0)
	{ Handle = HeapCreate(flags, initialSize, maxSize); }

	inline void Destroy()
	{ HeapDestroy(Handle); Handle = NULL; }

	// allocation functions...
	inline void* Alloc(uint size, uint flags=0)
	{ return HeapAlloc(Handle, flags, size); }

	inline void* ReAlloc(void* ptr, uint size, uint flags=0)
	{ return HeapReAlloc(Handle, flags, ptr, size); }

	inline void Free(void* ptr, uint flags=0)
	{ HeapFree(Handle, flags, ptr); }

	inline uint SizeOf(void* ptr, uint flags=0)
	{ return HeapSize(Handle, flags, ptr); }

	inline void Lock()
	{ HeapLock(Handle); }

	inline void Unlock()
	{ HeapUnlock(Handle); }

	inline void Compact(uint flags = 0)
	{ HeapCompact(Handle, flags); }

#else // OS != WINDOWS

	// static functions
	inline static void Begin()
	{ }

	inline static heap GetDefault()
	{ return heap(); }

	// getprocessheaps


	// create and destroy
	inline heap(uint initialSize=0, uint maxSize=0, uint flags=0)
	{ unused(initialSize); unused(maxSize); unused(flags); }


	// allocation functions...
	inline void* Alloc(uint size, uint flags=0)
	{ unused(flags); return malloc(size); }

	inline void* ReAlloc(void* ptr, uint size, uint flags=0)
	{ unused(flags); return realloc(ptr, size); }

	inline void Free(void* ptr, uint flags=0)
	{ unused(flags); free(ptr); }

	inline uint SizeOf(void* ptr, uint flags=0)
	{ unused(ptr); unused(flags); return 0; }

	inline void Lock()
	{ }

	inline void Unlock()
	{ }

	inline void Compact(uint flags = 0)
	{ unused(flags); }

#endif	// OS == WINDOWS


}; // end class heap


} // end namespace wind


#endif /* _TYPE_HEAP_HPP_ */