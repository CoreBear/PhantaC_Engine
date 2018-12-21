#ifndef _UI_MANAGER_H
#define _UI_MANAGER_H

// My Headers
#include "Reticle.h"

// Forward Declarations
class Renderer;

class UiManager
{
	Renderer*			renderPtr;
	Reticle				reticle;
	static UiManager*	uiManagerInstance;

	UiManager(Renderer* renderer) : renderPtr(renderer) { return; }
	UiManager(UiManager const&) = delete;
	UiManager operator=(UiManager const&) = delete;

public:
	// Initialization
	static UiManager* GetInstance(Renderer* renderer);

	// Update
	void Update();

	// Accessors
	Reticle* GetReticle() { return &reticle; }
};

#endif