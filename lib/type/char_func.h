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
 * type\char_func.h - Provides standard generic character functions
 * This file is part of the Wind library for C++.
 */

#ifndef _TYPE_CHAR_FUNC_H_
#define _TYPE_CHAR_FUNC_H_


// required headers
#include "primitives.h"


namespace wind {


// functions
template <typename T>
inline bool isLowerCase(T ch)
{ return (ch >= 'a') && (ch <= 'z'); }

template <typename T>
inline bool isUpperCase(T ch)
{ return (ch >= 'A') && (ch <= 'Z'); }

template <typename T>
inline bool isAlphabet(T ch)
{ return isLowerCase(ch) || isUpperCase(ch); }

template <typename T>
inline bool isDigit(T ch)
{ return (ch >= '0') && (ch <= '9'); }

template <typename T>
inline T lowerCaseOf(T ch)
{ return isUpperCase(ch)? ch - 'A' + 'a' : ch; }

template <typename T>
inline T upperCaseOf(T ch)
{ return isLowerCase(ch)? ch - 'a' + 'A' : ch; }

template <typename T>
inline char charOf(T ch)
{ return (char) ch; }

template <typename T>
inline wchar wcharOf(T ch)
{ return (wchar) ch; }

template <typename T>
inline tchar tcharOf(T ch)
{ return (tchar) ch; }


} // end namespace wind


#endif /* _TYPE_CHAR_FUNC_H_ */