#pragma region Dependencies
// My Headers
#include "Logic.h"			// Connection to declarations
#include "Agent.h"
#include "AutonomousAgent.h"
#include "GlobalApplication.h"
#pragma endregion

#pragma region Update
void Logic::Update(std::vector<AutonomousAgent*>* autonomousAgents)
{
	for (iterators[0] = 0; iterators[0] < autonomousAgents->size(); ++iterators[0])
		autonomousAgents->at(iterators[0])->Plan();
}
#pragma endregion