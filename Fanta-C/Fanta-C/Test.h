#pragma once
#include "MovingObject.h"

class Test : public MovingObject
{
public:
	// Initialization
	Test(ObjectManager* inObject) : MovingObject(inObject, 3) { return; }

	// Update
	void Update() override;
};