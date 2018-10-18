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
	void Free(ushort index);
	ushort AllocateNew();
	Generic& operator[](ushort index);
	const Generic& operator[](ushort index) const;
	
	// Accessors
	ushort Capacity() const;
	ushort GetSize() const;
};

#endif