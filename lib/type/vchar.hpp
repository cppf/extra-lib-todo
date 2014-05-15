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
 * vchar.hpp - varaible character (ascii / unicode)
 */

#ifndef _TYPE_VCHAR_HPP_
#define _TYPE_VCHAR_HPP_


// required headers
#include "basic.hpp"
#include "tchar.hpp"


namespace wind
{


// variable character class
// can be type casted to thcar
// provides associated functions
class vchar
{
public:


	// vchar value
	tchar Value;


	// for type conversion
	inline vchar()
	{ Value = tcharof('\0'); }

	inline vchar(tchar ch)
	{ Value = ch; }

	inline void operator=(char ch)
	{ Value = (tchar) ch; }

	inline void operator=(tchar ch)
	{ Value = ch; }

	inline operator tchar() const
	{ return Value; }

	// achar functions
	inline bool IsLowerCase() const
	{ return tchar_IsLowerCase(Value); }

	inline bool IsUpperCase() const
	{ return tchar_IsUpperCase(Value); }

	inline bool IsAlphabet() const
	{ return tchar_IsAlphabet(Value); }

	inline bool IsDigit() const
	{ return tchar_IsDigit(Value); }

	inline bool IsBlank() const
	{ return tchar_IsBlank(Value); }

	inline bool IsSpace() const
	{ return tchar_IsSpace(Value); }

	inline vchar GetLowerCase() const
	{ return (vchar) tchar_GetLowerCase(Value); }

	inline vchar GetUpperCase() const
	{ return (vchar) tchar_GetUpperCase(Value); }

	inline char GetChar() const
	{ return tchar_GetChar(Value); }

	inline wchar GetWchar() const
	{ return tchar_GetWchar(Value); }


}; // end class achar


} // end namespace wind


#endif /* _TYPE_VCHAR_HPP_ */