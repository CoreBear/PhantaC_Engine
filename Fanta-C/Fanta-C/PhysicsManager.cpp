#pragma region Dependencies
// My Headers
#include "PhysicsManager.h"			// Connection to declarations
#include "Agent.h"
#pragma endregion

#pragma region Update
void PhysicsManager::Update(float deltaTime, std::vector<Agent*>* collidableObjects)
{
	// Check for collisions
	collisionManager.Update(collidableObjects);
}
#pragma endregion