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
 * concat.hpp - value concatenation
 */

#ifndef _MATH_CONCAT_HPP_
#define _MATH_CONCAT_HPP_


// integer concatenation
#define math_Concat2(v1, v0, sft)	\
(((v1) << (sft)) | (v0))

#define math_Concat3(v2, v1, v0, sft)	\
math_Concat2(math_Concat2(v2, v1, sft), v0, sft)

#define math_Concat4(v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat3(v3, v2, v1, sft), v0, sft)

#define math_Concat5(v4, v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat4(v4, v3, v2, v1, sft), v0, sft)

#define math_Concat6(v5, v4, v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat3(v5, v4, v3, v2, v1, sft), v0, sft)

#define math_Concat7(v6, v5, v4, v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat3(v6, v5, v4, v3, v2, v1, sft), v0, sft)

#define math_Concat8(v7, v6, v5, v4, v3, v2, v1, v0, sft)	\
math_Concat2(math_Concat3(v7, v6, v5, v4, v3, v2, v1, sft), v0, sft)

#define	math_Concat(...)	\
macro_Fn(macro_Fn9(__VA_ARGS__, math_Concat8, math_Concat7, math_Concat6, math_Concat5, math_Concat4, math_Concat3, math_Concat2)(__VA_ARGS__))


// value formation
#define math_MakeInt8n(v1, v0)	\
math_Concat(v1, v0, 4)

#define	math_MakeInt8b(v7, v6, v5, v4, v3, v2, v1, v0)	\
math_Concat(v7, v6, v5, v4, v3, v2, v1, v0, 1)

#define math_MakeInt8(...)	\
macro_Fn(macro_Fn8(__VA_ARGS__, math_MakeInt8b, _7, _6, _5, _4, _3, math_MakeInt8n)(__VA_ARGS__))

#define math_MakeUint8	\
math_MakeInt8

#define	math_MakeInt16(v1, v0)	\
	math_Concat(v1, v0, 8)

#define math_MakeUint16	\
math_MakeInt16

#define math_MakeInt32_4(v3, v2, v1, v0)	\
math_Concat(v3,v2, v1, v0, 8)

#define	math_MakeInt32_2(v1, v0)	\
math_Concat(v1, v0, 16)

#define math_MakeInt32(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, math_MakeInt32_4, _3, math_MakeInt32_2)(__VA_ARGS__))

#define	math_MakeUint32	\
math_MakeInt32

#define math_MakeInt64_8(v7, v6, v5, v4, v3, v2, v1, v0)	\
math_Concat(v7, v6, v5, v4, v3, v2, v1, v0, 8)

#define math_MakeInt64_4(v3, v2, v1, v0)	\
math_Concat(v3, v2, v1, v0, 16)

#define math_MakeInt64_2(v1, v0)	\
math_Concat(v1, v0, 32)

#define math_MakeInt64(...)	\
macro_Fn(macro_Fn8(__VA_ARGS__, math_MakeInt64_8, _7, _6, _5, math_MakeInt64_4, _3, math_MakeInt64_2)(__VA_ARGS__))

#define math_MakeUint64	\
math_MakeInt64


#endif /* _MATH_CONCAT_HPP_ */