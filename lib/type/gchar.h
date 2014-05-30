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
 * type\gchar.h - generic character wrapper class
 */

#ifndef _TYPE_GCHAR_H_
#define _TYPE_GCHAR_H_


// required headers
#include "gcharF.h"


#ifdef __cplusplus
namespace wind
{


// generic character wrapper class
// can be type casted to type T
template <typename T>
class gchar_
{


public:
	// wchar value
	T Value;


public:
	// initialization
	inline gchar_()
	{ Value = L'\0'; }

	inline gchar_(T ch)
	{ Value = ch; }

	inline void operator=(T ch)
	{ Value = ch; }

	inline operator T() const
	{ return Value; }

	// wrapper functionality
	inline bool IsLowerCase() const
	{ return gchar_IsLowerCase(Value); }

	inline bool IsUpperCase() const
	{ return gchar_IsUpperCase(Value); }

	inline bool IsAlphabet() const
	{ return gchar_IsAlphabet(Value); }

	inline bool IsDigit() const
	{ return gchar_IsDigit(Value); }

	inline gchar_ GetLowerCase() const
	{ return (gchar_) gchar_GetLowerCase(Value); }

	inline gchar_ GetUpperCase() const
	{ return (gchar_) gchar_GetUpperCase(Value); }

	inline char GetChar() const
	{ return (char) Value; }

	inline wchar GetWchar() const
	{ return (wchar) Value; }

	inline tchar GetTchar() const
	{ return (tchar) Value; }


}; // end class gchar_


} // end namespace wind
#endif // !__cplusplus


#endif /* _TYPE_GCHAR_H_ */