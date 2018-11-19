#pragma region Dependencies
// My Headers
#include "TestScene.h"			// Connection to declarations

#include "Cube.h"
#include "Grid.h"
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
	AddObjectToSceneAsParent(new ObjectManager(new Pyramid, false, true, true, XMVectorSet(-10, 0, 0, 1)), nullptr);
	AddObjectToSceneAsParent(new ObjectManager(new Grid, false, false, true), nullptr);
	AddObjectToSceneAsParent(new ObjectManager(new Cube, false, true, true), nullptr);
	
	// Creating non visible game objects
	//AddObjectToSceneAsParent(new ObjectManager(new Sphere, false, false, false, false), nullptr);
	//AddObjectToSceneAsParent(new ObjectManager(new Cube, false, false, false, false), nullptr);
	
	// Removing the grid
	//RemoveObjectFromScene(sceneObjects.at(2));
	
	// Adding a script to the object
	AddScript(sceneObjects.at(1), new Test(sceneObjects.at(1)->object));

	// Add player script to camera scene object and and camera to player script
	AddScript(sceneObjects.at(3), new PlayerManager(sceneObjects.at(3)->object));
	//AddScript(sceneObjects.at(0), new PlayerManager(sceneObjects.at(0)->object));

	// Assign scene's player (This is currently the player)
	playerPtr = (PlayerManager*)sceneObjects.at(3)->myScripts.at(0);
	//playerPtr = (PlayerManager*)sceneObjects.at(0)->myScripts.at(0);
	// End Examples--------------------------------------------------------------------------------
}
#pragma endregion