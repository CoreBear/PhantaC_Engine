#pragma region Dependencies
// My Headers
#include "TestScene.h"			// Connection to declarations

#include "Cube.h"
#include "ObjectManager.h"
#include "PlayerManager.h"
#include "Pyramid.h"
#include "Sphere.h"
#include "Test.h"
#pragma endregion

#pragma region Initialization
TestScene::TestScene(ushort* clientDimensions) : SceneGraph(clientDimensions)
{
	// Examples------------------------------------------------------------------------------------	
	// When messing with these numbers, don't forget to go into the petition 
	// grid and mess with the number of cells for spatial partitioning
	short x, y, z;

	// This is 15625 objects - Runs alright in release, without the physics engine
	//for (x = -60; x < 61; x += 5)
	//	for (y = -60; y < 61; y += 5)
	//		for (z = -60; z < 61; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 4913 objects - Runs alright in release
	// for (x = -40; x < 41; x += 5)
	// 	for (y = -40; y < 41; y += 5)
	// 		for (z = -40; z < 41; z += 5)
	// 			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 3375 objects - Runs great in release
	//for (x = -35; x < 36; x += 5)
	//	for (y = -35; y < 36; y += 5)
	//		for (z = -35; z < 36; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 1000 objects - Runs great in release, not useable in debug
	for (x = -10; x < 36; x += 5)
		for (y = -10; y < 36; y += 5)
			for (z = -10; z < 36; z += 5)
				AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)), nullptr);


	// This is 729 objects - Runs well in release, not useable in debug
	//for (x = -10; x < 31; x += 5)
	//	for (y = -10; y < 31; y += 5)
	//		for (z = -10; z < 31; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 125 objects - Runs well in release and well enough in debug
	//for (x = -10; x < 11; x += 5)
	//	for (y = -10; y < 11; y += 5)
	//		for (z = -10; z < 11; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 64 objects - Runs well in both
	//for (x = -7; x < 9; x += 5)
	//	for (y = -7; y < 9; y += 5)
	//		for (z = -7; z < 9; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(x, y, z, 1)), nullptr);
	
	// This is just 1 object
	//AddObjectToScene(new ObjectManager(new Sphere(1, 1, 1), false, true, true, XMVectorSet(0, 0, 0, 1)), nullptr);
	//AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(5, 0, 0, 1)), nullptr);
	//AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), true, true, XMVectorSet(0, 0, 0, 1)), nullptr);

	// Adding scripts to objects - Make sure this number is within the range of cube numbers
	for (x = 2; x < 700; ++x)
	////	AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x)->object, 3));
	if (x % 7 == 0)
		AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x)->object, 3, 50));
	//AddScript(sceneObjects.at(2), new Test(sceneObjects.at(2)->object, 3, 50));

	// Add player script to camera scene object and and camera to player script
	AddScript(sceneObjects.at(0), new PlayerManager(sceneObjects.at(0)->object, 20, 50));

	// Assign scene's player (This is currently the player)
	playerPtr = (PlayerManager*)sceneObjects.at(0)->myScripts.at(0);

	//sceneObjects.at(2)->myScripts.at(0)->AssignTarget(sceneObjects.at(0)->object->GetTransform()->GetPosition());
	// Rescaling objects - Will resize from current size, not 1
	//GlobalTransform::Scale(.5f, .5f, .5f, sceneObjects.at(2)->object->GetColliderManager(), sceneObjects.at(2)->object->GetTransform()->GetLocalMatrix());
	// End Examples--------------------------------------------------------------------------------
}
#pragma endregion