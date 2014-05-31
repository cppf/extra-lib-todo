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
 * memory\block_func.h - Provides block memory operations for use with the Wind library
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_BLOCK_FUNC_H_
#define _MEMORY_BLOCK_FUNC_H_


// required headers
#include <stdlib.h>
#include <string.h>
#include "..\support\constants.h"
#include "..\type\primitives.h"
#if OS == WINDOWS
#include <Windows.h>
#endif


namespace wind {


// block operations
#if OS == WINDOWS
#define	_block_fill(addr, sz, val)		FillMemory(addr, sz, val)
#define	_block_fillZero(addr, sz)		ZeroMemory(addr, sz)
#define	_block_copy(dst, src, sz)		CopyMemory(dst, src, sz)
#define	_block_move(dst, src, sz)		MoveMemory(dst, src, sz)
#else // OS != WINDOWS
#define	_block_fill(addr, sz, val)		memset(addr, sz, val)
#define	_block_fillZero(addr, sz)		memset(addr, sz, 0)
#define	_block_copy(dst, src, sz)		memcpy(dst, src, sz)
#define	_block_move(dst, src, sz)		memmove(dst, src, sz)
#endif // OS == WINDOWS


inline void block_Fill(void* addr, uint size, byte val)
{ _block_fill(addr, size, val); }

inline void block_FillZero(void* addr, uint size)
{ _block_fillZero(addr, size); }

inline void block_Copy(void* dst, const void* src, uint size)
{ _block_copy(dst, src, size); }

inline void block_Copy(void* dst, uint dstSize, const void* src, uint size)
{ memcpy_s(dst, dstSize, src, size); }

inline void block_Move(void* dst, const void* src, uint size)
{ _block_move(dst, src, size); }

inline void block_Move(void* dst, uint dstSize, const void* src, uint size)
{ memmove_s(dst, dstSize, src, size); }

inline int block_Compare(const void* addr1, const void* addr2, uint size)
{ return memcmp(addr1, addr2, size); }

inline bool block_Equals(const void* addr1, const void* addr2, uint size)
{ return !block_Compare(addr1, addr2, size); }

inline void* block_Find(void* addr, uint size, byte val)
{ return memchr(addr, val, size); }


} // end namespace wind


#endif /* _MEMORY_BLOCK_FUNC_H_ */