#pragma region Dependencies
// My Headers
#include "PhysicsMain.h"			// Connection to declarations
#include "AutonomousAgent.h"
#include "ObjectTransform.h"
#include "GlobalApplication.h"
#pragma endregion

#pragma region Update
void PhysicsMain::Update(float deltaTime, std::vector<Agent*>* autonomousAgents, std::vector<Agent*>* staticAgents)
{
	// Camera's index is 0, so skip
	for (iterators[0] = 1; iterators[0] < autonomousAgents->size(); ++iterators[0])
		static_cast<AutonomousAgent*>(autonomousAgents->at(iterators[0]))->Action(deltaTime);

	// Check for collisions
	collisionChecker.Update(autonomousAgents, staticAgents, collisionManager.GetCurrentlyCollidingObjectContainerPtr());
}
#pragma endregion