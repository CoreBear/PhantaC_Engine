#ifndef _PARTITIONER_H
#define _PARTITIONER_H

// My Headers
#include "GlobalSceneVariables.h"
#include "GlobalTypedefs.h"
#include "MyArray.h"

// Forward Declarations
class SceneObject;

class Partitioner
{
	// Variables
	static Partitioner*	partitionerInstance;
	ushort				iterators[2];

	// Initialization
	Partitioner() { return; }
	Partitioner(Partitioner const&) = delete;
	Partitioner operator=(Partitioner const&) = delete;

public:
	// Initialization
	static Partitioner* GetInstance();

	// Update
	void Update(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects, class PartitionGrid* grid);
};

#endif