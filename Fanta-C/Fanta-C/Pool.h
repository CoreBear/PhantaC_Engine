#ifndef _POOLS_H
#define _POOLS_H

#include "GlobalApplication.h"
#include "GlobalTypedefs.h"

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

		// Assigns and decrements (places asset in unreachable position. i.e. the count)
		pool[currentCount] = tempAsset;
	}
	ushort AllocateNew()
	{
		// If the current number of assets in container is less than the last available index
		if (currentCount < number - 1)
		{
			iterators[0] = currentCount++;
			return iterators[0];
		}

		// If no inactive elements
		return -1;
	}
	Generic& operator[](ushort index) { return pooledAssets[index]; }
	const Generic& operator[](ushort index) const { return pooledAssets[index]; }
	
	// Accessors
	const ushort Capacity() const { return number; }
	const ushort GetSize() const { return currentCount; }
};

#endif