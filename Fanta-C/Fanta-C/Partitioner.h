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
	static Partitioner*	partitionerInstance;
	ushort				iterators[2];

	Partitioner() { return; }
	Partitioner(Partitioner const&) = delete;
	Partitioner operator=(Partitioner const&) = delete;

public:
	// Update
	void Update(MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* collidableObjects, class PartitionGrid* grid);

	// Accessors
	static Partitioner* GetInstance();
};

#endif