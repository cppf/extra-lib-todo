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
 * basic.hpp - basic memory macros
 */

#ifndef _MEM_BASIC_HPP_
#define _MEM_BASIC_HPP_


#define address(base, off)	\
(((char*)(base)) + (off))


// swap variables
#define	mem_Swap3(a, b, temp)	\
macro_Begin		\
temp = a;	\
a = b;		\
b = temp;	\
macro_End

#define	mem_Swap2(a, b)	\
macro_Begin	\
a ^= b;	\
b ^= a;	\
a ^= b;	\
macro_End

#define	mem_Swap(...)	\
macro_Fn(macro_Fn3(__VA_ARGS__, mem_Swap3, mem_Swap2)(__VA_ARGS__))


// write variables to memory
#define	mem_Write1(dst, var1)	\
(*((typeof(var1)*)(dst)) = var1)

#define	mem_Write2(dst, var1, var2)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
macro_End

#define	mem_Write3(dst, var1, var2, var3)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
macro_End

#define	mem_Write4(dst, var1, var2, var3, var4)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeof(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
macro_End

#define	mem_Write5(dst, var1, var2, var3, var4, var5)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeof(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeof(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
macro_End

#define	mem_Write6(dst, var1, var2, var3, var4, var5, var6)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeof(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeof(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((typeof(var6)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
macro_End

#define	mem_Write7(dst, var1, var2, var3, var4, var5, var6, var7)	\
macro_Begin	\
*((typeof(var1)*)(dst)) = var1;	\
*((typeof(var2)*)((char*)(dst) + sizeof(var1))) = var2;	\
*((typeof(var3)*)((char*)(dst) + sizeof(var1) + sizeof(var2))) = var3;	\
*((typeof(var4)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3))) = var4;	\
*((typeof(var5)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4))) = var5;	\
*((typeof(var6)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5))) = var6;	\
*((typeof(var7)*)((char*)(dst) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6))) = var7;	\
macro_End

#define	mem_Write8(dst, var1, var2, var3, var4, var5, var6, var7, var8)	\
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

#define	mem_Write(...)	\
macro_Fn(macro_Fn10(_0, __VA_ARGS__, mem_Write8, mem_Write7, mem_Write6, mem_Write5, mem_Write4, mem_Write3, mem_Write2, mem_Write1, macro_FnE, macro_FnE)(__VA_ARGS__))

#define mem_Save	mem_Write


// read variables from memory
#define	mem_Read1(src, var1)	\
(var1 = *((typeof(var1)*)(src)))

#define	mem_Read2(src, var1, var2)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
macro_End

#define	mem_Read3(src, var1, var2, var3)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
macro_End

#define	mem_Read4(src, var1, var2, var3, var4)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeof(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
macro_End

#define	mem_Read5(src, var1, var2, var3, var4, var5)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeof(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeof(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
macro_End

#define	mem_Read6(src, var1, var2, var3, var4, var5, var6)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeof(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeof(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((typeof(var6)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
macro_End

#define	mem_Read7(src, var1, var2, var3, var4, var5, var6, var7)	\
macro_Begin	\
var1 = *((typeof(var1)*)(src));	\
var2 = *((typeof(var2)*)((char*)(src) + sizeof(var1)));	\
var3 = *((typeof(var3)*)((char*)(src) + sizeof(var1) + sizeof(var2)));	\
var4 = *((typeof(var4)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3)));	\
var5 = *((typeof(var5)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4)));	\
var6 = *((typeof(var6)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5)));	\
var7 = *((typeof(var7)*)((char*)(src) + sizeof(var1) + sizeof(var2) + sizeof(var3) + sizeof(var4) + sizeof(var5) + sizeof(var6)));	\
macro_End

#define	mem_Read8(src, var1, var2, var3, var4, var5, var6, var7, var8)	\
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

#define	mem_Read(...)	\
macro_Fn(macro_Fn10(_0, __VA_ARGS__, mem_Read8, mem_Read7, mem_Read6, mem_Read5, mem_Read4, mem_Read3, mem_Read2, mem_Read1, macro_FnE, macro_FnE)(__VA_ARGS__))


#endif /* _MEM_BASIC_HPP_ */