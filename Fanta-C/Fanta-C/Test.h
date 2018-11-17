#pragma once
#include "ScriptManager.h"
class Test : public ScriptManager
{
public:
	// Initialization
	Test(ObjectManager* inObject) : ScriptManager(inObject) { return; }

	// Update
	void Update(float delteTime) override;
};

