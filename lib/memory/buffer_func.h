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
 * memory\buffer_func.h - Provides standard memory operations than can be performed on a buffer
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_BUFFER_FUNC_H_
#define _MEMORY_BUFFER_FUNC_H_


// required headers
#include <stdlib.h>
#include <string.h>
#include "heap_func.h"


namespace wind {


// initialization
inline void* buffer_Create(handle hHeap, uint size, uint flags=0)
{ return heap_Alloc(hHeap, size, flags); }

inline void* buffer_Create(uint size, uint flags=0)
{ return heap_Alloc(size, flags); }

inline void* buffer_Resize(handle hHeap, void* addr, uint size, uint flags=0)
{ return heap_ReAlloc(hHeap, addr, size, flags); }

inline void* buffer_Resize(void* addr, uint size, uint flags=0)
{ return heap_ReAlloc(addr, size, flags); }

inline void buffer_Destroy(handle hHeap, void* addr, uint flags=0)
{ return heap_Free(hHeap, addr, flags); }

inline void buffer_Destroy(void* addr, uint flags=0)
{ return heap_Free(addr, flags); }


// functions
#if OS == WINDOWS
inline void buffer_Fill(void* dst, uint size, byte val)
{ FillMemory(dst, size, val); }

inline void buffer_FillZero(void* dst, uint size)
{ SecureZeroMemory(dst, size); }

inline void buffer_Copy(void* dst, const void* src, uint size)
{ CopyMemory(dst, src, size); }

inline void buffer_Move(void* dst, void* src, uint size)
{ MoveMemory(dst, src, size); }

#else // OS != WINDOWS
inline void buffer_Fill(void* dst, uint size, byte val)
{ memset(dst, size, val); }

inline void buffer_FillZero(void* dst, uint size)
{ memset(dst, size, 0); }

inline void buffer_Copy(void* dst, const void* src, uint size)
{ memcpy(dst, src, size); }

inline void buffer_Move(void* dst, void* src, uint size)
{ memmove(dst, src, size); }
#endif // OS == WINDOWS

inline void buffer_Copy(void* dst, uint dstSize, const void* src, uint size)
{ memcpy_s(dst, dstSize, src, size); }

inline void buffer_Move(void* dst, uint dstSize, const void* src, uint size)
{ memmove_s(dst, dstSize, src, size); }

inline int buffer_Compare(const void* addr1, const void* addr2, uint size)
{ return memcmp(addr1, addr2, size); }

inline bool buffer_Equals(const void* addr1, const void* addr2, uint size)
{ return !buffer_Compare(addr1, addr2, size); }

inline void* buffer_Find(void* addr, uint size, byte val)
{ return memchr(addr, val, size); }


} // end namespace wind


#endif /* _MEMORY_BUFFER_FUNC_H_ */