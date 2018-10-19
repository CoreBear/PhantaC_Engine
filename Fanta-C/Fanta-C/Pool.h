#ifndef _POOLS_H
#define _POOLS_H

#include "Typedefs.h"

template<typename Generic, ushort number>
class Pool
{
	Generic pooledAssets[number];
	Generic tempAsset;
	ushort currentCount = 0;

public:
	void Free(ushort index)
	{
		tempAsset = pool[index];
		pool[index] = pool[--currentCount];

		// Assigns and decrements
		pool[currentCount] = tempAsset;
	}
	ushort AllocateNew()
	{
		for (iterator = 0; iterator < N; ++iterator)
		{
			if (iterator == currentCount)
			{
				++currentCount;
				return iterator;
			}
		}

		// If no inactive elements
		return -1;
	}
	Generic& operator[](ushort index)
	{
		return pool[index];
	}
	const Generic& operator[](ushort index) const
	{
		return pool[index];
	}
	
	// Accessors
	ushort Capacity() const
	{
		return N;
	}
	ushort GetSize() const
	{
		return currentCount;
	}
};

#endif