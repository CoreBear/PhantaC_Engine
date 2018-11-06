#ifndef _INTELLIGENCE_MANAGER_H
#define _INTELLIGENCE_MANAGER_H

// System Headers
#include <vector>

class IntelligenceManager
{
public:
	// Update
	void Update(std::vector<class Agent*>* autonomousAgents);
};

#endif