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
 * attrib.hpp - attribute declaration file (GCC only)
 */

#ifndef _MAKE_ATTRIB_HPP_
#define _MAKE_ATTRIB_HPP_


// required headers
#include "const.hpp"


// GCC attribute definitions only
#if COMPILER == GCC

// attribute macro
#define attrib(...)	\
__attribute__((__VA_ARGS__))

// standard attributes
#define aligned(amt)	attrib(__aligned__(amt))
#define alwaysinline	attrib(__always_inline__)
#define deprecated(msg)	attrib(__deprecated__(msg))
#define raw				attrib(__naked__)
#define noinline		attrib(__noinline__)
#define noreturn		attrib(__noreturn__)
#define optimizespeed	attrib(__optimize__("O3"))
#define optimizesize	attrib(__optimize__("Os"))
#define optimize		optimizeSize
#define osmain			attrib(__OS_main__)
#define ostask			attrib(__OS_task__)
#define pure			attrib(__pure__)
#define hot				attrib(__hot__)
#define cold			attrib(__cold__)
#define section(name)	attrib(__section__(name))
#define isrspecial		attrib(__interrupt__)
#define isr				attrib(__signal__)
#define ignore			attrib(__unused__)
#define used			attrib(__used__)
#define packed			attrib(__packed__)
#define progmem			attrib(__progmem__)
// osfn = attrib(section(".boot"), optimize("Os"))

#else // VISUALCPP

// attribute macro
#define attrib(...)			__declspec(__VA_ARGS__)

// standard attributes
#define aligned(amt)
#define alwaysinline		__forceinline
#define deprecated(msg)
#define raw
#define noinline
#define noreturn
#define optimizespeed
#define optimizesize
#define optimize
#define osmain
#define ostask
#define pure
#define hot
#define cold
#define section(name)
#define isrspecial
#define isr
#define ignore
#define used
#define packed
#define progmem
// osfn = 

#endif // GCC


#endif /* _MAKE_ATTRIB_HPP_ */