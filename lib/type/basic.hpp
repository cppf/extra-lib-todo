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
 * basic.hpp - basic type definitions
 */

#ifndef	_TYPE_BASIC_HPP_
#define	_TYPE_BASIC_HPP_


namespace wind
{


// basic values
#ifndef NULL
#define NULL	(0)
#endif // !null

#ifndef TRUE
#define	TRUE	(1)
#define	FALSE	(0)
#endif // !true


// character types
typedef	wchar_t			wchar;
#define	wcharof(str)	L##str
#if CHAR_MODE == ASCII
typedef char			tchar;
#define	tcharof(str)	str
#else // UNICODE
typedef wchar			tchar;
#define	tcharof(str)	L##str
#endif


// size-specific integers
typedef	signed char			int8;
typedef	unsigned char		uint8;
typedef	short				int16;
typedef	unsigned short		uint16;
typedef	long				int32;
typedef	unsigned long		uint32;
typedef	long long			int64;
typedef	unsigned long long	uint64;


// word size integer
#ifndef word
#if WORD_SIZE == 8
typedef	int8	word;
typedef	uint8	uword;
#elif WORD_SIZE == 16
typedef	int16	word;
typedef	uint16	uword;
#elif WORD_SIZE == 32
  typedef int32	word;
typedef uint32	uword;
#else // 64
typedef int64	word;
typedef uint64	uword;
#endif
#endif // !word


// named types
#ifndef byte
typedef	unsigned char	byte;
typedef	signed char		sbyte;
#endif // !byte
typedef unsigned short	ushort;
typedef unsigned int	uint;
typedef unsigned long	ulong;


} // end namespace wind


#endif /* _TYPE_BASIC_HPP_ */