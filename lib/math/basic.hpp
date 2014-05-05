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


// constants
#define	math_e				M_E
#define	math_log2e			M_LOG2E
#define	math_log10e			M_LOG10E
#define	math_ln2			M_LN2
#define	math_ln10			M_LN10
#define	math_pi				M_PI
#define	math_pi_by_2		M_PI_2
#define	math_pi_by_4		M_PI_4
#define	math_1_by_pi		M_1_PI
#define	math_2_by_pi		M_2_PI
#define	math_2_by_sqrt_pi	M_2_SQRTPI
#define	math_sqrt_2			M_SQRT2
#define	math_sqrt_1_by_2	M_SQRT1_2
#define	math_nan			NAN
#define	math_infinity		INFINITY
#define	math_inf			INFINITY


// functions
#define	math_Cos			cos
#define	math_Sin			sin
#define	math_Tan			tan
#define	math_Mod			fmod
#define	math_Sqrt			sqrt
#define	math_CubeRoot		cbrt
#define	math_Cbrt			cbrt
#define	math_Hypotenuse		hypot
#define	math_Hypot			hypot
#define	math_Floor			floor
#define	math_Ceil			ceil
#define	math_Exp			exp
#define	math_Cosh			cosh
#define	math_Sinh			sinh
#define	math_Tanh			tanh
#define	math_Acos			acos
#define	math_CosInv			acos
#define	math_Asin			asin
#define	math_SinInv			asin
#define	math_Atan			atan
#define	math_TanInv			atan
#define	math_Atan2			atan2
#define	math_TanInv2		atan2
#define	math_Log			log
#define	math_Log10			log10
#define	math_Pow			pow
#define	math_IsNan			isnan
#define	math_IsInf			isinf
#define	math_IsFinite		isfinite


// maximum of values
#define	math_Max2(val1, val2)	\
(((val1) > (val2))? (val1) : (val2))

#define	math_Max3(val1, val2, val3)	\
math_Max2(math_Max2(val1, val2), val3)

#define	math_Max4(val1, val2, val3, val4)	\
math_Max2(math_Max2(val1, val2), math_Max2(val3, val4))

#define	math_Max(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, math_Max4, math_Max3, math_Max2)(__VA_ARGS__))


// minimum of values
#define	math_Min2(val1, val2)	\
(((val1) < (val2))? (val1) : (val2))

#define	math_Min3(val1, val2, val3)	\
math_Min2(math_Min2(val1, val2), val3)

#define	math_Min4(val1, val2, val3, val4)	\
math_Min2(math_Min2(val1, val2), math_Min2(val3, val4))

#define	math_min(...)	\
macro_Fn(macro_Fn4(__VA_ARGS__, math_Min4, math_Min3, math_Min2)(__VA_ARGS__))


// absolute value
#define	math_Abs(val)	\
(((val) > 0)? (val) : -(val))


// value sign
#define	math_Sign(val)	\
(((val) >= 0)? (((val) > 0)? 1 : 0) : -1)


// square
#define	math_Sqr(val)	\
((val)*(val))


// base 2 logarithm
uword math_Log2(uint val);
uword math_Log2(uint val)
{
	uword log2 = (uword)-1;
	while(val)
	{
		val >>= 1;
		log2++;
	}
	return log2;
}


// power of 2
#define	math_Exp2(val)	\
(1 << (val))


#endif /* _MATH_BASIC_HPP_ */