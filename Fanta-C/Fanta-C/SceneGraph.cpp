#pragma region Dependencies
// My Headers
#include "SceneGraph.h"			// Connection to declarations

#include "AgentManager.h"
#include "Camera.h"
#include "Grid.h"
#include "Line.h"
#include "PlayerManager.h"
#include "Pooler.h"
#include "RayCast.h"
#include "SceneObject.h"
#include "ScriptManager.h"
#include "TestScene.h"
#pragma endregion

#pragma region Forward Declarations
// Pooler Variables
MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	Pooler::activeObjects;
MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	Pooler::sceneObjects;
MyArray<SceneObject*, GlobalSceneVariables::maxNumberOfSceneObjects>	Pooler::removeFromActive;

// Scene Graph Variables
ushort																	SceneGraph::numberOfObjectsInScene = 0;
#pragma endregion

#pragma region Initialization
SceneGraph::SceneGraph(bool useGrid, ushort* clientDimensions)
{
	#pragma region DO NOT TOUCH

	// Figure out how to do this in container
	{
		// For each object, set to nullptr 
		for (graphIterator = 0; graphIterator < Pooler::sceneObjects.GetCapacity(); ++graphIterator)
			Pooler::sceneObjects.SetAt(graphIterator, nullptr);
	}

	#pragma region Grid Creation
	// If grid is to be used
	if (useGrid)
	{
		// Create Grid
		gridPtr = new SceneObject(new Grid, true, false, true, true);
		CreateSceneObject(gridPtr);
	}
	#pragma endregion

	#pragma region Create Camera(Every scene needs a camera)	
	sceneCameraPtr = Camera::GetInstance(clientDimensions);
	#pragma endregion

	#pragma region Player Creation
	// Create player scene object, create player script, and attach script to object
	CreateSceneObject(new SceneObject(sceneCameraPtr));
	playerPtr = PlayerManager::GetInstance(sceneCameraPtr, Pooler::sceneObjects.At(numberOfObjectsInScene - 1), 150, 150, 20, 20);
	Pooler::sceneObjects.At(numberOfObjectsInScene - 1)->AddScript(playerPtr);
	#pragma endregion

	#pragma region Ray Cast Init
	// Tells ray cast where to start its checks
	RayCast::UpdateRayCastStartIndex(uchar(numberOfObjectsInScene));
	#pragma endregion

	#pragma endregion
}
#pragma endregion

#pragma region Update
void SceneGraph::UpdateScripts()
{
	// Update every object in the scene
	for (graphIterator = 0; graphIterator < Pooler::activeObjects.GetSize(); ++graphIterator)
	{
		if (Pooler::activeObjects.At(graphIterator)->GetLogical())
			Pooler::activeObjects.At(graphIterator)->Update();
	}
}
#pragma endregion

#pragma region Public Interface
void SceneGraph::ActivateObject(SceneObject* object) 
{
	if (object)
	{
		Pooler::activeObjects.AddToBack(object);
		++numberOfObjectsInScene;
	}
}
bool SceneGraph::CreateSceneObject(SceneObject* object)
{
	// If objects created is less than the max number of objects allowed
	if (Pooler::sceneObjects.GetSize() < GlobalSceneVariables::maxNumberOfSceneObjects)
	{
		// Add new object to scene objects
		Pooler::sceneObjects.AddToBack(object);

		// Add to applicable containers
		if (object->GetActive()) ActivateObject(object);

		// If object made it into the scene objects container
		return true;
	}

	// If object did not make it into the scene
	return false;
}
void SceneGraph::CleanScene()
{
	// If container is not empty
	if (!Pooler::removeFromActive.IsEmpty())
	{
		// For each object in scene removal container
		for (graphIterator = 0; graphIterator < Pooler::removeFromActive.GetSize(); ++graphIterator)
		{
			Pooler::removeFromActive.At(graphIterator)->SetActive(false);

			// Set logical to false and remove object from all of the containers
			Pooler::activeObjects.Remove(Pooler::removeFromActive.At(graphIterator));
		}

		// Clear the scene removal container for the next frame
		Pooler::removeFromActive.Clear();
	}
}
void SceneGraph::RemoveFromActive(SceneObject* object) 
{
	Pooler::removeFromActive.AddToBack(object); 
	--numberOfObjectsInScene;
}
#pragma endregion

#pragma region Clean Up
SceneGraph::~SceneGraph()
{
	// Delete camera
	if (sceneCameraPtr)
	{
		delete sceneCameraPtr;
		sceneCameraPtr = nullptr;
	}

	// Delete pooler
	Pooler::PoolerDestructor();
}
#pragma endregion
