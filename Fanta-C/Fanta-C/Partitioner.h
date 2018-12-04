#ifndef _PARTITIONER_H
#define _PARTITIONER_H

// System Headers
#include <vector>

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class SceneObject;

class Partitioner
{
	ushort iterators[2];

public:
	// Update
	void Update(std::vector<SceneObject*>* collidableObject, std::vector<class PartitionCell*>* gridCells);
};

#endif