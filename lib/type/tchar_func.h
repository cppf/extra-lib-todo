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
 * type\tchar_func.h - Provides generic text (from TEXT_MODE) character functions
 * This file is part of the Wind library for C++.
 */

#ifndef _TYPE_TCHAR_FUNC_H_
#define _TYPE_TCHAR_FUNC_H_


// required headers
#include "primitives.h"


namespace wind {


// functions
inline bool tchar_IsLowerCase(tchar ch)
{ return (ch >= tcharof('a')) && (ch <= tcharof('z')); }

inline bool tchar_IsUpperCase(tchar ch)
{ return (ch >= tcharof('A')) && (ch <= tcharof('Z')); }

inline bool tchar_IsAlphabet(tchar ch)
{ return tchar_IsLowerCase(ch) || tchar_IsUpperCase(ch); }

inline bool tchar_IsDigit(tchar ch)
{ return (ch >= tcharof('0')) && (ch <= tcharof('9')); }

inline tchar tchar_GetLowerCase(tchar ch)
{ return tchar_IsUpperCase(ch)? (ch - tcharof('A') + tcharof('a')) : ch; }

inline tchar tchar_GetUpperCase(tchar ch)
{ return tchar_IsLowerCase(ch)? (ch - tcharof('a') + tcharof('A')) : ch; }

inline char tchar_GetChar(tchar ch)
{ return (char) ch; }

inline wchar tchar_GetWchar(tchar ch)
{ return (wchar) ch; }

inline tchar tchar_GetTchar(tchar ch)
{ return ch; }


} // end namespace wind


#endif /* _TYPE_TCHAR_FUNC_H_ */