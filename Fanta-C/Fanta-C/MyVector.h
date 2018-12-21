#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

// My Headers
#include "GlobalTypedefs.h"

template<typename Generic> class MyVector
{
	struct Node
	{
		Generic	value;
		Node*	nextNode;

		Node(Generic inValue) : value(inValue), nextNode(nullptr) { return; }
	};

	// Variables
	Node*		currentNode;
	Node*		headNode;	
	Node*		tailNode;
	ushort		iterator;
	ushort		size;			// Current count of objects in container

public:
	// Initialization
	MyVector() : currentNode(nullptr), headNode(nullptr), tailNode(nullptr)  { return; }

	// Public Interface
	void AddToBack(Generic value)
	{
		// Create new node
		currentNode = new Node(value);

		// If there is already a head/root node
		if (headNode)
		{
			// Add node to end and point tail node at new/last node
			tailNode->nextNode = currentNode;
			tailNode = currentNode;
		}

		// If there is no head/root node
		else
			headNode = tailNode = currentNode;

		// Increment size to reflect
		++size;
	}
	void Clear()
	{
		//currentNode = headNode;
		//Node* next = currentNode->nextNode;
		//
		//// While not at the end
		//while (currentNode != nullptr)
		//{
		//	delete currentNode;
		//	currentNode = nullptr;
		//	currentNode = next;
		//	next = next->nextNode;
		//}
		//
		//size = 0;
	}
	Generic At(ushort index) 
	{
		// Start at the beginning index
		iterator = 0;

		// Point to the head/root node
		currentNode = headNode;

		// Loop while not at the index
		while (iterator != index)
		{
			// Move pointer to next index and increment iterator
			currentNode = currentNode->nextNode;
			++iterator;
		}

		// Return the value at the index
		return currentNode->value;
	}
	ushort GetSize() { return size; }
	bool IsEmpty() { return (size > 0) ? false : true; }
};

#endif