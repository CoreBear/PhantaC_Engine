#pragma region Dependencies
// My Headers
#include "PhysicsManager.h"			// Connection to declarations

#include "ObjectManager.h"
#pragma endregion

#pragma region Update
void PhysicsManager::Update(std::vector<ObjectManager*>* collidableObjects)
{
	collisionManager.Update(collidableObjects);
}
#pragma endregion