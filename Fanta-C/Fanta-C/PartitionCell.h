#ifndef _PARTITION_CELL_H
#define _PARTITION_CELL_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalSceneVariables.h"
#include "GlobalTypedefs.h"
#include "MyArray.h"
#include "SceneObject.h"

// Forward Declarations
class SceneObject;

class PartitionCell
{
	// Variables
	float																	maxs[2];
	float																	mins[2];
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	objectsInsideOfMyContainer;
	ushort																	iterator;
	XMVECTOR																checkObjectsMinMax[2];		// Index 0 - Min. Index 1 - Max
	
public:	
	// Initialization
	PartitionCell() : maxs{ 0, 0 }, mins{ 0,0 } { return; }
	void DelayedInitialization(float minX, float minZ, float maxX, float maxZ);
	
	// Private Functionality
	void AddObject(SceneObject* inObject);
	bool IsObjectInsideOfMyArea(SceneObject* checkObject);
	bool IsObjectInsideOfMyContainer(SceneObject* checkObject);
	void RemoveObject(SceneObject* removedObject);
	void VerifyOrRemoveObjectsFromContainer();

	// Accessors
	float* GetMaxs() { return maxs; }
	float* GetMins() { return mins; }
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>* GetObjectsInsideOfMe() { return &objectsInsideOfMyContainer; }
};

#endif