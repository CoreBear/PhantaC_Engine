#ifndef _AGENT_H
#define _AGENT_H

// My Headers
#include "CollidableObject.h"
#include "Mesh.h"
#include "ObjectTransform.h"

class CollidableObject;
class ObjectTransform;
class Mesh;

class Agent
{
	CollidableObject*		colliderPtr;
	Mesh*					meshPtr;

protected:
	ObjectTransform*		transformPtr;

public:
	// Initialization
	Agent(ObjectTransform* transformPtr, bool collidable, bool renderable, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Accessors
	CollidableObject* GetColliderPtr() const { return colliderPtr; }
	Mesh* GetMeshPtr() const { return meshPtr; }
	ObjectTransform* GetTransformPtr() const { return transformPtr; }

	// Clean Up
	~Agent();
};

#endif