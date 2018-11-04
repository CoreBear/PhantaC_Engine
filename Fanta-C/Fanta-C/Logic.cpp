#pragma region Dependencies
// My Headers
#include "Logic.h"			// Connection to declarations
#include "Agent.h"
#include "AutonomousAgent.h"
#include "GlobalApplication.h"
#pragma endregion

#pragma region Update
void Logic::Update(std::vector<Agent*>* autonomousAgents)
{
	// Camera's index is 0, so skip
	for (iterators[0] = 1; iterators[0] < autonomousAgents->size(); ++iterators[0])
		static_cast<AutonomousAgent*>(autonomousAgents->at(iterators[0]))->Plan();
}
#pragma endregion