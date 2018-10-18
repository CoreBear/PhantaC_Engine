#include "Pool.h"

template<typename Generic, ushort number>
void Pool<Generic, number>::Free(ushort index)
{
	tempAsset = pool[index];
	pool[index] = pool[--active_count];

	// Assigns and decrements
	pool[active_count] = tempAsset;
}
template<typename Generic, ushort number>
ushort Pool<Generic, number>::AllocateNew()
{
	for (iterator = 0; iterator < N; ++iterator)
	{
		if (iterator == active_count)
		{
			++active_count;
			return iterator;
		}
	}

	// If no inactive elements
	return -1;
}
template<typename Generic, ushort number>
Generic& Pool<Generic, number>::operator[](ushort index)
{
	return pool[index];
}
template<typename Generic, ushort number>
const Generic& Pool<Generic, number>::operator[](ushort index) const
{
	return pool[index];
}
template<typename Generic, ushort number>
ushort Pool<Generic, number>::Capacity() const
{
	return N;
}
template<typename Generic, ushort number>
ushort Pool<Generic, number>::GetSize() const
{
	return active_count;
}