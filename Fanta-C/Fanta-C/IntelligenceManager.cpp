#pragma region Dependencies
// My Headers
#include "IntelligenceManager.h"			// Connection to declarations
#include "Agent.h"
#include "GlobalIterators.h"
#pragma endregion

#pragma region Update
void IntelligenceManager::Update(std::vector<Agent*>* autonomousAgents)
{
	for (iterators[0] = 0; iterators[0] < autonomousAgents->size(); ++iterators[0])
		autonomousAgents->at(iterators[0])->Update();
}
#pragma endregion