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
 * range.hpp - datatype min., max. values
 */

#ifndef _TYPE_RANGE_HPP_
#define _TYPE_RANGE_HPP_


// size-specified integers
#define int8_Min	(-0x80)
#define int8_Max	(0x7F)
#define int16_Min	(-0x8000)
#define int16_Max	(0x7FFF)
#define int32_Min	(-0x80000000L)
#define int32_Max	(0x7FFFFFFFL)
#define int64_Min	(-0x8000000000000000LL)
#define int64_Max	(0x7FFFFFFFFFFFFFFFLL)
#define uint8_Min	(0U)
#define uint8_Max	(0xFFU)
#define uint16_Min	(0U)
#define uint16_Max	(0xFFFFU)
#define uint32_Min	(0UL)
#define uint32_Max	(0xFFFFFFFFUL)
#define uint64_Min	(0ULL)
#define uint64_Max	(0xFFFFFFFFFFFFFFFFULL)


// word size integer
#if WORD_SIZE == 8
#define	int_Min		int16_Min
#define	int_Max		int16_Max
#define	uint_Min	uint16_Min
#define	uint_Max	uint16_Max
#define	word_Min	int8_Min
#define	word_Max	int8_Max
#define	uword_Min	uint8_Min
#define	uword_Max	uint8_Max
#elif WORD_SIZE == 16
#define	int_Min		int16_Min
#define	int_Max		int16_Max
#define	uint_Min	uint16_Min
#define	uint_Max	uint16_Max
#define	word_Min	int16_Min
#define	word_Max	int16_Max
#define	uword_Min	uint16_Min
#define	uword_Max	uint16_Max
#elif WORD_SIZE == 32
#define	int_Min		int32_Min
#define	int_Max		int32_Max
#define	uint_Min	uint32_Min
#define	uint_Max	uint32_Max
#define	word_Min	int32_Min
#define	word_Max	int32_Max
#define	uword_Min	uint32_Min
#define	uword_Max	uint32_Max
#else // 64
#define	int_Min		int64_Min
#define	int_Max		int64_Max
#define	uint_Min	uint64_Min
#define	uint_Max	uint64_Max
#define	word_Min	int64_Min
#define	word_Max	int64_Max
#define	uword_Min	uint64_Min
#define	uword_Max	uint64_Max
#endif


// named types
#define char_Min	('\0')
#define char_Max	('\xFF')
#define byte_Min	uint8_Min
#define byte_Max	uint8_Max
#define ubyte_Min	uint8_Min
#define ubyte_Max	uint8_Max
#define sbyte_Min	int8_Min
#define sbyte_Max	int8_Max
#define short_Min	int16_Min
#define short_Max	int16_Max
#define ushort_Min	uint16_Min
#define ushort_Max	uint16_Max
#define long_Min	int32_Min
#define long_Max	int32_Max
#define	ulong_Min	uint32_Min
#define ulong_Max	uint32_Max


#endif /* _TYPE_RANGE_HPP_ */