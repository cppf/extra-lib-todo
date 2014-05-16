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
 * tchar.hpp - text character functions and wrapper
 */

#ifndef _TYPE_TCHAR_HPP_
#define _TYPE_TCHAR_HPP_


// required headers
#include "..\make\const.hpp"
#include "basic.hpp"


namespace wind
{


// tchar functions
inline bool tchar_IsLowerCase(tchar ch)
{ return (ch >= tcharof('a')) && (ch <= tcharof('z')); }

inline bool tchar_IsUpperCase(tchar ch)
{ return (ch >= tcharof('A')) && (ch <= tcharof('Z')); }

inline bool tchar_IsAlphabet(tchar ch)
{ return tchar_IsLowerCase(ch) || tchar_IsUpperCase(ch); }

inline bool tchar_IsDigit(tchar ch)
{ return (ch >= tcharof('0')) && (ch <= tcharof('9')); }

inline bool tchar_IsBlank(tchar ch)
{ return (ch == tcharof('\t')) || (ch == tcharof(' ')); }

inline bool tchar_IsSpace(tchar ch)
{ return tchar_IsBlank(ch); }

inline tchar tchar_GetLowerCase(tchar ch)
{ return tchar_IsUpperCase(ch)? (ch - tcharof('A') + tcharof('a')) : ch; }

inline tchar tchar_GetUpperCase(tchar ch)
{ return tchar_IsLowerCase(ch)? (ch - tcharof('a') + tcharof('A')) : ch; }

inline char tchar_GetChar(tchar ch)
{ return (char) ch; }

inline wchar tchar_GetWchar(tchar ch)
{ return (wchar) ch; }


// text character wrapper
// can be type casted to tchar
class tchar_
{
public:


	// vchar value
	tchar Value;


	// for type conversion
	inline tchar_()
	{ Value = tcharof('\0'); }

	inline tchar_(tchar ch)
	{ Value = ch; }

	inline void operator=(char ch)
	{ Value = (tchar) ch; }

#if CHAR_MODE == UNICODE
	inline void operator=(tchar ch)
	{ Value = ch; }
#endif

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

	inline tchar_ GetLowerCase() const
	{ return (tchar_) tchar_GetLowerCase(Value); }

	inline tchar_ GetUpperCase() const
	{ return (tchar_) tchar_GetUpperCase(Value); }

	inline void ToLowerCase()
	{ Value = tchar_GetLowerCase(Value); }

	inline void ToUpperCase()
	{ Value = tchar_GetUpperCase(Value); }

	inline char GetChar() const
	{ return tchar_GetChar(Value); }

	inline wchar GetWchar() const
	{ return tchar_GetWchar(Value); }


}; // end class achar


} // end namespace wind


#endif /* _TYPE_CHAR_HPP_ */