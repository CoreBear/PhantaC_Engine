#pragma region Dependencies
// My Headers
#include "SceneManager.h"		// Connection to declarations

#include "SceneGraph.h"
#include "TestScene.h"
#pragma endregion

#pragma region Forward Declarations
SceneManager* SceneManager::sceneManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
SceneManager::SceneManager(Application_Level::WindowCreator& window)
{		
	// Assign whatever scene you want to run
	scenePtr = new TestScene(true, window.GetClientDimensions());
}
#pragma endregion

#pragma region Update
void SceneManager::Update()
{	
	scenePtr->UpdateScripts();
}
#pragma endregion

#pragma region Accessors
SceneManager* SceneManager::GetInstance(Application_Level::WindowCreator& window)
{
	// If instance is already created, return it
	if (sceneManagerInstance) return sceneManagerInstance;

	// If instance is not created, create it and return it
	else
	{
		sceneManagerInstance = new SceneManager(window);
		return sceneManagerInstance;
	}
}
#pragma endregion

#pragma region Clean Up
SceneManager::~SceneManager()
{
	if (scenePtr) delete scenePtr;
}
#pragma endregion