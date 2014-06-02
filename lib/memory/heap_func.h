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
 * memory\heap_func.h - Provides heap related functions for dynamic memory management
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_HEAP_FUNC_HPP_
#define _MEMORY_HEAP_FUNC_HPP_


// required headers
#include "..\support\keywords.h"
#include "..\support\constants.h"
#include "..\type\primitives.h"
#include "..\type\handle.h"
#if OS == WINDOWS
#include <Windows.h>
#endif


namespace wind
{


// flags
#if OS == WINDOWS
#define	HEAP_EXECUTE_ENABLED		HEAP_CREATE_ENABLE_EXECUTE
#define	HEAP_GENERATES_EXCEPTIONS	HEAP_GENERATE_EXCEPTIONS
#define	HEAP_NOT_SERIALIZED			HEAP_NO_SERIALIZE
#define	HEAP_ZERO_FILLED			HEAP_ZERO_MEMORY
#else
#define	HEAP_EXECUTE_ENABLED		0x00040000
#define	HEAP_GENERATES_EXCEPTIONS	0x00000004
#define	HEAP_NOT_SERIALIZED			0x00000001
#define	HEAP_ZERO_FILLED			0x00000008
#endif


// data
handle	heap_Default;


#if OS == WINDOWS
// initialization
inline handle heap_Begin()
{ return heap_Default = GetProcessHeap(); }

inline void heap_End()
{ heap_Default = NULL; }

inline handle heap_Create(uint startSize=0, uint flags=0)
{ return HeapCreate(flags, startSize, 0); }

inline void heap_Destroy(handle hHeap)
{ HeapDestroy(hHeap); }

// getprocessheaps

// functions
inline void* heap_Alloc(handle hHeap, uint size, uint flags=0)
{ return HeapAlloc(hHeap, flags, size); }

inline void* heap_ReAlloc(handle hHeap, void* addr, uint size, uint flags=0)
{ return HeapReAlloc(hHeap, flags, addr, size); }

inline void heap_Free(handle hHeap, void* addr, uint flags=0)
{ HeapFree(hHeap, flags, addr); }

inline void heap_Optimize(handle hHeap, uint flags=0)
{ HeapCompact(hHeap, flags); }


#else // OS != WINDOWS

// initialization
inline handle heap_Begin()
{ return NULL; }

inline void heap_End()
{ }

inline handle heap_Create(uint startSize=0, uint flags=0)
{ unusedvar(startSize); unusedvar(flags); return 0; }

inline void heap_Destroy(handle hHeap)
{ unusedvar(hHeap); }

// getprocessheaps

// functions
inline void* heap_Alloc(handle hHeap, uint size, uint flags=0)
{ unusedvar(hHeap); unusedvar(flags); return malloc(size); }

inline void* heap_ReAlloc(handle hHeap, void* ptr, uint size, uint flags=0)
{ unusedvar(hHeap); unusedvar(flags); return realloc(ptr, size); }

inline void heap_Free(handle hHeap, void* ptr, uint flags=0)
{ unusedvar(hHeap); unusedvar(flags); free(ptr); }

inline void heap_Optimize(handle hHeap, uint flags = 0)
{ unusedvar(hHeap); unusedvar(flags); }

#endif	// OS == WINDOWS

inline void* heap_Alloc(uint size, uint flags=0)
{ return heap_Alloc(heap_Default, size, flags); }

inline void* heap_ReAlloc(void* addr, uint size, uint flags=0)
{ return heap_ReAlloc(heap_Default, addr, size, flags); }

inline void heap_Free(void* addr, uint flags=0)
{ heap_Free(heap_Default, addr, flags); }

inline void heap_Optimize(uint flags=0)
{ heap_Optimize(heap_Default, flags); }


} // end namespace wind


#endif /* _MEMORY_HEAP_FUNC_HPP_ */