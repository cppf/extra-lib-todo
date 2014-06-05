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
 * data\gstring.h - Defines a length-specified generic string that provides destination-type functions
 * This file is part of the Wind library for C++.
 */

#ifndef _DATA_GSTRING_H_
#define _DATA_GSTRING_H_


// required headers
#include "..\type\gchar.h"
#include "..\memory\heap.h"
#include "..\memory\buffer.h"
#include "..\memory\address.h"


namespace wind {


// length-specified generic string class
// can be type casted to char*
template <typename T>
class gstring
{


public:
	// data
	address<T> Address;
	uint Length;


public:
	// initialization
	inline operator T*() const
	{ return Address.Value; }

	inline operator address<T>() const
	{ return Address; }

	inline gstring(void* addr=NULL, uint len=0)
	{ Address = addr; Length = len; }

	inline static gstring Create(T* str)
	{
		if(sizeof(T) == 1) return gstring(str, strlen(str));
		else if(sizeof(T) == 2) return gstring(str, wcslen(str));
		else return gstring(str, Address.Find(int_Max, 0));
	}

	inline static gstring Create(T* str, uint len)
	{ return gstring(str, len); }

	inline void Destroy()
	{ Address = NULL; Length = 0; }


	// functions
	inline bool IsValid()
	{ return Address.IsValid(); }

	inline gstring Begin(int off=0, uint len=0)
	{ return gstring(Address+off, len); }

	inline gstring End(int off=0, uint len=0)
	{ return gstring(Address+Length+off, len); }

	inline gstring BeginFull(int off=0, int lenOff=0)
	{ return gstring(Address+off, (uint)(Length+lenOff)); }

	inline gstring EndFull(int off=0, int lenOff=0)
	{ return gstring(Address+Length+off, (uint)(Length+lenOff)); }

	inline gstring Fill(T val, uint len=Length)
	{ Address.Fill(val, len); return *this; }

	inline gstring FillZero(uint len=Length)
	{ Address.FillZero(len); return *this; }

	inline gstring Copy(gstring str)
	{ Address.Copy(str, str.Length); return gstring(Address, str.Length); }

	inline void Move(gstring str)
	{ Address.Move(str, str.Length); return gstring(Address, str.Length); }

	inline gstring Concat(gstring str)
	{
		if(Address+Length != str.Address)
		{ address<T>(Address+Length).Move(str.Address, str.Length); }
		return gstring(Address, Length+str.Length);
	}

	inline int Compare(gstring str) const
	{
		int cmp = Address.Compare(str, (Length < str.Length)? Length : str.Length);
		if(cmp) return cmp;
		return Length - str.Length;
	}

	inline bool Equals(gstring str) const
	{
		if(Length != str.Length) return false;
		return Address.Compare(str, Length) == 0;
	}

	inline address<T> Find(T val)
	{ return Address.Find(val, Length); }

	inline address<T> Find(gstring str) const
	{
		uint len = Length - str.Length + 1;
		for(T* ptr=Address; len; ++ptr, --len)
		{ if(address<T>(ptr).Equals(str, str.Length)) return ptr; }
		return NULL;
	}

	inline address<T> FindLast(T val)
	{ return Address.FindLast(val, Length); }

	inline address FindLast(gstring str) const
	{
		uint len = Length - str.Length + 1;
		for(T* ptr=Address+len-1; len; --ptr, --len)
		{ if(address<T>(ptr).Equals(str, str.Length)) return ptr; }
		return NULL;
	}

	inline int IndexOf(T val)
	{ return Address.IndexOf(val, Length); }

	inline int IndexOf(gstring str) const
	{
		T* ptr = Find(str);
		return (ptr)? (int)(ptr - Address) : -1;
	}

	inline int IndexOfLast(T val)
	{ return Address.IndexOfLast(val, Length); }

	inline int IndexOfLast(gstring str) const
	{
		T* ptr = FindLast(str);
		return (ptr)? (int)(ptr - Address) : -1;
	}

	inline gstring Reverse()
	{
		uint len = Length/2;
		for(T* ptr1=Address, ptr2=Address+Length-1; len; ++ptr1, --ptr2, --len)
		{ *ptr1 ^= *ptr2; *ptr2 ^= *ptr1; *ptr1 ^= *ptr2; }
		return *this;
	}

	inline gstring ToLowerCase()
	{
		uint len = Length;
		for(T* ptr=Address; len; ++ptr, --len)
		{ *ptr = gchar<T>(*ptr).GetLowerCase(); }
		return *this;
	}

	inline gstring ToUpperCase()
	{
		uint len = Length;
		for(T* ptr=Address; len; ++ptr, --len)
		{ *ptr = gchar<T>(*ptr).GetUpperCase(); }
		return *this;
	}

	




}; // end class gstring


} // end namespace wind


#endif /* _DATA_GSTRING_H_ */