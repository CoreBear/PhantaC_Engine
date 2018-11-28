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

	// This is 27 cubes
	//for (x = -5; x < 6; x += 5)
	//	for (y = -5; y < 6; y += 5)
	//		for (z = -5; z < 6; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube, false, true, true, XMVectorSet(x, y, z, 1)), nullptr);
	
	// Adding a script to object
	//AddScript(sceneObjects.at(5), new Test(sceneObjects.at(5)->object));

	// This is 216 cubes - Runs well in release, but not in debug
	//for (x = -10; x < 16; x += 5)
	//	for (y = -10; y < 16; y += 5)
	//		for (z = -10; z < 16; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube, false, true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 125 cubes - Runs well in release and well enough in debug
	//for (x = -10; x < 11; x += 5)
	//	for (y = -10; y < 11; y += 5)
	//		for (z = -10; z < 11; z += 5)
	//			AddObjectToScene(new ObjectManager(new Cube, false, true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// This is 64 cubes - Runs well in both
	for (x = -7; x < 9; x += 5)
		for (y = -7; y < 9; y += 5)
			for (z = -7; z < 9; z += 5)
				AddObjectToScene(new ObjectManager(new Cube, false, true, true, XMVectorSet(x, y, z, 1)), nullptr);

	// Adding scripts to objects - Make sure this number is within the range of cube numbers
	for (x = 2; x < 60; x += 2)
		AddScript(sceneObjects.at(x), new Test(sceneObjects.at(x)->object));

	// Add player script to camera scene object and and camera to player script
	AddScript(sceneObjects.at(0), new PlayerManager(sceneObjects.at(0)->object));

	// Assign scene's player (This is currently the player)
	playerPtr = (PlayerManager*)sceneObjects.at(0)->myScripts.at(0);

	// Rescaling objects
	// GlobalTransform::Scale(5, 1, 1, sceneObjects.at(3)->object->GetColliderManager(), sceneObjects.at(3)->object->GetTransform()->GetWorldMatrix());
	// End Examples--------------------------------------------------------------------------------
}
#pragma endregion