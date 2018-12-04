#pragma region Dependencies
// My Headers
#include "PhysicsManager.h"			// Connection to declarations

#include "SceneObject.h"
#pragma endregion

#pragma region Update
void PhysicsManager::Update(std::vector<SceneObject*>* collidableObjects)
{
	collisionManager->Update(collidableObjects);
}
#pragma endregion