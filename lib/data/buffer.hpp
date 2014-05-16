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
 * buffer.hpp - basic buffer structure
 */

#ifndef _DATA_BUFFER_HPP_
#define _DATA_BUFFER_HPP_


// required headers
#include "..\type\basic.hpp"


// basic buffer definition
template <uint size>
union buffer
{
	int8	Int8[1];
	uint8	Uint8[1];
	int16	Int16[1];
	uint16	Uint16[1];
	int32	Int32[1];
	uint32	Uint32[1];
	int64	Int64[1];
	uint64	Uint64[1];
	int		Int[1];
	uint	Uint[1];
	word	Word[1];
	uword	Uword[1];
	byte	Byte[size];
	ubyte	UByte[1];
	sbyte	Sbyte[1];
	char	Char[1];
	short	Short[1];
	ushort	Ushort[1];
	long	Long[1];
	ulong	Ulong[1];
	float	Float[1];
	double	Double[1];
};


#endif /* _DATA_BUFFER_HPP_ */