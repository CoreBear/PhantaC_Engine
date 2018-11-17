#ifndef _INPUT_CONTROLLER_H
#define _INPUT_CONTROLLER_H

// My Headers
#include "GlobalInput.h"

// Forward Declarations
class PlayerManager;
class SceneManager;

class InputManager
{
	PlayerManager*	playerPtr;			// Update to take multiple players
	SceneManager*	sceneManagerPtr;	// Temporary

public:	
	// Update
	void Update(bool* keysCurrentlyPressed);

	// Public Interface
	void AssignPlayer(PlayerManager* inPlayer) { playerPtr = inPlayer; }
	void AssignSceneManager(SceneManager* inSceneManager) { sceneManagerPtr = inSceneManager; }
};

#endif