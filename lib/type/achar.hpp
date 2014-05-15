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
 * achar.hpp - ascii character
 */

#ifndef _TYPE_ACHAR_HPP_
#define _TYPE_ACHAR_HPP_


// required headers
#include "basic.hpp"
#include "char.hpp"


namespace wind
{


// ascii character class
// can be type casted to char
// provides associated functions
class achar
{
public:


	// achar value
	char Value;


	// for type conversion
	inline achar()
	{ Value = '\0'; }

	inline achar(char ch)
	{ Value = ch; }

	inline void operator=(char ch)
	{ Value = ch; }

	inline operator char() const
	{ return Value; }

	// achar functions
	inline bool IsLowerCase() const
	{ return char_IsLowerCase(Value); }

	inline bool IsUpperCase() const
	{ return char_IsUpperCase(Value); }

	inline bool IsAlphabet() const
	{ return char_IsAlphabet(Value); }

	inline bool IsDigit() const
	{ return char_IsDigit(Value); }

	inline bool IsBlank() const
	{ return char_IsBlank(Value); }

	inline bool IsSpace() const
	{ return char_IsSpace(Value); }

	inline achar GetLowerCase() const
	{ return (achar) char_GetLowerCase(Value); }

	inline achar GetUpperCase() const
	{ return (achar) char_GetUpperCase(Value); }

	inline wchar GetWchar() const
	{ return char_GetWchar(Value); }

	inline tchar GetTchar() const
	{ return char_GetTchar(Value); }


}; // end class achar


} // end namespace wind


#endif /* _TYPE_ACHAR_HPP_ */