#ifndef _GAME_MANAGER_H
#define _GAME_MANAGER_H

// System Headers
#include <chrono>
#include <Windows.h>

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class GameState;

class GameManager
{
	// Window Variables
	HWND									windowHandle;							// Instance/Pointer to the program window
	LPCSTR									windowClassName = "Fanta-CWinClass";	// Unique for the application
	LPCSTR									windowName = "Fanta-C Engine";			// Name of window
	ushort									clientDimensions[2] = { 720, 1280 };	// Index 0 - Height. 1 - Width	

	// Game Variables
	const double							targetedFrameCompletionTime = double(1000) / targetFPS;
	float									deltaTime = 0;
	GameState*								availableStates[2];
	GameState*								currentState;
	class Renderer*							rendererPtr;
	class SceneManager*						sceneManagerPtr;
	std::chrono::duration<float>			chronoDelta;
	std::chrono::steady_clock::time_point	startTime;
	std::chrono::steady_clock::time_point	endTime;
	const uchar								targetFPS = 100;

	// System Input
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);				// Handles mouse, keyboard, and window events that are sent to the application

	// Update Main
	void ApplicationLoop();

public:
	// Initialization
	GameManager(HINSTANCE hInstance, int cmdShow);
	void InitializeWindow(HINSTANCE hInstance, int cmdShow);

	// Update
	void MainGameUpdate(float deltaTime);			// The update that talks to the game

	// Public Interface
	// If game is paused, unpause, and vice versa
	void PauseUnpause() { currentState = (currentState == availableStates[0]) ? availableStates[1] : availableStates[0]; }
};

#endif