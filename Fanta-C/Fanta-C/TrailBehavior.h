#ifndef _TRAIL_BEHAVIOR_H
#define _TRAIL_BEHAVIOR_H

// My Headers
#include "NonMovingObject.h"
#include "SceneGraph.h"

class TrailBehavior : public NonMovingObject
{
	bool targetedForRemoval;
	float currentTime;
	float lifeTime;

public:
	// Initialization
	TrailBehavior(SceneObject* inObject) : targetedForRemoval(false), currentTime(0), lifeTime(1), NonMovingObject(inObject) { return; }

	// Update
	void Update() override 
	{
		if (!targetedForRemoval)
		{
			currentTime += .1f;

			if (currentTime > lifeTime)
			{
				SceneGraph::AddObjectToRemovableList(myObject);
				targetedForRemoval = true;
			}
		}
	}
};

#endif