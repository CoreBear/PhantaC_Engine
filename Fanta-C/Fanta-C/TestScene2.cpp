#pragma region Dependencies
// My Headers
#include "TestScene2.h"			// Connection to declarations

#include "Cube.h"
#include "Grid.h"
#include "Pyramid.h"
#include "Sphere.h"
#include "Test.h"
#pragma endregion

#pragma region Initialization
TestScene2::TestScene2(ushort* clientDimensions) : SceneGraph(clientDimensions)
{
	// Examples------------------------------------------------------------------------------------
	// Creating visible game objects
	AddObjectToSceneAsParent(new ObjectManager(new Sphere, false, false, true, true), nullptr);
	AddObjectToSceneAsParent(new ObjectManager(new Grid, false, false, true, true), nullptr);
	AddObjectToSceneAsParent(new ObjectManager(new Cube, false, false, true, true), nullptr);

	// Creating non visible game objects
	AddObjectToSceneAsParent(new ObjectManager(new Pyramid, false, false, false, true), nullptr);
	AddObjectToSceneAsParent(new ObjectManager(new Cube, false, false, false, true), nullptr);

	// Removing the grid
	//RemoveObjectFromScene(sceneObjects.at(2));

	// Adding a script to the object
	AddScript(sceneObjects.at(1), new Test(sceneObjects.at(1)->object));
	// End Examples--------------------------------------------------------------------------------
}
#pragma endregion