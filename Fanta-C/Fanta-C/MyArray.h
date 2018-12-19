#ifndef _MY_ARRAY_H
#define _MY_ARRAY_H

// My Headers
#include "GlobalTypedefs.h"
#include "SceneObject.h"

template<typename Generic, ushort max> class MyArray
{
	// Variables
	Generic*	container;		// The actual container that will store objects
	ushort		capacity;		// The number of spaces available
	ushort		iterator;
	ushort		size;			// Current count of objects in container

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
	//		// For each object, set to nullptr 
	//		for (iterator = 0; iterator < capacity; ++iterator)
	//			container[iterator] = nullptr;
	//	}
	//}

	// Public Interface
	void AddToBack(Generic object)
	{
		// Assign the next open position as the object and increment the counter
		container[size] = object;
		++size;
	}
	Generic At(ushort index) { return container[index]; }
	bool CapacityContains(Generic object)
	{
		// For each object
		for (iterator = 0; iterator < capacity; ++iterator)
		{
			// If the object is found in container, container contains object
			if (container[iterator] == object)
				return true;
		}

		// Container doesn't contain object
		return false;
	}
	void Clear() 
	{
		// Just acts like it is clear. Will over write information
		size = 0; 
	}
	ushort GetCapacity() { return capacity; }
	ushort GetSize() { return size; }
	bool IsEmpty() { return (size > 0) ? false : true; }
	void Remove(Generic object)
	{
		// If the object is found in container, remove it
		if (SizeContains(object))
			RemoveAt(iterator);
	}
	void RemoveAt(ushort index)
	{
		// Assign the last object as the index and decrement the counter
		container[index] = container[size - 1];
		--size;
	}
	ushort ReturnIndex(Generic object)
	{
		// If the object is found in container, return its index
		if (CapacityContains(object))
			return iterator;

		// Return -1 if object is not in container (This will break code)
		return -1;
	}
	void SetAt(ushort index, Generic object) { container[index] = object; }
	bool SizeContains(Generic object)
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

	// Clean Up
	~MyArray() { if (container) delete container; }
};

#endif