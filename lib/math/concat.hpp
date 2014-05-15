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


// required headers
#include "..\make\macro.hpp"


// concat numbers
#define Concat2(v1, v0, sft)	\
(((v1) << (sft)) | (v0))

#define Concat3(v2, v1, v0, sft)	\
Concat2(Concat2(v2, v1, sft), v0, sft)

#define Concat4(v3, v2, v1, v0, sft)	\
Concat2(Concat3(v3, v2, v1, sft), v0, sft)

#define Concat5(v4, v3, v2, v1, v0, sft)	\
Concat2(Concat4(v4, v3, v2, v1, sft), v0, sft)

#define Concat6(v5, v4, v3, v2, v1, v0, sft)	\
Concat2(Concat3(v5, v4, v3, v2, v1, sft), v0, sft)

#define Concat7(v6, v5, v4, v3, v2, v1, v0, sft)	\
Concat2(Concat3(v6, v5, v4, v3, v2, v1, sft), v0, sft)

#define Concat8(v7, v6, v5, v4, v3, v2, v1, v0, sft)	\
Concat2(Concat3(v7, v6, v5, v4, v3, v2, v1, sft), v0, sft)

#define	Concat(...)	\
macro_Fn(macro_Fn9(__VA_ARGS__, Concat8, Concat7, Concat6, Concat5, Concat4, Concat3, Concat2)(__VA_ARGS__))


// form value
#define MakeInt8n(v1, v0)	\
Concat(v1, v0, 4)

#define	MakeInt8b(v7, v6, v5, v4, v3, v2, v1, v0)	\
Concat(v7, v6, v5, v4, v3, v2, v1, v0, 1)

#define MakeInt8(...)	\
macro_Fn(macro_Fn8(__VA_ARGS__, MakeInt8b, _7, _6, _5, _4, _3, MakeInt8n)(__VA_ARGS__))

#define MakeUint8	\
MakeInt8

#define	MakeInt16(v1, v0)	\
Concat(v1, v0, 8)

#define MakeUint16	\
MakeInt16

#define MakeInt32_4(v3, v2, v1, v0)	\
Concat(v3,v2, v1, v0, 8)

#define	MakeInt32_2(v1, v0)	\
Concat(v1, v0, 16)

#define MakeInt32(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, MakeInt32_4, _3, MakeInt32_2)(__VA_ARGS__))

#define	MakeUint32	\
MakeInt32

#define MakeInt64_8(v7, v6, v5, v4, v3, v2, v1, v0)	\
Concat(v7, v6, v5, v4, v3, v2, v1, v0, 8)

#define MakeInt64_4(v3, v2, v1, v0)	\
Concat(v3, v2, v1, v0, 16)

#define MakeInt64_2(v1, v0)	\
Concat(v1, v0, 32)

#define MakeInt64(...)	\
macro_Fn(macro_Fn8(__VA_ARGS__, MakeInt64_8, _7, _6, _5, MakeInt64_4, _3, MakeInt64_2)(__VA_ARGS__))

#define MakeUint64	\
MakeInt64


#endif /* _MATH_CONCAT_HPP_ */