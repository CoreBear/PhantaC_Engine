#pragma region Dependencies
// My Headers
#include "PhysicsManager.h"			// Connection to declarations

#include "SceneObject.h"
#pragma endregion

#pragma region Forward Declarations
PhysicsManager* PhysicsManager::physicsManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
PhysicsManager* PhysicsManager::GetInstance(SceneObject * grid)
{
	// If instance has been created, return it
	if (physicsManagerInstance) return physicsManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		physicsManagerInstance = new PhysicsManager(grid);
		return physicsManagerInstance;
	}
}
#pragma endregion

#pragma region Update
void PhysicsManager::Update()
{
	collisionManager->Update();
}
#pragma endregion