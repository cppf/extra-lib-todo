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
 * bit.hpp - bit operations
 */

#ifndef _MATH_BIT_HPP_
#define _MATH_BIT_HPP_


// required headers
#include "..\make\macro.hpp"
#include "..\type\basic.hpp"


// form value by ones
#define	bit_ValueByOnes1(b1)	\
(1 << (b1))

#define	bit_ValueByOnes2(b1, b2)	\
((1 << (b1)) | (1 << (b2)))

#define	bit_ValueByOnes3(b1, b2, b3)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)))

#define	bit_ValueByOnes4(b1, b2, b3, b4)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)))

#define	bit_ValueByOnes5(b1, b2, b3, b4, b5)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)) | (1 << (b5)))

#define	bit_ValueByOnes6(b1, b2, b3, b4, b5, b6)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)) | (1 << (b5)) | (1 << (b6)))

#define	bit_ValueByOnes7(b1, b2, b3, b4, b5, b6, b7)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)) | (1 << (b5)) | (1 << (b6)) | (1 << (b7)))

#define	bit_ValueByOnes8(b1, b2, b3, b4, b5, b6, b7, b8)	\
((1 << (b1)) | (1 << (b2)) | (1 << (b3)) | (1 << (b4)) | (1 << (b5)) | (1 << (b6)) | (1 << (b7)) | (1 << (b8)))

#define	bit_ValueByOnes(...)	\
macro_Fn(macro_Fn8(__VA_ARGS__, bit_ValueByOnes8, bit_ValueByOnes7, bit_ValueByOnes6, bit_ValueByOnes5, bit_ValueByOnes4, bit_ValueByOnes3, bit_ValueByOnes2, bit_ValueByOnes1)(__VA_ARGS__))


// read bit
#define	bit_Read(src, bit_no)	\
(((src) >> (bit_no)) & 1)

#define bit_Get	\
bit_Read


// test / check bit
#define bit_Test(src, ...)	\
((src) & bit_ValueByOnes(__VA_ARGS__))


// set bit (to 1)
#define bit_Set(dst, ...)	\
((dst) |= bit_ValueByOnes(__VA_ARGS__))


// clear bit (to 0)
#define bit_Clear(dst, ...)	\
((dst) &= ~bit_ValueByOnes(__VA_ARGS__))

#define bit_Reset	\
bit_Clear


// toggle bit (flip)
#define bit_Toggle(dst, ...)	\
((dst) ^= bit_ValueByOnes(__VA_ARGS__))


// write bit (to 0/1)
template <typename T>
inline void bit_Write(T& dst, byte bitNo, byte bitVal)
{
	dst = (dst & ~(1 << bitNo)) | (bitVal << bitNo);
}

#define bit_Put	\
bit_Write


#endif /* _MATH_BIT_HPP_ */