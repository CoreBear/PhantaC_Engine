#ifndef _GAME_CONTROLLER_H
#define _GAME_CONTROLLER_H

// System Headers
#include <Windows.h>

// My Headers
#include "Typedefs.h"

// Forward Declarations
class GameState;

class GameController
{
	const uchar				targetFPS = 100;
	const double			targetedFrameCompletionTime = double(1000) / targetFPS;
	float					deltaTime = 0;

	// State Machine
	GameState*				availableStates[2];
	GameState*				currentState;

	class Renderer*			rendererPtr;
	class SceneManager*		sceneManagerPtr;
	time_t					startTime = 0;
	time_t					endTime = 0;										

public:
	// Initialization
	GameController(HINSTANCE hInstance, HWND windowHandle, class InputController* inputController, ushort* clientDimensions);

	// Updates
	void MainThreadUpdate();		// The update that talks to main.cpp (i.e. input)
	void MainGameUpdate();			// The update that talks to the game

	// Public Interface
	// If game is paused, unpause, and vice versa
	void PauseUnpause() { currentState = (currentState == availableStates[0]) ? availableStates[1] : availableStates[0]; }
};

#endif