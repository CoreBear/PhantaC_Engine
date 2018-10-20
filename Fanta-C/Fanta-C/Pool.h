#ifndef _POOLS_H
#define _POOLS_H

#include "ProgramGlobals.h"
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
		for (iterators[0] = 0; iterators[0] < number; ++iterators[0])
		{
			if (iterators[0] == currentCount)
			{
				++currentCount;
				return iterators[0];
			}
		}

		// If no inactive elements
		return -1;
	}
	Generic& operator[](ushort index) { return pool[index]; }
	const Generic& operator[](ushort index) const { return pool[index]; }
	
	// Accessors
	const ushort Capacity() const { return N; }
	const ushort GetSize() const { return currentCount; }
};

#endif