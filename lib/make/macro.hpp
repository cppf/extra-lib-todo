#ifndef _MAKE_MACRO_HPP_
#define _MAKE_MACRO_HPP_


// required headers
#include "const.hpp"

#define	max2(a, b)		2
#define	max3(a, b, c)	3


#ifndef macro_Fn
// macro overloading support
#define	macro_Fn(x)	x
#define	macro_Fn1(_1, func, ...)	func
#define	macro_Fn2(_1, _2, func, ...)	func
#define	macro_Fn3(_1, _2, _3, func, ...)	func
#define	macro_Fn4(_1, _2, _3, _4, func, ...)	func
#define	macro_Fn5(_1, _2, _3, _4, _5, func, ...)	func
#define	macro_Fn6(_1, _2, _3, _4, _5, _6, func, ...)	func
#define	macro_Fn7(_1, _2, _3, _4, _5, _6, _7, func, ...)	func
#define	macro_Fn8(_1, _2, _3, _4, _5, _6, _7, _8, func, ...)	func
#define	macro_Fn9(_1, _2, _3, _4, _5, _6, _7, _8, _9, func, ...)	func
#define	macro_Fn10(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, func, ...)	func
#define	macro_Fn11(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, func, ...)	func
#define	macro_Fn12(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, func, ...)	func
#define	macro_Fn13(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, func, ...)	func
#define	macro_Fn14(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, func, ...)	func
#define	macro_Fn15(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, func, ...)	func
#define	macro_Fn16(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, func, ...)	func
#define	macro_Fn17(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, func, ...)	func
#define	macro_Fn18(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, func, ...)	func
#define	macro_Fn19(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, func, ...)	func
#define	macro_Fn20(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, func, ...)	func
#define	macro_Fn21(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, func, ...)	func
#define	macro_Fn22(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, func, ...)	func
#define	macro_Fn23(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, func, ...)	func
#define	macro_Fn24(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, func, ...)	func
#define	macro_FnE()
#define	macro_FnX(...)

// macro beginning and ending
// return only supported in GCC
#if COMPILER == GCC
#define	macro_Begin			({
#define	macro_End			})
#define macro_Return(var)	(var)
#else // COMPILER == VISUALCPP
#define	macro_Begin			do{
#define	macro_End			}while(0)
#endif // COMPILER == GCC
#endif // !macro_Fn


#endif /* _MAKE_MACRO_HPP_ */