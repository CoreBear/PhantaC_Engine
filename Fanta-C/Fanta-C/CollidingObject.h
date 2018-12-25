#ifndef _COLLIDING_OBJECT_H
#define _COLLIDING_OBJECT_H

// My Headers
#include "ScriptManager.h"

class CollidingObject : public ScriptManager
{
	// Private Functionality
	void CollisionHandling()
	{
		if (newCollision)
			CollisionEnter();
		if (continuedCollision)
			CollisionContinue();
		if (newSeparation)
			CollisionExit();
	}

protected:
	// Variables
	bool		 continuedCollision;
	bool		 newCollision;
	bool		 newSeparation;
	SceneObject* myObject;

	// Protected Fucntionality
	virtual void CollisionEnter() { return; }
	virtual void CollisionExit() { return; }
	virtual void CollisionContinue() { return; }

public:
	// Initialization
	CollidingObject(SceneObject* inObject) : continuedCollision(false), newCollision(false), newSeparation(false), myObject(inObject) { return; }

	// Update - Runs object collision functionality
	virtual void Update() { CollisionHandling(); }

	// Public Interface
	void ContinuedCollision(std::unordered_map<ushort, SceneObject*>* inCollidingObjects) override
	{
		continuedCollision = true;
		newCollision = false;
		newSeparation = false;
	}
	void NewCollision(SceneObject* inCollidingObject) override
	{
		continuedCollision = false;
		newCollision = true;
		newSeparation = false;
	}
	void NewSeparation() override
	{
		continuedCollision = false;
		newCollision = false;
		newSeparation = true;
	}
};

#endif