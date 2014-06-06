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
 * type\gchar.h - Defines a generic character wrapper class with source-type functions
 * This file is part of the Wind library for C++.
 */

#ifndef _TYPE_GCHAR_H_
#define _TYPE_GCHAR_H_


// required headers
#include "primitives.h"
#include "gchar_func.h"


namespace wind {


// generic character wrapper class
// can be type casted to type
template <typename T>
class gchar
{


public:
	// data
	T Value;


public:
	// initialization
	inline operator T() const
	{ return Value; }

	inline gchar(T ch='\0')
	{ Value = ch; }

	inline static gchar Create(T ch='\0')
	{ return gchar(ch); }

	inline void Destroy()
	{ Value = '\0'; }

	// operators
	inline gchar operator ++()
	{ return ++Value; }

	inline gchar operator ++(T)
	{ return Value++; }

	inline void operator +=(gchar ch)
	{ Value += ch.Value; }

	inline void operator -= (gchar ch)
	{ Value -= ch.Value; }

	// functions
	inline bool IsLowerCase() const
	{ return gchar_IsLowerCase(Value); }

	inline bool IsUpperCase() const
	{ return gchar_IsUpperCase(Value); }

	inline bool IsAlphabet() const
	{ return gchar_IsAlphabet(Value);; }

	inline bool IsDigit() const
	{ return gchar_IsDigit(Value); }

	inline gchar GetLowerCase() const
	{ return gchar_GetLowerCase(Value); }

	inline gchar GetUpperCase() const
	{ return gchar_GetUpperCase(Value); }

	inline char GetChar() const
	{ return gchar_GetChar(Value); }

	inline wchar GetWchar() const
	{ return gchar_GetWchar(Value); }

	inline tchar GetTchar() const
	{ return gchar_GetTchar(Value); }


}; // end class gchar


// ANSI character wrapper
typedef gchar<char> char_;


// Unicode (wide) character wrapper
typedef gchar<wchar> wchar_;


// Text (from TEXT_MODE) character wrapper
typedef gchar<tchar> tchar_;


} // end namespace wind


#endif /* _TYPE_GCHAR_H_ */