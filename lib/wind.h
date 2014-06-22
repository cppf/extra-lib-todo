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
 * wind.h - main include file
 */

#ifndef _WIND_H_
#define _WIND_H_


// required headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "support\constants.h"


// Wind configuration settings
#define	WORD_SIZE		32
#define	TEXT_MODE		ANSI
#define	HEAP_MODE		MULTI_HEAP
#define	COMPILER		VISUAL_CPP
#define	DEVICE			PROCESSOR
#define	ARCHITECTURE	X86
#define	OS				WINDOWS


// required headers
#if OS == WINDOWS
#include <Windows.h>
#endif


// make support
#include "support\keywords.h"
#include "support\attributes.h"
#include "support\macros.h"
#include "support\merge.h"


// types
#include "type\primitives.h"
#include "type\ranges.h"
#include "type\var_func.h"
#include "type\char_func.h"


// memory
#include "memory\heap_func.h"
#include "memory\block_func.h"
#include "memory\heap.h"
//#include "memory\buffer.h"
/*
// math
#include "math\basic.hpp"


// memory
#include "mem\basic.hpp"
#include "mem\heap.hpp"
#include "mem\address.hpp"
#include "mem\block.hpp"
*/


#endif /* _WIND_H_ */