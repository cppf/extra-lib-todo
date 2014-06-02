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
 * type\wchar.h - Unicode (wide) character wrapper class
 */

#ifndef _TYPE_WCHAR_H_
#define _TYPE_WCHAR_H_


// required headers
#include "wchar_func.h"


namespace wind {


// wide character wrapper class
// can be type casted to wchar
class wchar_
{


public:
	// wchar value
	wchar Value;


public:
	// initialization
	inline wchar_()
	{ Value = L'\0'; }

	inline wchar_(wchar ch)
	{ Value = ch; }

	inline void operator=(wchar ch)
	{ Value = ch; }

	inline operator wchar() const
	{ return Value; }

	// functions
	inline bool IsLowerCase() const
	{ return wchar_IsLowerCase(Value); }

	inline bool IsUpperCase() const
	{ return wchar_IsUpperCase(Value); }

	inline bool IsAlphabet() const
	{ return wchar_IsAlphabet(Value); }

	inline bool IsDigit() const
	{ return wchar_IsDigit(Value); }

	inline wchar_ GetLowerCase() const
	{ return (wchar_) wchar_GetLowerCase(Value); }

	inline wchar_ GetUpperCase() const
	{ return (wchar_) wchar_GetUpperCase(Value); }

	inline char GetChar() const
	{ return (char) Value; }

	inline wchar GetWchar() const
	{ return Value; }

	inline tchar GetTchar() const
	{ return (tchar) Value; }


}; // end class wchar_


} // end namespace wind


#endif /* _TYPE_WCHAR_H_ */