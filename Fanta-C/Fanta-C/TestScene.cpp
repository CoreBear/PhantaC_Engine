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

	char x, y, z;

	for (x = -5; x < 6; x += 5)
		for (y = -5; y < 6; y += 5)
			for (z = -5; z < 6; z += 5)
				AddObjectToScene(new ObjectManager(new Cube, false, true, true, XMVectorSet(x, y, z, 1)), nullptr);
	
	// Adding a script to the object
	// AddScript(sceneObjects.at(1), new Test(sceneObjects.at(1)->object));

	// Add player script to camera scene object and and camera to player script
	AddScript(sceneObjects.at(0), new PlayerManager(sceneObjects.at(0)->object));

	// Assign scene's player (This is currently the player)
	playerPtr = (PlayerManager*)sceneObjects.at(0)->myScripts.at(0);

	// Rescaling objects
	// GlobalTransform::Scale(5, 1, 1, sceneObjects.at(3)->object->GetCollider(), sceneObjects.at(3)->object->GetTransform()->GetWorldMatrix());
	// End Examples--------------------------------------------------------------------------------
}
#pragma endregion