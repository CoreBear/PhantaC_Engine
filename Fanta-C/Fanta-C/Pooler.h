#ifndef _POOLER_H
#define _POOLER_H

// My Headers
#include "GlobalSceneVariables.h"
#include "GlobalTypedefs.h"
#include "MyArray.h"

struct Pooler
{
	// Variables
	static MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects> activeObjects;
	static MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects> removeFromActive;
	static MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects> sceneObjects;													 
	static Pooler*																poolerInstance;
	static constexpr uchar														numberOfBulletsTrailsToPool = 10;
	static ushort																bulletTrailIndices[2];
	static ushort																iterator;

	// Clean Up
	static void PoolerDestructor();
};

#endif