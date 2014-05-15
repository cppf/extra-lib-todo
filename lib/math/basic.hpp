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
 * basic.hpp - basic math functions
 */

#ifndef _MATH_BASIC_HPP_
#define _MATH_BASIC_HPP_


// header config
#define	_USE_MATH_DEFINES


// required headers
#include <math.h>
#include "..\make\macro.hpp"
#include "..\type\basic.hpp"


// constants
#define	E				M_E
#define	LOG2_BASE_E		M_LOG2E
#define	LOG10_BASE_E	M_LOG10E
#define	LN2				M_LN2
#define	LN10			M_LN10
#define	PI				M_PI
#define	PI_BY_2			M_PI_2
#define	PI_BY_4			M_PI_4
#define	ONE_BY_PI		M_1_PI
#define	TWO_BY_PI		M_2_PI
#define	TWO_BY_SQRT_PI	M_2_SQRTPI
#define	SQRT_2			M_SQRT2
#define	SQRT_1_BY_2		M_SQRT1_2
#ifdef ININITY
#define	INF				INFINITY
#endif // ININITY


// functions
#define	Cos(x)				cos(x)
#define	Sin(x)				sin(x)
#define	Tan(x)				tan(x)
#define	Mod(x, y)			fmod(x, y)
#define	Sqrt(x)				sqrt(x)
#define	Hypotenuse(x, y)	hypot(x, y)
#define	Floor(x)			floor(x)
#define	Ceil(x)				ceil(x)
#define	Exp(x)				exp(x)
#define	Cosh(x)				cosh(x)
#define	Sinh(x)				sinh(x)
#define	Tanh(x)				tanh(x)
#define	CosInv(x)			acos(x)
#define	SinInv(x)			asin(x)
#define	TanInv(x)			atan(x)
#define	TanInv2(y, x)		atan2(y, x)
#define	Log(x)				log(x)
#define	Log10(x)			log10(x)
#define	Pow(x, y)			pow(x, y)


// maximum of values
template <typename T>
inline T Max(T a, T b)
{
	return (a > b)? a : b;
}

template <typename T>
inline T Max(T a, T b, T c)
{
	return Max(Max(a, b), c);
}

template <typename T>
inline T Max(T a, T b, T c, T d)
{
	return Max(Max(a, b), Max(c, d));
}


// minimum of values
template <typename T>
inline T Min(T a, T b)
{
	return (a < b)? a : b;
}

template <typename T>
inline T Min(T a, T b, T c)
{
	return Min(Min(a, b), c);
}

template <typename T>
inline T Min(T a, T b, T c, T d)
{
	return Min(Min(a, b), Min(c, d));
}


// absolute value
template <typename T>
inline T Abs(T a)
{
	return (a < 0)? -a : a;
}


// sign of value
template <typename T>
inline T Sign(T a)
{
	return (a >= 0)? ((a > 0)? 1 : 0) : -1;
}


// square
template <typename T>
inline T Sqr(T a)
{
	return a*a;
}


// base 2 logarithm
template <typename T>
T Log2(T a)
{
	T log2 = (T)-1;
	while(a)
	{
		a >>= 1;
		log2++;
	}
	return log2;
}


// power of 2
template <typename T>
inline T Exp2(T a) 
{
	return 1 << a;
}


} // namespace math


#endif /* _MATH_BASIC_HPP_ */