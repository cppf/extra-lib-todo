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
 * queue.hpp - generic queue
 */

#ifndef _DATA_QUEUE_HPP_
#define _DATA_QUEUE_HPP_


// required headers
#include "..\type\basic.hpp"


// generic queue definition
template <typename T, uword size>
class queue
{
public:
	uword	Count;
	uword	Front;
	uword	Size;
	uword	Max;
	T		Item[size];
	
public:
	inline void Init()
	{
		Size = size;
		Max = size - 1;
		Count = Front = 0;
	}
	inline uword Rear()
	{
		return (Front + Count) & Max;
	}
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return Size - Count;
	}
	inline uword Index(uword pos)
	{
		return (Front + pos) & Max;
	}
	inline uword Pos(uword indx)
	{
		return (indx - Front) & Max;
	}
	inline void Clear()
	{
		Count = Front = 0;
	}
	void PushFront(T item)
	{
		Count++;
		Front = (Front - 1) & Max;
		Item[Front] = item;
	}
	void PushRear(T item)
	{
		Item[Rear()] = item;
		Count++;
	}
	T PopFront()
	{
		Count--;
		T item = Item[Front];
		Front = (Front + 1) & Max;
		return item;
	}
	T PopRear()
	{
		Count--;
		return Item[Rear()];
	}
	uword IndexOf(T item)
	{
		for(uword i=Front, n=Count; n>0; n--)
		{
			if(Item[i] == item) return i;
			i = (i + 1) & Max;
		}
		return (uword) -1;
	}
	void InsertAt(uword indx, T item)
	{
		PushFront(Item[indx]);
		Item[indx] = item;
	}
	void DeleteAt(uword indx)
	{
		Item[indx] = Item[Front];
		PopFront();
	}
	void Remove(T item)
	{
		uword indx = IndexOf(item);
		if(indx != (uword) -1) DeleteAt(indx);
	}
};


typedef queue<uint8, 8> queue8_uint8;
typedef queue<uint16, 8> queue8_uint16;


// 8-bit queue definition
template <typename T, uword size>
class queue8
{
	public:
	uword	Count;
	uword	Front;
	uword	Size;
	uword	Max;
	T		Item[size];
	
	public:
	inline void Init()
	{
		Size = size;
		Max = size - 1;
		Count = Front = 0;
	}
	inline uword Rear()
	{
		return (Front + Count) & Max;
	}
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return Size - Count;
	}
	inline uword Index(uword pos)
	{
		return (Front + pos) & Max;
	}
	inline uword Pos(uword indx)
	{
		return (indx - Front) & Max;
	}
	inline void Clear()
	{
		Count = Front = 0;
	}
	inline void PushFront(T item)
	{
		((queue8_uint8*)this)->PushFront((uint8)item);
	}
	inline void PushRear(T item)
	{
		((queue8_uint8*)this)->PushRear((uint8)item);
	}
	inline T PopFront()
	{
		return (T) ((queue8_uint8*)this)->PopFront();
	}
	inline T PopRear()
	{
		return (T) ((queue8_uint8*)this)->PopRear();
	}
	inline uword IndexOf(T item)
	{
		return ((queue8_uint8*)this)->IndexOf((uint8)item);
	}
	inline void InsertAt(uword indx, T item)
	{
		((queue8_uint8*)this)->InsertAt(indx, (uint8)item);
	}
	inline void DeleteAt(uword indx)
	{
		((queue8_uint8*)this)->DeleteAt(indx);
	}
	inline void Remove(T item)
	{
		((queue8_uint8*)this)->Remove((uint8)item);
	}
};


// 16-bit queue definition
template <typename T, uword size>
class queue16
{
	public:
	uword	Count;
	uword	Front;
	uword	Size;
	uword	Max;
	T		Item[size];
	
	public:
	inline void Init()
	{
		Size = size;
		Max = size - 1;
		Count = Front = 0;
	}
	inline uword Rear()
	{
		return (Front + Count) & Max;
	}
	inline uword Avail()
	{
		return Count;
	}
	inline uword Free()
	{
		return Size - Count;
	}
	inline uword Index(uword pos)
	{
		return (Front + pos) & Max;
	}
	inline uword Pos(uword indx)
	{
		return (indx - Front) & Max;
	}
	inline void Clear()
	{
		Count = Front = 0;
	}
	inline void PushFront(T item)
	{
		((queue8_uint16*)this)->PushFront((uint16)item);
	}
	inline void PushRear(T item)
	{
		((queue8_uint16*)this)->PushRear((uint16)item);
	}
	inline T PopFront()
	{
		return (T) ((queue8_uint16*)this)->PopFront();
	}
	inline T PopRear()
	{
		return (T) ((queue8_uint16*)this)->PopRear();
	}
	inline uword IndexOf(T item)
	{
		return ((queue8_uint16*)this)->IndexOf((uint16)item);
	}
	inline void InsertAt(uword indx, T item)
	{
		((queue8_uint16*)this)->InsertAt(indx, (uint16)item);
	}
	inline void DeleteAt(uword indx)
	{
		((queue8_uint16*)this)->DeleteAt(indx);
	}
	inline void Remove(T item)
	{
		((queue8_uint16*)this)->Remove((uint16)item);
	}
};


#endif /* _DATA_QUEUE_HPP_ */