#ifndef _PARTITION_CELL_H
#define _PARTITION_CELL_H

// System Headers
#include <vector>

// My Headers
#include "GlobalDirectX.h"
#include "GlobalTypedefs.h"

// Forward Declarations
class ObjectManager;

class PartitionCell
{
	float						dimensions[2];				// Index 0 - Cell width (x). Index 1 - Cell depth (z)
	std::vector<ObjectManager*>	objectsInsideOfMyContainer;
	ushort						iterator;
	XMVECTOR					checkObjectsMinMax[2];		// Index 0 - Min. Index 1 - Max
	XMVECTOR					myPosition;					// Y is probably wrong

public:
	// Initialization
	PartitionCell(float x, float y, float inWidth, float inDepth) : myPosition{ x, 0, y }, dimensions{ inWidth, inDepth } { return; }
	
	// Public Interface
	void AddObject(ObjectManager* inObject);
	bool IsObjectInsideOfMyArea(ObjectManager* checkObject);
	bool IsObjectInsideOfMyContainer(ObjectManager* checkObject);
	void RemoveObject(ObjectManager* removedObject);
	void VerifyOrRemoveObjectsFromContainer();

	// Accessors
	float* GetDimensions() { return dimensions; }
	std::vector<ObjectManager*>* GetObjectsInsideOfMe() { return &objectsInsideOfMyContainer; }
	XMVECTOR* GetMyPosition() { return &myPosition; }
};

#endif