#pragma region Dependencies
// My Headers
#include "TestScene2.h"			// Connection to declarations

#include "Cube.h"
#include "Grid.h"
#include "ObjectManager.h"
#include "PlayerManager.h"
#include "Pyramid.h"
#include "Sphere.h"
#include "Test.h"
#pragma endregion

#pragma region Initialization
TestScene2::TestScene2(ushort* clientDimensions) : SceneGraph(clientDimensions)
{
	// Examples------------------------------------------------------------------------------------		
	// Creating visible game objects
	AddObjectToScene(new ObjectManager(new Grid, false, false, true), nullptr);
	AddObjectToScene(new ObjectManager(new Pyramid, false, true, true, XMVectorSet(-10, 0, 10, 1)), nullptr);
	AddObjectToScene(new ObjectManager(new Pyramid, false, true, true, XMVectorSet(-12, 0, 0, 1)), nullptr);
	AddObjectToScene(new ObjectManager(new Pyramid, false, true, true, XMVectorSet(-15, 0, -10, 1)), nullptr);
	
	short x, y;
	for (x = -10; x < 11; x += 5)
		for (y = -10; y < 11; y += 5)
			AddObjectToScene(new ObjectManager(new Cube, false, true, true, XMVectorSet(x, 0, y, 1)), nullptr);
	
	AddScript(sceneObjects.at(2), new Test(sceneObjects.at(2)->object));
	AddScript(sceneObjects.at(3), new Test(sceneObjects.at(3)->object));
	AddScript(sceneObjects.at(4), new Test(sceneObjects.at(4)->object));
	GlobalTransform::Scale(1, 2, 1, sceneObjects.at(2)->object->GetCollider(), sceneObjects.at(2)->object->GetTransform()->GetWorldMatrix());

	// Add player script to camera scene object and and camera to player script
	//AddScript(sceneObjects.at(3), new PlayerManager(sceneObjects.at(3)->object));
	AddScript(sceneObjects.at(0), new PlayerManager(sceneObjects.at(0)->object));

	// Assign scene's player (This is currently the player)
	//playerPtr = (PlayerManager*)sceneObjects.at(3)->myScripts.at(0);
	playerPtr = (PlayerManager*)sceneObjects.at(0)->myScripts.at(0);
	// End Examples--------------------------------------------------------------------------------
}
#pragma endregion