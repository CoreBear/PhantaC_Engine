#ifndef _POOLER_H
#define _POOLER_H

// My Headers
#include "GlobalSceneVariables.h"
#include "GlobalTypedefs.h"
#include "MyArray.h"

class Pooler
{
	// Variables
	static Pooler*			poolerInstance;
	constexpr static uchar	numberOfProjectilesToPool = 10;
	ushort					iterator;

	// Private Functionality
	Pooler() { return; }
	Pooler(Pooler const&) = delete;
	Pooler operator=(Pooler const&) = delete;

public:
	// Variables (Public for now)
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	collidableObjects;
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	removableObjects;
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	renderableObjects;
	MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	sceneObjects;
	MyArray<SceneObject*, numberOfProjectilesToPool>						bulletTrailPool;

	// Initialization
	static Pooler* GetInstance();

	// Public Interface
	SceneObject* SpawnBulletTrail(XMVECTOR* startPosition, XMVECTOR* endPosition);

	// Clean Up
	~Pooler();
};

#endif