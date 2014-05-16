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
 * string.hpp - string functions and wrapper
 */

#ifndef _TYPE_STRING_HPP_
#define _TYPE_STRING_HPP_


// required headers
#include "..\make\const.hpp"
#include "basic.hpp"
#include <string.h>


namespace wind
{


// definition
typedef char*	string;


// string functions
inline int string_Length(const char* str)
{ return strlen(str); }

inline int string_Compare(const char* str1, const char* str2)
{ return strcmp(str1, str2); }

inline char* string_ToLower(char* str)
{ return NULL; /*strlwr(str);*/ }

inline char* string_ToUpper(char* str)
{ return NULL; /*strupr(str);*/ }

inline char* string_CopyTo(char* dst, const char* src)
{ return NULL; /*strcpy(dst, src);*/ }

inline char* string_Reverse(char* str)
{ return NULL; /*strrev(str);*/ }

inline char* string_Concat(char* dst, const char* src)
{ return NULL; }
#define string_Concat		strcat
#define string_Reverse		strrev
#define string_IndexOfChar	strchr
#define string_FindChar		strchr
#define string_LastIndexOf	strrchr
#define string_IndexOfChars	strpbrk 
#define string_FindChars	strpbrk 
#define string_IndexOf		strstr
#define string_Find			strstr


// string equality (true if equals)
#define	string_Equals(str1, str2)	\
	(!string_Compare(str1, str2))


// find substring of a string
#define string_Substring3(dst, str, start)	\
string_Copy(dst, (str)+(start))

#define string_Substring4(dst, str, start, stop)	\
mem_Copy(dst, (str)+(start), (stop)-(start))

#define string_Substring(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, string_Substring4, string_Substring3)(__VA_ARGS__))


// remove part of a string
#define string_Remove2(str, start)	\
(*(((char*)(str))+(start)) = '\0')

#define string_Remove3(str, start, stop)	\
string_Copy((str)+(start), (str)+(stop))

#define string_Remove(...)	\
macro_Fn(macro_Fn3(__VA_ARGS__, string_Remove3, string_Remove2)(__VA_ARGS__))


 } // end namespace wind


#endif /* _TYPE_STRING_HPP_ */