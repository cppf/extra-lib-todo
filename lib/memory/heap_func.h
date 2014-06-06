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
 * heap.h - Provides destination-type heap functions for dynamic memory management
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_HEAP_FUNC_H_
#define _MEMORY_HEAP_FUNC_H_


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


#if OS == WINDOWS
inline handle heap_GetDefault()
{ return GetProcessHeap(); }

inline handle heap_Create(uint startSize=0, uint flags=0)
{ return HeapCreate(flags, startSize, 0); }

inline void heap_Destroy(handle hHeap)
{ HeapDestroy(hHeap); }

inline void* heap_Alloc(handle hHeap, uint size, uint flags=0)
{ return HeapAlloc(hHeap, flags, size); }

inline void* heap_ReAlloc(handle hHeap, void* addr, uint size, uint flags=0)
{ return HeapReAlloc(hHeap, flags, addr, size); }

inline void heap_Free(handle hHeap, void* addr, uint flags=0)
{ HeapFree(hHeap, flags, addr); }

inline void heap_Optimize(handle hHeap, uint flags=0)
{ HeapCompact(hHeap, flags); }

// getprocessheaps
#else // OS != WINDOWS
inline handle heap_GetDefault()
{ return (handle) 1; }

inline handle heap_Create(uint startSize=0, uint flags=0)
{ unusedpar(startSize); unusedpar(flags); return (handle) 1; }

inline void heap_Destroy(handle hHeap)
{ unusedpar(hHeap); }

inline void* heap_Alloc(handle hHeap, uint size, uint flags=0)
{ unusedpar(hHeap); unusedpar(flags); return malloc(size); }

inline void* heap_ReAlloc(handle hHeap, void* addr, uint size, uint flags=0)
{ unusedpar(hHeap); unusedpar(flags); return realloc(addr, size); }

inline void heap_Free(handle hHeap, void* addr, uint flags=0)
{ unusedpar(hHeap); unusedpar(flags); free(addr); }

inline void heap_Optimize(handle hHeap, uint flags=0)
{ unusedpar(hHeap); unusedpar(flags); }

// getprocessheaps
#endif // OS == WINDOWS


} // end namespace wind


#endif /* _MEMORY_HEAP_FUNC_H_ */