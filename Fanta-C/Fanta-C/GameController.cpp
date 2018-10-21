#pragma region Dependencies
// My Headers
#include "GameController.h"			// Connection to declarations
#include "GameState.h"
#include "InputController.h"
#include "Renderer.h"
#include "SceneManager.h"

// System Headers
#include <time.h>					// For delta time
#pragma endregion

#pragma region Initialization
GameController::GameController(HINSTANCE hInstance, HWND windowHandle, InputController* inputController, ushort* clientDimensions)
{
	currentState = availableStates[0] = new GameRunning(this);
	availableStates[1] = new GamePaused;
	sceneManagerPtr = new SceneManager(inputController, clientDimensions);
	rendererPtr = new Renderer(hInstance, windowHandle, sceneManagerPtr, clientDimensions, targetFPS);
}
#pragma endregion

#pragma region Update
void GameController::MainThreadUpdate()
{
	currentState->UpdateState();
}
void GameController::MainGameUpdate()
{
	// Stores how long it took to complet the frame
	//deltaTime = endTime - startTime;

	// Stores the time at the beginning of the frame
	//time(&startTime);

	sceneManagerPtr->Update();
	rendererPtr->Update(sceneManagerPtr->GetSceneObjectsPtr());

	// Stores the time at the end of the frame
	//time(&endTime);
}
#pragma endregion