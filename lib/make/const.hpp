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
 * const.hpp - constant declaration file
 */

#ifndef _MAKE_CONST_HPP_
#define _MAKE_CONST_HPP_


// CHAR_MODE
#ifndef ASCII
#define	ASCII		0x0000
#endif // !ASCII
#ifndef UNICODE
#define	UNICODE		0x0001
#endif // !UNICODE


// DEVICE
#ifndef PROCESSOR
#define	PROCESSOR	0x0010
#endif // !PROCESSOR
#ifndef CONTROLLER
#define	CONTROLLER	0x0011
#endif // !CONTROLLER


// ARCHITECTURE
#ifndef X86
#define	X86			0x0020
#endif // !X86
#ifndef X64
#define	X64			0x0021
#endif // !X64
#ifndef AVR
#define	AVR			0x0022
#endif // !AVR


// OS
#ifndef NONE
#define	NONE		0x0020
#endif // !AVR
#ifndef WINDOWS
#define	WINDOWS		0x0021
#endif // !WIN32


// COMPILER
#ifndef GCC
#define	GCC			0x0030
#endif // !GCC
#ifndef VISUALCPP
#define	VISUALCPP	0x0031
#endif // !VISUALCPP


#endif /* _MAKE_CONST_HPP_ */