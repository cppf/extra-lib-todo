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
 * wchar.hpp - wide (unicode) character wrapper
 */

#ifndef _TYPE_WCHAR_HPP_
#define _TYPE_WCHAR_HPP_


namespace wind
{


// wide character wrapper class
// can be type casted to wchar
class wchar_
{
public:


	// wchar value
	wchar Value;


	// for type conversion
	inline wchar_()
	{ Value = '\0'; }

	inline wchar_(wchar ch)
	{ Value = ch; }

	inline void operator=(wchar ch)
	{ Value = ch; }

	inline operator wchar() const
	{ return Value; }

	// wrapper functionality
	inline bool IsLowerCase() const
	{ return (Value >= L'a') && (Value <= L'z'); }

	inline bool IsUpperCase() const
	{ return (Value >= L'A') && (Value <= L'Z'); }

	inline bool IsAlphabet() const
	{ return IsLowerCase() || IsUpperCase(); }

	inline bool IsDigit() const
	{ return (Value >= L'0') && (Value <= L'9'); }

	inline bool IsBlank() const
	{ return (Value == L'\t') || (Value == L' '); }

	inline bool IsSpace() const
	{ return IsBlank(); }

	inline wchar_ GetLowerCase() const
	{ return (wchar_) IsUpperCase()? (Value - L'A' + L'a') : Value; }

	inline wchar_ GetUpperCase() const
	{ return (wchar_) IsLowerCase()? (Value - L'a' + L'A') : Value; }

	inline char GetChar() const
	{ return (char) Value; }

	inline wchar GetWchar() const
	{ return Value; }

	inline tchar GetTchar() const
	{ return (tchar) Value; }


}; // end class wchar_


} // end namespace wind


#endif /* _TYPE_WCHAR_HPP_ */