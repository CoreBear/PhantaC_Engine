#ifndef _AGENT_H
#define _AGENT_H

// My Headers
#include "CollidableObject.h"
#include "Shape.h"
#include "ObjectTransform.h"

class CollidableObject;
class ObjectTransform;
class Shape;

class Agent
{
	CollidableObject*		colliderPtr;
	Shape*					shapePtr;

protected:
	ObjectTransform*		transformPtr;

public:
	// Initialization
	Agent(ObjectTransform* transformPtr, bool collidable, bool renderable, float inMoveSpeed = 0, float inRotationSpeed = 0);

	// Accessors
	CollidableObject* GetColliderPtr() const { return colliderPtr; }
	Shape* GetShapePtr() const { return shapePtr; }
	ObjectTransform* GetTransformPtr() const { return transformPtr; }

	// Clean Up
	~Agent();
};

#endif