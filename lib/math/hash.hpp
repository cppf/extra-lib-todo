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
 * hash.hpp - hashing functions
 */

#ifndef _MATH_HASH_HPP_
#define _MATH_HASH_HPP_


// required headers
#include "..\make\func.hpp"
#include "..\make\attrib.hpp"
#include "..\type\basic.hpp"

// 8-bit XOR-ROR hashing
noinline uint8 math_Hash8F(uint8* data, uint size);
uint8 math_Hash8F(uint8* data, uint size)
{
	// opt: uword size
	uint8 hash = 0;
	for(; size > 0; data++, size--)
	{
		hash ^= *data;
#if COMPILER == GCC
		assembly(
		line("bst %0, 0")
		line("lsr %0")
		line("bld %0, 7")
		: "=r"(hash)
		: "r"(hash)
		:
		);
#else // VISUALCPP
		hash = (hash >> 1) | ((hash & 1) << 7);
#endif
	}
	return hash;
}

#define math_Hash8(data, size)	\
math_Hash8F((uint8*)(data), (uint)(size))


#endif /* _MATH_HASH_HPP_ */