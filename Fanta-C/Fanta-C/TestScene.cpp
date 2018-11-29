#pragma region Dependencies
// My Headers
#include "TestScene.h"			// Connection to declarations

#include "Cube.h"
#include "Grid.h"
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
	// Creating visible game objects
	AddObjectToScene(new ObjectManager(new Grid, false, false, true), nullptr);

	short x, y, z;

	// This is 1000 objects - Runs alright in release, not useable in debug
	//for (x = -10; x < 36; x += 5)
	//	for (y = -10; y < 36; y += 5)
	//		for (z = -10; z < 36; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), false, true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 729 objects - Runs well in release, not useable in debug
	//for (x = -10; x < 31; x += 5)
	//	for (y = -10; y < 31; y += 5)
	//		for (z = -10; z < 31; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), false, true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 125 objects - Runs well in release and well enough in debug
	//for (x = -10; x < 11; x += 5)
	//	for (y = -10; y < 11; y += 5)
	//		for (z = -10; z < 11; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), false, true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 64 objects - Runs well in both
	//for (x = -7; x < 9; x += 5)
	//	for (y = -7; y < 9; y += 5)
	//		for (z = -7; z < 9; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), false, true, true, XMVectorSet(x, y, z, 1)), nullptr);
	
	// This is just 1 object
	//AddObjectToScene(new ObjectManager(new Sphere(1, 1, 1), false, true, true, XMVectorSet(0, 0, 0, 1)), nullptr);
	AddObjectToScene(new ObjectManager(new Cube(1, 1, 1), false, true, true, XMVectorSet(0, 0, 0, 1)), nullptr);

	// Adding scripts to objects - Make sure this number is within the range of cube numbers
	//for (x = 2; x < 40; x += 2)
	//	AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x)->object, 3));
	AddScript(sceneObjects.at(2), new Test(sceneObjects.at(2)->object, 3, .5f));

	// Add player script to camera scene object and and camera to player script
	AddScript(sceneObjects.at(0), new PlayerManager(sceneObjects.at(0)->object, 20, 5));

	// Assign scene's player (This is currently the player)
	playerPtr = (PlayerManager*)sceneObjects.at(0)->myScripts.at(0);

	sceneObjects.at(2)->myScripts.at(0)->AssignTarget(sceneObjects.at(0)->object->GetTransform()->GetPosition());
	// Rescaling objects - Will resize from current size, not 1
	//GlobalTransform::Scale(.5f, .5f, .5f, sceneObjects.at(2)->object->GetColliderManager(), sceneObjects.at(2)->object->GetTransform()->GetWorldMatrix());
	// End Examples--------------------------------------------------------------------------------
}
#pragma endregion