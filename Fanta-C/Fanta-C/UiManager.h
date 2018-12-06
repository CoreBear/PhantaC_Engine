#ifndef _UI_MANAGER_H
#define _UI_MANAGER_H

class UiManager
{
	static UiManager* uiManagerInstance;

	UiManager() { return; }
	UiManager(UiManager const&) = delete;
	UiManager operator=(UiManager const&) = delete;

public:
	// Update
	void Update() { return; }

	// Accessors
	static UiManager* GetInstance();
};

#endif