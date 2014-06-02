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
 * support\constants.h - Wind configuration and support constants declaration file
 * This file is part of the Wind library for C++.
 */

#ifndef _SUPPORT_CONSTANTS_H_
#define _SUPPORT_CONSTANTS_H_


// TEXT_MODE
#define	ANSI		0x0000
#define	ASCII		ANSI
#ifndef UNICODE
#define	UNICODE		0x0001
#endif


// DEVICE
#define	PROCESSOR	0x0010
#define	CONTROLLER	0x0011


// ARCHITECTURE
#define	AVR			0x0020
#define	X86			0x0021
#define	X64			0x0022


// OS
#define	NO_OS		0x0030
#define	WINDOWS		0x0031


// COMPILER
#define	GCC			0x0040
#define	VISUAL_CPP	0x0041


// HEAP_MODE
#define	SINGLE_HEAP	0x0050
#define	MULTI_HEAP	0x0051


#endif /* _SUPPORT_CONSTANTS_H_ */