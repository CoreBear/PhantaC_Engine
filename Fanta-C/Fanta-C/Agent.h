#ifndef _AGENT_H
#define _AGENT_H

// My Headers
#include "Collider.h"
#include "Mesh.h"
#include "ObjectTransform.h"

class Collider;
class ObjectTransform;
class Mesh;

class Agent
{
	Collider*			colliderPtr;
	Mesh*				meshPtr;

protected:
	ObjectTransform*	transformPtr;

public:
	// Initialization
	Agent(ObjectTransform* transformPtr, bool collidable, bool renderable, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Update
	virtual void Update() {
		return;
	}// = 0;

	// Accessors
	Collider* GetColliderPtr() const { return colliderPtr; }
	Mesh* GetMeshPtr() const { return meshPtr; }
	ObjectTransform* GetTransformPtr() const { return transformPtr; }

	// Clean Up
	~Agent();
};

#endif