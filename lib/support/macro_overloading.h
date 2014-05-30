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
 * support\macro_overloading.h - Provides support for overloading macros, in a way similar to function overloading
 * This file is a part of the Wind library for C++.
 */

#ifndef _SUPPORT_MACRO_OVERLOADING_H_
#define _SUPPORT_MACRO_OVERLOADING_H_


// required headers
#include "constants.h"


// macro overloading support
#define	macro_Fn(x)	x
#define	macro_Fn1(_1, func, ...)	func
#define	macro_Fn2(_1, _2, func, ...)	func
#define	macro_Fn3(_1, _2, _3, func, ...)	func
#define	macro_Fn4(_1, _2, _3, _4, func, ...)	func
#define	macro_Fn5(_1, _2, _3, _4, _5, func, ...)	func
#define	macro_Fn6(_1, _2, _3, _4, _5, _6, func, ...)	func
#define	macro_Fn7(_1, _2, _3, _4, _5, _6, _7, func, ...)	func
#define	macro_Fn8(_1, _2, _3, _4, _5, _6, _7, _8, func, ...)	func
#define	macro_Fn9(_1, _2, _3, _4, _5, _6, _7, _8, _9, func, ...)	func
#define	macro_Fn10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, func, ...)	func
#define	macro_Fn11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, func, ...)	func
#define	macro_Fn12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, func, ...)	func
#define	macro_Fn13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, func, ...)	func
#define	macro_Fn14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, func, ...)	func
#define	macro_Fn15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, func, ...)	func
#define	macro_Fn16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, func, ...)	func
#define	macro_Fn17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, func, ...)	func
#define	macro_Fn18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, func, ...)	func
#define	macro_Fn19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, func, ...)	func
#define	macro_Fn20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, func, ...)	func
#define	macro_Fn21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, func, ...)	func
#define	macro_Fn22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, func, ...)	func
#define	macro_Fn23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, func, ...)	func
#define	macro_Fn24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, func, ...)	func
#define	macro_FnE()
#define	macro_FnX(...)


// macro beginning and ending
// return only supported in GCC
#if COMPILER == GCC
#define	macro_Begin			({
#define	macro_End			})
#define macro_Return(var)	(var)
#else // COMPILER == VISUALCPP
#define	macro_Begin			do{
#define	macro_End			}while(0)
#endif // COMPILER == GCC


#endif /* _SUPPORT_MACRO_OVERLOADING_H_ */