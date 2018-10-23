#pragma region Dependencies
// My Headers
#include "Agent.h"			// Connection to declarations
#pragma endregion

#pragma region Initialization
Agent::Agent(ObjectTransform* transformPtr, bool collider, bool renderer, float inMoveSpeed, float inRotationSpeed) : transformPtr(transformPtr)
{
	// If agent has a collider
	if (collider) colliderPtr = new CollidableObject(transformPtr->GetFlatness(), transformPtr->GetScale());

	// If agent has a renderer
	if (renderer) rendererPtr = new RenderableObject(transformPtr);

	transformPtr->SetMoveSpeed(inMoveSpeed);
	transformPtr->SetRotationSpeed(inRotationSpeed);
}
#pragma endregion