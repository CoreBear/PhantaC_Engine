#pragma region Dependencies
// My Headers
#include "Agent.h"			// Connection to declarations
#pragma endregion

#pragma region Initialization
Agent::Agent(ObjectTransform* inPhysicalBodyPtr, float inMoveSpeed, float inRotationSpeed) : isColliding(false), physicalBodyPtr(inPhysicalBodyPtr)
{
	physicalBodyPtr->SetMoveSpeed(inMoveSpeed);
	physicalBodyPtr->SetRotationSpeed(inRotationSpeed);
}
#pragma endregion