#ifndef _AGENT_H
#define _AGENT_H

// My Headers
#include "CollidableObject.h"
#include "ObjectTransform.h"
#include "RenderableObject.h"

class Agent
{
	CollidableObject*		colliderPtr;
	RenderableObject*		rendererPtr;

protected:
	ObjectTransform*		transformPtr;

public:
	// Initialization
	Agent(ObjectTransform* transformPtr, bool collider, bool renderer, float inMoveSpeed, float inRotationSpeed);

	// Accessors
	CollidableObject* GetColliderPtr() const { return colliderPtr; }
	RenderableObject* GetRendererPtr() const { return rendererPtr; }
	ObjectTransform* GetTransformPtr() const { return transformPtr; }
};

#endif