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
 * support\attributes.h - Defines cross-compiler function and variable attributes
 * This file is part of the Wind library for C++.
 */

#ifndef _SUPPORT_ATTRIBUTES_H_
#define _SUPPORT_ATTRIBUTES_H_


// required headers
#include "constants.h"


// attribute definitions
#if COMPILER == GCC

// attribute macro
#define attrib(...)			__attribute__((__VA_ARGS__))
// security
#define	error(msg)			attrib(__error__(msg))
#define	warning(msg)		attrib(__warning__(msg))
#define outdated(msg)		attrib(__deprecated__(msg))
// interrupt
#define	isr					attrib(__signal__)
#define	longisr				attrib(__interrupt__)
// properties
#define	progmem				attrib(__progmem__)
#define noreturn			attrib(__noreturn__)
#define	useresult			attrib(__warn_unused_result__)
#define	readonly			attrib(__pure__)
#define	readonlyargs		attrib(__const__)
#define	noexception			attrib(__nothrow__)
#define	nonnullargs(...)	attrib(__nonnull__(__VA_ARGS__))
// visibility
#define	dllref				attrib(__dllimport__)
#define	dllfunc				attrib(__dllexport__)
#define	external			attrib(__externally_visible__)
// optimization
#define raw					attrib(__naked__)
#define	used				attrib(__used__)
#define	unused				attrib(__unused__)
#define fast				attrib(__optimize__("O3"))
#define compact				attrib(__optimize__("Os"))
#define	packed				attrib(__packed__)
#define	lessused			attrib(__cold__)
#define	highlyused			attrib(__hot__)
#define isinline			attrib(__always_inline__)
#define notinline			attrib(__noinline__)
#define aligned(amt)		attrib(__aligned__(amt))
#if DEVICE == PROCESSOR
#define optimized			fast
#else
#define	optimized			compact
#endif
// calling convention
#define	ccall			attrib(__cdecl__)
#define	cdecl			attrib(__cdecl__)
#define	stdcall			attrib(__stdcall__)

#else // COMPILER != GCC

// attribute macro
#define attrib(...)			__declspec(__VA_ARGS__)
// security
#define outdated(msg)		attrib(deprecated(msg))
// properties
#define noreturn			attrib(noreturn)
#define	noexception			attrib(nothrow)
// visibility
#define	dllref				attrib(dllimport)
#define	dllfunc				attrib(dllexport)
// optimization
#define raw					attrib(naked)
#define isinline			attrib(__forceinline)
#define notinline			attrib(noinline)
#define aligned(amt)		attrib(align(amt))
// calling convention
#define	ccall			__cdecl
#ifndef cdecl
#define	cdecl			__cdecl
#endif
#ifndef stdcall
#define	stdcall			__stdcall
#endif


#endif // COMPILER == GCC


#endif /* _SUPPORT_ATTRIBUTES_H_ */