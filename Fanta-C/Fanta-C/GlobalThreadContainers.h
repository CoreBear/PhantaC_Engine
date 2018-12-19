#ifndef _GLOBAL_THREAD_CONTAINERS_H
#define _GLOBAL_THREAD_CONTAINERS_H

// My Headers
#include "GlobalDirectX.h"
#include "GlobalSceneVariables.h"
#include "GlobalTypedefs.h"
#include "Mesh.h"
#include "MyArray.h"
#include "SceneObject.h"

struct GlobalThreadContainers 
{
	struct UpdateObject 
	{
		Mesh*		myMesh;
		XMMATRIX*	myMatrix; 

		// Initialization
		UpdateObject(Mesh* inMesh, XMMATRIX* inMatrix) : myMesh(inMesh), myMatrix(inMatrix) { return; }
	};
	struct UpdateContainer { bool physicsRenderReady = false;  MyArray<UpdateObject*, GlobalSceneVariables::maxNumberOfSceneObjects> updateObjects; }; 
	const static uchar numberOfUpdatableContainers = 3; // Whatever amount keeps the physics engine fed
};
#endif