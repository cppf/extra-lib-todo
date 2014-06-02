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
 * type\char_func.h - Defines ansANSI character wrapper class with standard associated functions
 * This file is part of the Wind library for C++.
 */

#ifndef _TYPE_CHAR_H_
#define _TYPE_CHAR_H_


// required headers
#include "char_func.h"


namespace wind {


// ANSI character wrapper class
// can be type casted to char
class char_
{


public:
	// data
	char Value;


	// initialization
	inline operator char() const
	{ return Value; }

	inline void operator=(char ch)
	{ Value = ch; }

	inline char_(char ch='\0')
	{ Value = ch; }

	inline static char_ Create(char ch='\0')
	{ return char_(ch); }

	inline void Destroy()
	{ Value = '\0'; }

	// functions
	inline bool IsLowerCase() const
	{ return char_IsLowerCase(Value); }

	inline bool IsUpperCase() const
	{ return char_IsUpperCase(Value); }

	inline bool IsAlphabet() const
	{ return char_IsAlphabet(Value); }

	inline bool IsDigit() const
	{ return char_IsDigit(Value); }

	inline char_ GetLowerCase() const
	{ return (char_) char_GetLowerCase(Value); }

	inline char_ GetUpperCase() const
	{ return (char_) char_GetUpperCase(Value); }

	inline char GetChar() const
	{ return Value; }

	inline wchar GetWchar() const
	{ return (wchar) Value; }

	inline tchar GetTchar() const
	{ return (tchar) Value; }


}; // end class char_


} // end namespace wind


#endif /* _TYPE_CHAR_H_ */