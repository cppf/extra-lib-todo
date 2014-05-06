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
 * merge.hpp - token merging macro
 */

#ifndef _MAKE_MERGE_HPP_
#define _MAKE_MERGE_HPP_


// required headers
#include "macro.hpp"


// token merger
#ifndef merge
#define merge2(a, b)											a##b
#define merge3(a, b, c)											a##b##c
#define merge4(a, b, c, d)										a##b##c##d
#define merge5(a, b, c, d, e)									a##b##c##d##e
#define merge6(a, b, c, d, e, f)								a##b##c##d##e##f
#define merge7(a, b, c, d, e, f, g)								a##b##c##d##e##f##g
#define merge8(a, b, c, d, e, f, g, h)							a##b##c##d##e##f##g##h
#define merge9(a, b, c, d, e, f, g, h, i)						a##b##c##d##e##f##g##h##i
#define merge10(a, b, c, d, e, f, g, h, i, j)					a##b##c##d##e##f##g##h##i##j##k
#define merge11(a, b, c, d, e, f, g, h, i, j, k)				a##b##c##d##e##f##g##h##i##j##k##l
#define merge12(a, b, c, d, e, f, g, h, i, j, k, l)				a##b##c##d##e##f##g##h##i##j##k##l
#define merge13(a, b, c, d, e, f, g, h, i, j, k, l, m)			a##b##c##d##e##f##g##h##i##j##k##l##m
#define merge14(a, b, c, d, e, f, g, h, i, j, k, l, m, n)		a##b##c##d##e##f##g##h##i##j##k##l##m##n
#define merge15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o)	a##b##c##d##e##f##g##h##i##j##k##l##m##n##o
#define merge16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p)	a##b##c##d##e##f##g##h##i##j##k##l##m##n##o##p

#define merge(...)	\
macro_Fn(macro_Fn16(__VA_ARGS__, merge16, merge15, merge14, merge13, merge12, merge11, merge10, merge9, merge8, merge7, merge6, merge5, merge4, merge3, merge2)(__VA_ARGS__))
#endif // !merge


#endif /* _MAKE_MERGE_HPP_ */