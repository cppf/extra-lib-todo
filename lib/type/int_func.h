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
 * type\int_func.h - Provides functions for integer character
 * This file is part of the Wind library for C++.
 */

#ifndef _TYPE_INT_FUNC_H_
#define _TYPE_INT_FUNC_H_


// required headers
#include "primitives.h"
#include "gchar_func.h"


namespace wind {


// functions
template <typename Tint, typename Tstr>
bool int_Parse(Tint* dst, Tstr* str, uint len, uint base=0)
{
	// get base from end
	byte ch = gchar_GetLowerCase(str[len-1]);
	if(ch == 'o' || ch == 'd' || ch =='h')
	{
		--len;
		if(ch == 'o') base = 8;
		else if(ch == 'd') base = 10;
		else base = 16;
	}
	// get sign
	bool neg = false;
	if(*str == '-')
	{ neg = true; ++str; --len; }
	// get base from begin
	if(*str == '0')
	{
		ch = gchar_GetLowerCase(str[1]);
		if(ch == 't' || ch == 'c' || ch =='x')
		{
			str += 2; len -= 2;
			if(ch == 't') base = 8;
			else if(ch == 'c') base = 10;
			else base = 16;
		}
	}
	// default base = 10
	if(base == 0) base = 10;
	// parse integer
	Tint num = 0;
	for(; len; ++str, --len)
	{
		ch = gchar_GetLowerCase(*str);
		ch = (ch <= '9')? ch - '0' : ch - 'a' + 10;
		if(ch >= base) return false;
		num = num*base + ch;
	}
	*dst = (neg)? -num : num;
	return true;
}


} // end namespace wind


#endif /* _TYPE_INT_FUNC_H_ */