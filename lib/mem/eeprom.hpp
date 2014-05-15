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
 * eeprom.hpp - EEPROM driver file
 */

#ifndef _MEM_EEPROM_HPP_
#define _MEM_EEPROM_HPP_


// required headers
#include "..\make\const.hpp"


#if ARCHITECTURE == AVR


namespace mem
{
using namespace data;

class eeprom
{
	struct task
	{
		void*	Dest;
		void*	Src;
		uint	Size;
	};
	
	private:
	queue<task, 16> Tasks;
	
	private:
	void _Isr()
	{
		_Handler();
	}
	
	void _Handler()
	{
		
	}
	
	public:
	void Read(void* dest, void* src, uint size)
	{
		// Check if queue is already full or not, if yes, block
		task tsk = {dest, src, size};
		Tasks.PushRear(tsk);
	}
	
	void Write(void* dest, void* src, uint size)
	{
		task tsk = {dest, src, size};
	}
};

} // end (namespace) mem


#endif
#endif /* _MEM_EEPROM_HPP_ */