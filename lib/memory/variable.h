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
 * memory\variable.h - Provides variable related macros
 * This file is part of the Wind library for C++.
 */

#ifndef _MEMORY_VARIABLE_H_
#define _MEMORY_VARIABLE_H_


// required headers
#include "..\support\keywords.h"
#include "..\support\macro_overloading.h"


// swap variables
#define	var_Swap3(a, b, temp)	\
macro_Begin		\
temp = a;	\
a = b;		\
b = temp;	\
macro_End

#define	var_Swap2(a, b)	\
macro_Begin	\
a ^= b;	\
b ^= a;	\
a ^= b;	\
macro_End

#define	var_Swap(...)	\
macro_Fn(macro_Fn3(__VA_ARGS__, var_Swap3, var_Swap2)(__VA_ARGS__))


// write variables to memory
#define	var_Write2(dst, var1)	\
(*((typeof(var1)*)(dst)) = var1)

#define	var_Write3(dst, var1, var2)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
macro_End

#define	var_Write4(dst, var1, var2, var3)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
macro_End

#define	var_Write5(dst, var1, var2, var3, var4)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeof(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
macro_End

#define	var_Write6(dst, var1, var2, var3, var4, var5)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeof(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeof(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
macro_End

#define	var_Write7(dst, var1, var2, var3, var4, var5, var6)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeof(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeof(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((typeof(var6)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
macro_End

#define	var_Write8(dst, var1, var2, var3, var4, var5, var6, var7)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeof(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeof(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((typeof(var6)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
*((typeof(var7)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6))) = var7;	\
macro_End

#define	var_Write9(dst, var1, var2, var3, var4, var5, var6, var7, var8)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeof(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeof(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((typeof(var6)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
*((typeof(var7)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6))) = var7;	\
*((typeof(var8)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6) + sizeof(var7))) = var8;	\
macro_End

#define	var_Write(...)	\
macro_Fn(macro_Fn10(_0, __VA_ARGS__, var_Write9, var_Write8, var_Write7, var_Write6, var_Write5, var_Write4, var_Write3, var_Write2, macro_FnE, macro_FnE)(__VA_ARGS__))

#define var_Save	var_Write


// read variables from memory
#define	var_Read2(src, var1)	\
(var1 = *((typeof(var1)*)(src)))

#define	var_Read3(src, var1, var2)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
macro_End

#define	var_Read4(src, var1, var2, var3)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
macro_End

#define	var_Read5(src, var1, var2, var3, var4)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeof(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
macro_End

#define	var_Read6(src, var1, var2, var3, var4, var5)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeof(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeof(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
macro_End

#define	var_Read7(src, var1, var2, var3, var4, var5, var6)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeof(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeof(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((typeof(var6)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
macro_End

#define	var_Read8(src, var1, var2, var3, var4, var5, var6, var7)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeof(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeof(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((typeof(var6)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
var7 = *((typeof(var7)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6)));	\
macro_End

#define	var_Read9(src, var1, var2, var3, var4, var5, var6, var7, var8)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeof(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeof(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((typeof(var6)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
var7 = *((typeof(var7)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6)));	\
var8 = *((typeof(var8)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6) + sizeof(var7)));	\
macro_End

#define	var_Read(...)	\
macro_Fn(macro_Fn10(_0, __VA_ARGS__, var_Read9, var_Read8, var_Read7, var_Read6, var_Read5, var_Read4, var_Read3, var_Read2, macro_FnE, macro_FnE)(__VA_ARGS__))

#define	var_Load	var_Read


#endif /* _MEMORY_VARIABLE_H_ */