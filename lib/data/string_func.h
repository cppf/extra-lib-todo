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
 * string_func.h - Provides functions for performing string operations on a length-specified string
 * This file is part of the Wind library for C++.
 */

#ifndef _DATA_STRING_FUNC_H_
#define _DATA_STRING_FUNC_H_


// required headers
#include "..\support\constants.h"
#include "..\type\primitives.h"
#include "..\memory\block_func.h"
#include <string.h>


namespace wind
{


// length-specified string functions
inline int stringz_Length(const char* str)
{ return strlen(str); }

inline int stringz_Compare(const char* str1, const char* str2)
{ return strcmp(str1, str2); }

inline char* stringz_ToLower(char* str)
{ return strlwr(str); }

inline char* stringz_ToUpper(char* str)
{ return strupr(str); }

inline char* stringz_Copy(char* dst, const char* src)
{ return strcpy(dst, src); }

inline char* stringz_Reverse(char* str)
{ return strrev(str); }

inline char* stringz_Concat(char* dst, const char* str)
{ return strcat(dst, str); }

inline const char* stringz_Find(const char* str, char ch)
{ return strchr(str, ch); }

inline int stringz_IndexOf(const char* str, char ch)
{ const char* ptr = stringz_Find(str, ch); return (ptr)? (int) (ptr-str) : -1; }

inline const char* stringz_FindLast(const char* str, char ch)
{ return strrchr(str, ch); }

inline int stringz_LastIndexOf(const char* str, char ch)
{ const char* ptr = stringz_FindLast(str, ch); return (ptr)? (int) (ptr-str) : -1; }

inline const char* stringz_FindAny(const char* str, const char* chs)
{ return strpbrk(str, chs); }

inline int stringz_IndexOfAny(const char* str, const char* chs)
{ const char* ptr = stringz_FindAny(str, chs); return (ptr)? (int) (ptr-str) : -1; }

inline const char* stringz_Find(const char* str, const char* srchStr)
{ return strstr(str, srchStr); }

inline const int stringz_IndexOf(const char* str, const char* srchStr)
{ const char* ptr = stringz_Find(str, srchStr); return (ptr)? (int) (ptr-str) : -1; }

inline bool stringz_Equals(const char* str1, const char* str2)
{ return !stringz_Compare(str1, str2); }

inline char* stringz_Filter(char* dst, const char* src, int start)
{ stringz_Copy(dst, src + start); return dst; }

inline char* stringz_Filter(char* dst, const char* src, int start, int stop)
{ block_Copy(dst, src+start, stop-start); dst[stop-start] = '\0'; return dst; }

inline char* stringz_Remove(char* str, int start)
{ str[start] = '\0'; return str; }

inline char* stringz_Remove(char* str, int start, int stop)
{ stringz_Copy(str+start, str+stop); return str; }


} // end namespace wind


#endif /* _DATA_STRING_FUNC_H_ */