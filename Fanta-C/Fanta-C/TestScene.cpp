#pragma region Dependencies
// My Headers
#include "TestScene.h"			// Connection to declarations

#include "Cube.h"
#include "ObjectManager.h"
#include "Pyramid.h"
#include "SceneObject.h"
#include "ScriptManager.h"
#include "Sphere.h"
#include "Test.h"
#pragma endregion

#pragma region Initialization
TestScene::TestScene(ushort* clientDimensions) : SceneGraph(clientDimensions)
{
	short x, y, z;
	// When messing with the numbers in this script, don't forget to go into the petition grid and mess with the number of cells for spatial partitioning

	// This is 15625 objects - Runs alright in release, without the physics engine
	//for (x = -60; x < 61; x += 5)
	//	for (y = -60; y < 61; y += 5)
	//		for (z = -60; z < 61; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 8000; x < 15600; ++x)
	//	AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x), 3, 50));

	// This is 4913 objects - Runs alright in release
	// for (x = -40; x < 41; x += 5)
	// 	for (y = -40; y < 41; y += 5)
	// 		for (z = -40; z < 41; z += 5)
	// 			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 2000; x < 4900; ++x)
	//	AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x), 3, 50));

	// This is 3375 objects - Runs great in release
	for (x = -35; x < 36; x += 5)
		for (y = -35; y < 36; y += 5)
			for (z = -35; z < 36; z += 5)
				AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	
	// Adding scripts to objects - Make sure this number is within the range of cube numbers
	for (x = 1500; x < 3300; ++x)
	{
		AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x), 3, 50));
		sceneObjects.at(x)->GetMyScripts()->at(0)->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);
	}

	// This is 1000 objects - Runs great in release, not useable in debug
	//for (x = -10; x < 36; x += 5)
	//	for (y = -10; y < 36; y += 5)
	//		for (z = -10; z < 36; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	//
	//// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 500; x < 1000; ++x)
	//	AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x), 3, 50));
	
	// This is 729 objects - Runs well in release, not useable in debug
	//for (x = -10; x < 31; x += 5)
	//	for (y = -10; y < 31; y += 5)
	//		for (z = -10; z < 31; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	//
	//// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 300; x < 729; ++x)
	//	AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x), 3, 50));

	// This is 125 objects - Runs well in release and well enough in debug
	//for (x = -10; x < 11; x += 5)
	//	for (y = -10; y < 11; y += 5)
	//		for (z = -10; z < 11; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));
	//
	//// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 50; x < 120; ++x)
	//{
	//	AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x), 3, 50));
	//	sceneObjects.at(x)->GetMyScripts()->at(0)->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);
	//}

	// This is 64 objects - Runs well in both
	//for (x = -7; x < 9; x += 5)
	//	for (y = -7; y < 9; y += 5)
	//		for (z = -7; z < 9; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)));

	// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 30; x < 64; ++x)
	//	AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x), 3, 50));
	
	// This is just 1 object
	AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(5, 0, 0, 1)));
	AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(2.5f, 0, 0, 1)));
	//AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(7.25f, 0, 0, 1)));
	//AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(5, 0, 2.25f, 1)));
	//AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(5, 0, -2.25f, 1)));

	AddScript(sceneObjects.at(1), new Test(sceneObjects.at(1), 3, 0.5f));
	
	// Example of assigning targets for lookAt and turnTowards
	sceneObjects.at(1)->GetMyScripts()->at(0)->AssignTarget(&sceneCameraPtr->GetViewMatrix()->r[3]);
	
	// Rescaling objects - Will resize from current size, not 1
	//GlobalTransform::Scale(.5f, .5f, .5f, sceneObjects.at(2)->object->GetColliderManager(), sceneObjects.at(2)->object->GetTransform()->GetLocalMatrix());
}
#pragma endregion