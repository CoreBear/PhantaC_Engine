#pragma region Dependencies
// My Headers
#include "KeyboardManager.h"		// Connection to declarations

#include "GlobalInputVariables.h"
#include "InputManager.h"
#include "PlayerManager.h"

// System Headers
#include <Windows.h>
#pragma endregion

#pragma region Forward Declarations
KeyboardManager* KeyboardManager::keyboardManagerInstance = nullptr;
#pragma endregion

#pragma region MyRegion
KeyboardManager::KeyboardManager(PlayerManager* inPlayerManager) : playerManagerPtr(inPlayerManager), inputManagerPtr(InputManager::GetInstance(inPlayerManager)) { return; }
#pragma endregion

#pragma region Update
void KeyboardManager::Update()
{
	// Poor way to handle this...look into raw input
	if (GetAsyncKeyState(GlobalInputVariables::KEYS::A)) KeyEventHandler(true, 0);
	else KeyEventHandler(false, 0);

	if (GetAsyncKeyState(GlobalInputVariables::KEYS::D)) KeyEventHandler(true, 1);
	else KeyEventHandler(false, 1);

	if (GetAsyncKeyState(GlobalInputVariables::KEYS::I)) KeyEventHandler(true, 2);
	else KeyEventHandler(false, 2);

	if (GetAsyncKeyState(GlobalInputVariables::KEYS::J)) KeyEventHandler(true, 3);
	else KeyEventHandler(false, 3);

	if (GetAsyncKeyState(GlobalInputVariables::KEYS::K)) KeyEventHandler(true, 4);
	else KeyEventHandler(false, 4);

	if (GetAsyncKeyState(GlobalInputVariables::KEYS::L)) KeyEventHandler(true, 5);
	else KeyEventHandler(false, 5);

	if (GetAsyncKeyState(GlobalInputVariables::KEYS::S)) KeyEventHandler(true, 6);
	else KeyEventHandler(false, 6);

	if (GetAsyncKeyState(GlobalInputVariables::KEYS::W)) KeyEventHandler(true, 7);
	else KeyEventHandler(false, 7);

	if (GetAsyncKeyState(GlobalInputVariables::KEYS::SPACE)) KeyEventHandler(true, 8);
	else KeyEventHandler(false, 8);
}
#pragma endregion

#pragma region Accessors
KeyboardManager* KeyboardManager::GetInstance(PlayerManager* inPlayerManager)
{
	// If instance is already created, return it
	if (keyboardManagerInstance) return keyboardManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		keyboardManagerInstance = new KeyboardManager(inPlayerManager);
		return keyboardManagerInstance;
	}
}
#pragma endregion

#pragma region Private
void KeyboardManager::KeyEventHandler(bool keyDown, uchar index)
{
	// If key is pressed
	if (keyDown)
	{
		// If key was up last frame
		if (!keyIsDown[index])
		{
			// Key is now pressed
			keyIsDown[index] = true;

			// Key went down this frame
			keyDownThisFrame[index] = true;

			// Send to manager for processing
			inputManagerPtr->HandleInput(true, index);
		}

		// If key was down last frame
		else
		{
			// Flip flag
			if (keyDownThisFrame[index])
				keyDownThisFrame[index] = false;

			// Send to manager for processing
			inputManagerPtr->HandleInput(false, index);
		}
	}

	// If key is released
	else
	{
		// If key was down last frame
		if (keyIsDown[index])
		{
			// Flip flag so key is up
			keyIsDown[index] = false;

			// Moves too fast for this to event happen, but if for some reason it sticks, uncomment this
			// Flip flag
			//if (keyDownThisFrame[index])
			//	keyDownThisFrame[index] = false;
		}
	}
}
#pragma endregion
