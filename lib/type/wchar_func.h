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
 * type\wchar_func.h - Provides standard Unicode (wide) character functions
 * This file is part of the Wind library for C++.
 */

#ifndef _TYPE_WCHAR_FUNC_H_
#define _TYPE_WCHAR_FUNC_H_


// required headers
#include "primitives.h"


namespace wind {


// functions
inline bool wchar_IsLowerCase(wchar ch)
{ return (ch >= L'a') && (ch <= L'z'); }

inline bool wchar_IsUpperCase(wchar ch)
{ return (ch >= L'A') && (ch <= L'Z'); }

inline bool wchar_IsAlphabet(wchar ch)
{ return wchar_IsLowerCase(ch) || wchar_IsUpperCase(ch); }

inline bool wchar_IsDigit(wchar ch)
{ return (ch >= L'0') && (ch <= L'9'); }

inline wchar wchar_GetLowerCase(wchar ch)
{ return wchar_IsUpperCase(ch)? (ch - L'A' + L'a') : ch; }

inline wchar wchar_GetUpperCase(wchar ch)
{ return wchar_IsLowerCase(ch)? (ch - L'a' + L'A') : ch; }

inline char wchar_GetChar(wchar ch)
{ return (char) ch; }

inline wchar wchar_GetWwchar(wchar ch)
{ return ch; }

inline tchar wchar_GetTwchar(wchar ch)
{ return (tchar) ch; }


} // end namespace wind


#endif /* _TYPE_WCHARF_H_ */