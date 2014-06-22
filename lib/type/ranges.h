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
 * type\num_range.h - Defines the minimum and maximum values of primitive datatypes
 * This file is part of the Wind library for C++.
 */

#ifndef _TYPE_RANGES_H_
#define _TYPE_RANGES_H_


// required headers
#include "primitives.h"


namespace wind {


// size-specified integers
const int8   int8_Min	= -0x80;
const int8   int8_Max	= 0x7F;
const int16  int16_Min	= -0x8000;
const int16  int16_Max	= 0x7FFF;
const int32  int32_Min	= 0x80000000L;
const int32  int32_Max	= 0x7FFFFFFFL;
const int64  int64_Min	= 0x8000000000000000LL;
const int64  int64_Max	= 0x7FFFFFFFFFFFFFFFLL;
const uint8  uint8_Min	= 0U;
const uint8  uint8_Max	= 0xFFU;
const uint16 uint16_Min	= 0U;
const uint16 uint16_Max	= 0xFFFFU;
const uint32 uint32_Min	= 0UL;
const uint32 uint32_Max	= 0xFFFFFFFFUL;
const uint64 uint64_Min	= 0ULL;
const uint64 uint64_Max	= 0xFFFFFFFFFFFFFFFFULL;


// word size integer
#if WORD_SIZE == 8
const int   int_Min		= int16_Min;
const int   int_Max		= int16_Max;
const uint  uint_Min	= uint16_Min;
const uint  uint_Max	= uint16_Max;
const word  word_Min	= int8_Min;
const word  word_Max	= int8_Max;
const uword uword_Min	= uint8_Min;
const uword uword_Max	= uint8_Max;

#elif WORD_SIZE == 16
const int   int_Min		= int16_Min;
const int   int_Max		= int16_Max;
const uint  uint_Min	= uint16_Min;
const uint  uint_Max	= uint16_Max;
const word  word_Min	= int16_Min;
const word  word_Max	= int16_Max;
const uword uword_Min	= uint16_Min;
const uword uword_Max	= uint16_Max;

#elif WORD_SIZE == 32
const int   int_Min		= int32_Min;
const int   int_Max		= int32_Max;
const uint  uint_Min	= uint32_Min;
const uint  uint_Max	= uint32_Max;
const word  word_Min	= int32_Min;
const word  word_Max	= int32_Max;
const uword uword_Min	= uint32_Min;
const uword uword_Max	= uint32_Max;

#else // 64
const int   int_Min		= int64_Min;
const int   int_Max		= int64_Max;
const uint  uint_Min	= uint64_Min;
const uint  uint_Max	= uint64_Max;
const word  word_Min	= int64_Min;
const word  word_Max	= int64_Max;
const uword uword_Min	= uint64_Min;
const uword uword_Max	= uint64_Max;
#endif // WORD_SIZE


// named types
const char  char_Min	= '\0';
const char  char_Max	= '\xFF';
const wchar wchar_Min	= L'\0';
const wchar wchar_Max	= L'\xFFFF';

#if TEXT_MODE == ANSI
const tchar tchar_Min	= char_Min;
const tchar tchar_Max	= char_Max;

#else // TEXT_MODE == UNICODE
const tchar tchar_Min	= wchar_Min;
const tchar tchar_Max	= wchar_Max;
#endif

const byte   byte_Min	= uint8_Min;
const byte   byte_Max	= uint8_Max;
const sbyte  sbyte_Min	= int8_Min;
const sbyte  sbyte_Max	= int8_Max;
const short  short_Min	= int16_Min;
const short  short_Max	= int16_Max;
const ushort ushort_Min	= uint16_Min;
const ushort ushort_Max	= uint16_Max;
const long   long_Min	= int32_Min;
const long   long_Max	= int32_Max;
const ulong  ulong_Min	= uint32_Min;
const ulong  ulong_Max	= uint32_Max;


}


#endif /* _TYPE_RANGES_H_ */