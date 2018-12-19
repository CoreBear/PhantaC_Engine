#pragma region Dependencies
// My Headers
#include "TestScene.h"			// Connection to declarations

#include "AgentManager.h"
#include "BulletTrail.h"
#include "Line.h"
#include "Cube.h"
#include "Pyramid.h"
#include "SceneObject.h"
#include "ScriptManager.h"
#include "Sphere.h"
#pragma endregion

#pragma region Initialization
TestScene::TestScene(ushort* clientDimensions) : SceneGraph(clientDimensions)
{
	short x, y, z;
	
	// This is 125 objects - Runs well in both
	for (x = -10; x < 11; x += 5)
		for (y = -10; y < 11; y += 5)
			for (z = -10; z < 11; z += 5)
				AddObjectToScene(new SceneObject(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	
	// Adding scripts to objects - Make sure this number is within the range of cube numbers
	for (x = 1; x < 126; ++x)
	{
		// Will not over more scripts than what's allowable
		if (x < GlobalSceneVariables::maxNumberOfSceneObjects)
		{
			poolerInstance->sceneObjects.At(x)->AddScript(new AgentManager(this, poolerInstance->sceneObjects.At(x), 1, 1, 10, 1));
			static_cast<AgentManager*>(poolerInstance->sceneObjects.At(x)->GetMyScripts()->at(0))->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);	// Assign target
		}
	}

	// Add one object
	//AddObjectToScene(new SceneObject(new Cube(1, 1, 1), true, true));
	//poolerInstance->sceneObjects.At(1)->AddScript(new AgentManager(this, poolerInstance->sceneObjects.At(1), 1, 1, 10, 1));
	//static_cast<AgentManager*>(poolerInstance->sceneObjects.At(1)->GetMyScripts()->at(0))->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);	// Assign target
	
	#pragma region DONT TOUCH!!! (BULLET TRAILS)
	// For each index in pool
	for (graphIterator[0] = 0; graphIterator[0] < poolerInstance->bulletTrailPool.GetCapacity(); ++graphIterator[0])
	{
		// Create a new line sceneobject and add the bulletTrail script to it
		poolerInstance->bulletTrailPool.AddToBack(new SceneObject(new Line, false, true));
		poolerInstance->bulletTrailPool.At(graphIterator[0])->AddScript(new BulletTrail(this, poolerInstance->bulletTrailPool.At(graphIterator[0])));
	}
	#pragma endregion
}
#pragma endregion