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
 * uchar.hpp - unicode character
 */

#ifndef _TYPE_UCHAR_HPP_
#define _TYPE_UCHAR_HPP_


// required headers
#include "basic.hpp"
#include "wchar.hpp"


namespace wind
{


// unicode character class
// can be type casted to whcar
// provides associated functions
class uchar
{
public:


	// uchar value
	wchar Value;


	// for type conversion
	inline uchar()
	{ Value = L'\0'; }

	inline uchar(wchar ch)
	{ Value = ch; }

	inline void operator=(char ch)
	{ Value = (wchar) ch; }

	inline void operator=(wchar ch)
	{ Value = ch; }

	inline operator wchar() const
	{ return Value; }

	// achar functions
	inline bool IsLowerCase() const
	{ return wchar_IsLowerCase(Value); }

	inline bool IsUpperCase() const
	{ return wchar_IsUpperCase(Value); }

	inline bool IsAlphabet() const
	{ return wchar_IsAlphabet(Value); }

	inline bool IsDigit() const
	{ return wchar_IsDigit(Value); }

	inline bool IsBlank() const
	{ return wchar_IsBlank(Value); }

	inline bool IsSpace() const
	{ return wchar_IsSpace(Value); }

	inline uchar GetLowerCase() const
	{ return (uchar) wchar_GetLowerCase(Value); }

	inline uchar GetUpperCase() const
	{ return (uchar) wchar_GetUpperCase(Value); }

	inline char GetChar() const
	{ return wchar_GetChar(Value); }

	inline tchar GetTchar() const
	{ return wchar_GetTchar(Value); }


}; // end class achar


} // end namespace wind


#endif /* _TYPE_UCHAR_HPP_ */