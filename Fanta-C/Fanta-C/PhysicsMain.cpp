#pragma region Dependencies
// My Headers
#include "PhysicsMain.h"			// Connection to declarations
#include "AutonomousAgent.h"
#include "ObjectTransform.h"
#include "GlobalApplication.h"
#pragma endregion

#pragma region Update
void PhysicsMain::Update(float deltaTime, std::vector<Agent*>* agents)
{
	// Run agent actions
	/*for (iterators[0] = 0; iterators[0] < agents->size(); ++iterators[0])
		static_cast<AutonomousAgent*>(agents->at(iterators[0]))->Action(deltaTime);*/

	// Check for collisions
	collisionChecker.Update(agents, collisionManager.GetCurrentlyCollidingObjectContainerPtr());
}
#pragma endregion