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
#define int8_MIN	(-0x80)
#define int8_MAX	(0x7F)
#define int16_MIN	(-0x8000)
#define int16_MAX	(0x7FFF)
#define int32_MIN	(-0x80000000L)
#define int32_MAX	(0x7FFFFFFFL)
#define int64_MIN	(-0x8000000000000000LL)
#define int64_MAX	(0x7FFFFFFFFFFFFFFFLL)
#define uint8_MIN	(0U)
#define uint8_MAX	(0xFFU)
#define uint16_MIN	(0U)
#define uint16_MAX	(0xFFFFU)
#define uint32_MIN	(0UL)
#define uint32_MAX	(0xFFFFFFFFUL)
#define uint64_MIN	(0ULL)
#define uint64_MAX	(0xFFFFFFFFFFFFFFFFULL)


// word size integer
#if WORD_SIZE == 8
#define	int_MIN		int16_MIN
#define	int_MAX		int16_MAX
#define	uint_MIN	uint16_MIN
#define	uint_MAX	uint16_MAX
#define	word_MIN	int8_MIN
#define	word_MAX	int8_MAX
#define	uword_MIN	uint8_MIN
#define	uword_MAX	uint8_MAX
#elif WORD_SIZE == 16
#define	int_MIN		int16_MIN
#define	int_MAX		int16_MAX
#define	uint_MIN	uint16_MIN
#define	uint_MAX	uint16_MAX
#define	word_MIN	int16_MIN
#define	word_MAX	int16_MAX
#define	uword_MIN	uint16_MIN
#define	uword_MAX	uint16_MAX
#elif WORD_SIZE == 32
#define	int_MIN		int32_MIN
#define	int_MAX		int32_MAX
#define	uint_MIN	uint32_MIN
#define	uint_MAX	uint32_MAX
#define	word_MIN	int32_MIN
#define	word_MAX	int32_MAX
#define	uword_MIN	uint32_MIN
#define	uword_MAX	uint32_MAX
#else // 64
#define	int_MIN		int64_MIN
#define	int_MAX		int64_MAX
#define	uint_MIN	uint64_MIN
#define	uint_MAX	uint64_MAX
#define	word_MIN	int64_MIN
#define	word_MAX	int64_MAX
#define	uword_MIN	uint64_MIN
#define	uword_MAX	uint64_MAX
#endif


// named types
#define char_MIN	('\0')
#define char_MAX	('\xFF')
#define byte_MIN	uint8_MIN
#define byte_MAX	uint8_MAX
#define ubyte_MIN	uint8_MIN
#define ubyte_MAX	uint8_MAX
#define sbyte_MIN	int8_MIN
#define sbyte_MAX	int8_MAX
#define short_MIN	int16_MIN
#define short_MAX	int16_MAX
#define ushort_MIN	uint16_MIN
#define ushort_MAX	uint16_MAX
#define long_MIN	int32_MIN
#define long_MAX	int32_MAX
#define	ulong_MIN	uint32_MIN
#define ulong_MAX	uint32_MAX


#endif /* _TYPE_RANGE_HPP_ */