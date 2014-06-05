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
 * data\gstringz.h - Defines a zero-terminated generic string that provides basic destination-type functions
 * This file is part of the Wind library for C++.
 */

#ifndef _DATA_STRINGZ_H_
#define _DATA_STRINGZ_H_


// required headers
#include "..\support\keywords.h"
#include "..\memory\address.h"


namespace wind {


// zero-terminated ANSI string class
// can be type casted to char*
class stringz
{


public:
	// data
	address<char> Address;


public:
	// initialization
	inline operator char*() const
	{ return Address.Value; }

	inline operator address<char>() const
	{ return Address; }

	inline stringz(void* addr=NULL)
	{ Address = addr; }

	inline static stringz Create(char* str=NULL)
	{ return stringz(str); }

	inline void Destroy()
	{ Address = NULL; }


	// functions
public:
	inline bool IsValid()
	{ return Address.IsValid(); }

	inline uint GetLength()
	{ return strlen(Address); }

	inline stringz Part(int off=0, uint len=0)
	{ Address[len] = '\0'; return stringz(Address + off); }

	inline stringz PutCopy(stringz str)
	{ strcat(Address, str); return *this; }

	inline stringz PutReverse(stringz str)
	{

	}

	inline void Fill(uint size, char val)
	{ Address.Fill(size, val); }

	inline void Fill(byte val)
	{ Address.Fill(Length, val); }

	inline void FillZero(uint size=Size)
	{ Address.FillZero(size); }

	inline void Copy(const void* src, uint size)
	{ Address.Move(Size, src, size); }

	inline void Move(const void* src, uint size)
	{ Address.Move(Size, src, size); }

	inline int Compare(const void* addr, uint size) const
	{ return Address.Compare(addr, size); }

	inline bool Equals(const void* addr, uint size) const
	{ return Address.Equals(addr, size); }

	inline void* Find(uint size, byte val)
	{ return Address.Find(size, val); }


}; // end class stringz


} // end namespace wind


#endif /* _DATA_STRINGZ_H_ */