#pragma region Dependencies
// My Headers
#include "TestScene.h"			// Connection to declarations

#include "AgentManager.h"
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

	// This is 1000 objects - Runs well in release
	//for (x = -10; x < 36; x += 5)
	//	for (y = -10; y < 36; y += 5)
	//		for (z = -10; z < 36; z += 5)
	//			AddObjectToScene(new SceneObject(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	//
	//// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 500; x < 1000; ++x)
	//{
	//	AddScript(*sceneObjects.At(x), new AgentManager(*sceneObjects.At(x), 3, 50));
	//	static_cast<AgentManager*>(static_cast<SceneObject*>(*sceneObjects.At(x))->GetMyScripts()->at(0))->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);	// Assign target
	//}
	
	// This is 729 objects - Runs well in release
	//for (x = -10; x < 31; x += 5)
	//	for (y = -10; y < 31; y += 5)
	//		for (z = -10; z < 31; z += 5)
	//			AddObjectToScene(new SceneObject(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	//
	//// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 300; x < 729; ++x)
	//{
	//	AddScript(*sceneObjects.At(x), new AgentManager(*sceneObjects.At(x), 3, 50));
	//	static_cast<AgentManager*>(static_cast<SceneObject*>(*sceneObjects.At(x))->GetMyScripts()->at(0))->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);	// Assign target
	//}

	// This is 512 objects - Runs well in both
	for (x = -20; x < 16; x += 5)
		for (y = -20; y < 16; y += 5)
			for (z = -20; z < 16; z += 5)
				AddObjectToScene(new SceneObject(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	
	// Adding scripts to objects - Make sure this number is within the range of cube numbers
	for (x = 250; x < 512; ++x)
	{
		AddScript(sceneObjects.At(x), new AgentManager(sceneObjects.At(x), 3, 50));
		static_cast<AgentManager*>(static_cast<SceneObject*>(sceneObjects.At(x))->GetMyScripts()->at(0))->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);	// Assign target
	}

	//// This is 125 objects - Runs well in both
	//for (x = -10; x < 11; x += 5)
	//	for (y = -10; y < 11; y += 5)
	//		for (z = -10; z < 11; z += 5)
	//			AddObjectToScene(new SceneObject(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	//
	//// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 50; x < 120; ++x)
	//{
	//	AddScript(*sceneObjects.At(x), new AgentManager(*sceneObjects.At(x), 3, 50));
	//	static_cast<AgentManager*>(static_cast<SceneObject*>(*sceneObjects.At(x))->GetMyScripts()->at(0))->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);	// Assign target
	//}

	// This is 64 objects - Runs well in both
	//for (x = -7; x < 9; x += 5)
	//	for (y = -7; y < 9; y += 5)
	//		for (z = -7; z < 9; z += 5)
	//			AddObjectToScene(new SceneObject(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	//
	//// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 30; x < 64; ++x)
	//{
	//	AddScript(*sceneObjects.At(x), new AgentManager(*sceneObjects.At(x), 3, 50));
	//	static_cast<AgentManager*>(static_cast<SceneObject*>(*sceneObjects.At(x))->GetMyScripts()->at(0))->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);	// Assign target
	//}

	// This is just 1 object
	//AddObjectToScene(new SceneObject(new Cube(1, 1, 1), true, true, XMVectorSet(5, 0, 0, 1)));																	// Create object
	//AddScript(*sceneObjects.At(1), new AgentManager(*sceneObjects.At(1), 3, 0.5f));																			// Add script
	//static_cast<AgentManager*>(static_cast<SceneObject*>(*sceneObjects.At(1))->GetMyScripts()->at(0))->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);	// Assign target
	//AddObjectToScene(new SceneObject(new Cube(1, 1, 1), true, true, XMVectorSet(7, 0, 0, 1)));																	// Create object
	//AddScript(*sceneObjects.At(2), new AgentManager(*sceneObjects.At(2), 3, 0.5f));																			// Add script
	//static_cast<AgentManager*>(static_cast<SceneObject*>(*sceneObjects.At(2))->GetMyScripts()->at(0))->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);	// Assign target
}
#pragma endregion