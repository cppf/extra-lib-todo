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
 * func.hpp - common global macros
 */

#ifndef _MAKE_FUNC_HPP_
#define _MAKE_FUNC_HPP_


// required headers
#include "const.hpp"


// typeof macro
#if COMPILER == VISUALCPP
#define typeof(expr)	decltype(expr)
#endif // COMPILER == VISUALCPP


// token to string
#ifndef stringof
#define stringof(a)		#a
#endif // !tostring


// mark unused variables
#ifndef unused
#define unused(var)		(void)(var)
#endif // !unused


// memory barrier (prevents reordering)
#if COMPILER == GCC
#ifndef barrier
#define barrier()		asm volatile("" ::: "memory")
#endif // !barrier
#endif // COMPILER == GCC


// assembly coding
#if COMPILER == GCC
#ifndef assembly
#define assembly		__asm__ __volatile__
#endif // !assembly
#ifndef line
#define line(text)		text "\n\t"
#endif // !line
#else // COMPILER == VISUALCPP
#ifndef assembly
#define assembly		__asm
#endif // !assembly
#ifndef line
#define line(text)		text
#endif // !line
#endif

#endif /* _MAKE_FUNC_HPP_ */