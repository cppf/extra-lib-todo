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
 * reg.hpp - registers declaration file
 */

#ifndef _MEM_REGISTER_HPP_
#define _MEM_REGISTER_HPP_


// define register
#define	reg_Define8(addr)	\
(*((volatile uint8_t*)(addr)))

#define	reg_Define16(addr)	\
(*((volatile uint16_t*)(addr)))


// define IO
#define	reg_DefineIO8(addr)	\
reg_Define8((addr) + 0x20)

#define	reg_DefineIO16(addr)	\
reg_Define16((addr) + 0x20)


// R0-R31 registers
#ifndef R0
#define R0		reg_Define8(0x00)
#define R1		reg_Define8(0x01)
#define R2		reg_Define8(0x02)
#define R3		reg_Define8(0x03)
#define R4		reg_Define8(0x04)
#define R5		reg_Define8(0x05)
#define R6		reg_Define8(0x06)
#define R7		reg_Define8(0x07)
#define R8		reg_Define8(0x08)
#define R9		reg_Define8(0x09)
#define R10		reg_Define8(0x0A)
#define R11		reg_Define8(0x0B)
#define R12		reg_Define8(0x0C)
#define R13		reg_Define8(0x0D)
#define R14		reg_Define8(0x0E)
#define R15		reg_Define8(0x0F)
#define R16		reg_Define8(0x10)
#define R17		reg_Define8(0x11)
#define R18		reg_Define8(0x12)
#define R19		reg_Define8(0x13)
#define R20		reg_Define8(0x14)
#define R21		reg_Define8(0x15)
#define R22		reg_Define8(0x16)
#define R23		reg_Define8(0x17)
#define R24		reg_Define8(0x18)
#define R25		reg_Define8(0x19)
#define R26		reg_Define8(0x1A)
#define R27		reg_Define8(0x1B)
#define R28		reg_Define8(0x1C)
#define R29		reg_Define8(0x1D)
#define R30		reg_Define8(0x1E)
#define R31		reg_Define8(0x1F)
#endif


// X, Y, Z registers
#ifndef X
#define X		reg_Define16(0x1A)
#define Y		reg_Define16(0x1C)
#define Z		reg_Define16(0x1E)
#endif


// GPIO registers (0x00 - 0x1F)
#ifndef GPIO0
#define GPIO0		reg_DefineIO8(0x00)
#define GPIO1		reg_DefineIO8(0x01)
#define GPIO2		reg_DefineIO8(0x02)
#define GPIO3		reg_DefineIO8(0x03)
#define GPIO4		reg_DefineIO8(0x04)
#define GPIO5		reg_DefineIO8(0x05)
#define GPIO6		reg_DefineIO8(0x06)
#define GPIO7		reg_DefineIO8(0x07)
#define GPIO8		reg_DefineIO8(0x08)
#define GPIO9		reg_DefineIO8(0x09)
#define GPIO10		reg_DefineIO8(0x0A)
#define GPIO11		reg_DefineIO8(0x0B)
#define GPIO12		reg_DefineIO8(0x0C)
#define GPIO13		reg_DefineIO8(0x0D)
#define GPIO14		reg_DefineIO8(0x0E)
#define GPIO15		reg_DefineIO8(0x0F)
#define GPIO16		reg_DefineIO8(0x10)
#define GPIO17		reg_DefineIO8(0x11)
#define GPIO18		reg_DefineIO8(0x12)
#define GPIO19		reg_DefineIO8(0x13)
#define GPIO20		reg_DefineIO8(0x14)
#define GPIO21		reg_DefineIO8(0x15)
#define GPIO22		reg_DefineIO8(0x16)
#define GPIO23		reg_DefineIO8(0x17)
#define GPIO24		reg_DefineIO8(0x18)
#define GPIO25		reg_DefineIO8(0x19)
#define GPIO26		reg_DefineIO8(0x1A)
#define GPIO27		reg_DefineIO8(0x1B)
#define GPIO28		reg_DefineIO8(0x1C)
#define GPIO29		reg_DefineIO8(0x1D)
#define GPIO30		reg_DefineIO8(0x1E)
#define GPIO31		reg_DefineIO8(0x1F)
#endif


// status register
#ifndef SREG
#define SREG		reg_DefineIO8(0x3F)
#endif


// flags
#ifndef SREG_I
#define SREG_I		7
#define SREG_T		6
#define SREG_H		5
#define SREG_S		4
#define SREG_V		3
#define SREG_N		2
#define SREG_Z		1
#define SREG_C		0
#endif


// stack
#ifndef SP
#define SP		reg_DefineIO16(0x3D)
#endif
#ifndef SPL
#define SPL		reg_DefineIO8(0x3D)
#define SPH		reg_DefineIO8(0x3E)
#endif


#endif /* _MEM_REGISTER_HPP_ */