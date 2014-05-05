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
 * char.hpp - character macros
 */

#ifndef _TYPE_CHAR_HPP_
#define _TYPE_CHAR_HPP_


#define	char_IsLower(ch)	\
(((ch) >= 'a') && ((ch) <= 'z'))

#define	char_IsUpper(ch)	\
(((ch) >= 'A') && ((ch) <= 'Z'))

#define	char_IsAlphabet(ch)		\
(char_IsUpper(ch) || char_IsLower(ch))

#define	char_IsDigit(ch)	\
(((ch) >= '0') && ((ch) <= '9'))

#define	char_IsAlphabetOrDigit(ch)	\
(char_IsAlphabet(ch) || char_IsDigit(ch))

#define	char_IsBlank(ch)	\
(((ch) == '\t') || ((ch) == ' '))

#define	char_IsSpace	char_IsBlank

#define	char_IsControl(ch)	\
((byte)(ch) <= (byte)31)

#define	char_IsGraphical(ch)	\
((byte)(ch) >= (byte)128)

#define	char_ToLower(ch)	\
((char_IsUpper(ch))? (ch - 'A' + 'a') : (ch))

#define	char_ToUpper(ch)	\
((char_IsLower(ch))? (ch - 'a' + 'A') : (ch))


#endif /* _TYPE_CHAR_HPP_ */