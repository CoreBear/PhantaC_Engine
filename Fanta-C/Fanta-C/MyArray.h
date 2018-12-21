#ifndef _MY_ARRAY_H
#define _MY_ARRAY_H

// My Headers
#include "GlobalTypedefs.h"
#include "SceneObject.h"

template<typename Generic, ushort max> class MyArray
{
	// Variables
	Generic*	container;		// The actual container that will store values
	ushort		capacity;		// The number of spaces available
	ushort		iterator;
	ushort		size;			// Current count of values in container

public:
	// Initializaiton
	MyArray() : capacity(max), size(0) { container = new Generic[max]; }
	
	// CANNOT FIGURE OUT HOW TO CALL THIS CONSTRUCTOR
	//MyArray(bool pointerType) : capacity(max), size(0)
	//{
	//	container = new Generic[max];
	//
	//	// If type is a pointer
	//	if (pointerType)
	//	{
	//		// For each value, set to nullptr 
	//		for (iterator = 0; iterator < capacity; ++iterator)
	//			container[iterator] = nullptr;
	//	}
	//}

	// Public Interface
	void AddToBack(Generic value)
	{
		// Assign the next open position as the value and increment the counter
		container[size] = value;
		++size;
	}
	Generic At(ushort index) { return container[index]; }
	void Clear()
	{
		// Just acts like it is clear. Will over write information
		size = 0;
	}
	bool Contains(Generic value)
	{
		// For each value
		for (iterator = 0; iterator < size; ++iterator)
		{
			// If the value is found in container, container contains value
			if (container[iterator] == value)
				return true;
		}

		// Container doesn't contain value
		return false;
	}
	ushort GetCapacity() { return capacity; }
	ushort GetSize() { return size; }
	bool IsEmpty() { return (size > 0) ? false : true; }
	void Remove(Generic value)
	{
		// If the value is found in container, remove it
		if (Contains(value))
			RemoveAt(iterator);
	}
	void RemoveAt(ushort index)
	{
		// If not last value index, assign last value as the indexed value
		if (index != size - 1)
			container[index] = container[size - 1];

		// Update container size
		--size;
	}
	void SetAt(ushort index, Generic value) { container[index] = value; }

	// Clean Up
	~MyArray()
	{
		if (container)
		{
			delete container;
			container = nullptr;
		}
	}
};

#endif