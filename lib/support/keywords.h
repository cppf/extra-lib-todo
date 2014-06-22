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
 * support\keywords.h - Provides cross-compiler keyword-type functions for certain operations
 * This file is part of the Wind library for C++.
 */

#ifndef _SUPPORT_KEYWORDS_H_
#define _SUPPORT_KEYWORDS_H_


// required headers
#include "constants.h"


// get type of a variable
#if COMPILER == VISUAL_CPP
#define typeof(expr)		decltype(expr)
#endif


// convert a token to string
#ifndef stringof
#define stringof(a)			#a
#endif


// mark unused parameters
#ifndef unusedpar
#define unusedpar(param)	(void)(param)
#endif


// specify byte address
#define byteaddr(base, off)	(((unsigned char*)(base)) + (off))


// memory barrier to prevent reordering
#if COMPILER == GCC
#ifndef barrier
#define barrier()			asm volatile("" ::: "memory")
#endif
#endif // COMPILER


// assembly coding
#if COMPILER == GCC
#define assembly			__asm__ __volatile__
#define line(text)			text "\n\t"

#else // COMPILER != GCC
#define assembly			__asm
#define line(text)			text
#endif // COMPILER


#endif /* _SUPPORT_KEYWORDS_H_ */