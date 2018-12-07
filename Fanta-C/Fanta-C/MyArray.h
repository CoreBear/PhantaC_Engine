#ifndef _MY_ARRAY_H
#define _MY_ARRAY_H

// My Headers
#include "GlobalTypedefs.h"
#include "SceneObject.h"

template<typename Generic, ushort max> class MyArray
{
	Generic*	container;		// The actual container that will store objects
	ushort		capacity;		// The number of spaces available
	ushort		iterator;
	ushort		size;			// Current count of objects in container

public:
	// Initializaiton
	MyArray() : capacity(max), size(0) 
	{
		container = new Generic[max];

		// For each object, set to nullptr
		for (iterator = 0; iterator < capacity; ++iterator)
			container[iterator] = nullptr;
	}
	void AddToBack(Generic object)
	{
		// Assign the next open position as the object and increment the counter
		container[size] = object;
		++size;
	}
	Generic At(ushort index) { return container[index]; }
	void Clear() 
	{
		// Just acts like it is clear. Will over write information
		size = 0; 
	}
	bool Contains(Generic object)
	{
		// For each object
		for (iterator = 0; iterator < size; ++iterator)
		{
			// If the object is found in container, container contains object
			if (container[iterator] == object)
				return true;
		}

		// Container doesn't contain object
		return false;
	}
	ushort GetCapacity() { return capacity; }
	ushort GetSize() { return size; }
	bool IsEmpty() { return (size > 0) ? false : true; }
	void Remove(Generic object)
	{
		// If the object is found in container, remove it
		if (Contains(object))
			RemoveAt(iterator);
	}
	void RemoveAt(ushort index)
	{
		// Assign the last object as the index and decrement the counter
		container[index] = container[size - 1];
		--size;
	}
	~MyArray() { if (container) delete container; }
};

#endif