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
 * char.hpp - character functions and wrapper
 */

#ifndef _TYPE_CHAR_HPP_
#define _TYPE_CHAR_HPP_


namespace wind
{


// char functions
inline bool char_IsLowerCase(char ch)
{ return (ch >= 'a') && (ch <= 'z'); }

inline bool char_IsUpperCase(char ch)
{ return (ch >= 'A') && (ch <= 'Z'); }

inline bool char_IsAlphabet(char ch)
{ return char_IsLowerCase(ch) || char_IsUpperCase(ch); }

inline bool char_IsDigit(char ch)
{ return (ch >= '0') && (ch <= '9'); }

inline bool char_IsBlank(char ch)
{ return (ch == '\t') || (ch == ' '); }

inline bool char_IsSpace(char ch)
{ return char_IsBlank(ch); }

inline char char_GetLowerCase(char ch)
{ return char_IsUpperCase(ch)? (ch - 'A' + 'a') : ch; }

inline char char_GetUpperCase(char ch)
{ return char_IsLowerCase(ch)? (ch - 'a' + 'A') : ch; }

inline wchar char_GetWchar(char ch)
{ return (wchar) ch; }

inline tchar char_GetTchar(char ch)
{ return (tchar) ch; }


// character wrapper class
// can be type casted to char
class char_
{
public:


	// char value
	char Value;


	// for type conversion
	inline char_()
	{ Value = '\0'; }

	inline char_(char ch)
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

	inline char_ GetLowerCase() const
	{ return (char_) char_GetLowerCase(Value); }

	inline char_ GetUpperCase() const
	{ return (char_) char_GetUpperCase(Value); }

	inline void ToLowerCase()
	{ Value = char_GetLowerCase(Value); }

	inline void ToUpperCase()
	{ Value = char_GetUpperCase(Value); }

	inline wchar GetWchar() const
	{ return char_GetWchar(Value); }

	inline tchar GetTchar() const
	{ return char_GetTchar(Value); }


}; // end class achar


} // end namespace wind


#endif /* _TYPE_CHAR_HPP_ */