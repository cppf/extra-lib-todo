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
 * wind.hpp - main include file
 */

#ifndef _WIND_HPP_
#define _WIND_HPP_


// required headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// make constants
#include "make\const.hpp"


// make properties
#define	WORD_SIZE		64
#define	CHAR_MODE		ASCII
#define	COMPILER		VISUALCPP
#define	DEVICE			PROCESSOR
#define	ARCHITECTURE	X64
#define	OS				WINDOWS


// required headers
#if OS == WINDOWS
#include <Windows.h>
#endif // OS == WINDOWS


// make support
#include "make\attrib.hpp"
#include "make\func.hpp"
#include "make\macro.hpp"
#include "make\merge.hpp"


// types
#include "type\basic.hpp"
#include "type\char.hpp"
#include "type\range.hpp"
#include "type\string.hpp"


// math
#include "math\basic.hpp"


// memory
#include "mem\basic.hpp"
#include "mem\block.hpp"


#endif /* _WIND_HPP_ */