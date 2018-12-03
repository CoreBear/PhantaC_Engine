#pragma region Dependencies
// System Headers
#include <Windows.h>			// Contains all destd::finitions for creating a windows based application
#include <thread>

// My Headers
#include "EventHandler.h"
#include "EnvironmentManager.h"
#include "GlobalInput.h"
#include "GlobalThreading.h"
#include "GlobalTypedefs.h"
#include "WindowCreator.h"

// Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#pragma endregion

#pragma region Global Variables
bool GlobalInput::keysPressed[9];
#pragma endregion

#pragma region Forward Declarations
// Application Loop
/// Summary
/// Launches the thread that runs environment level of the application
///
/// Parameters
/// environmentManager - Runs everything, except window creation and events 
void RunEnvironment(EnvironmentManager* environmentManager);

// Event Handler
/// Summary
/// Receives system events
///
/// Parameters
/// hwnd - Unique window handle
/// message - The message that the window received
/// wParam - Additional information about/with the message
/// lParam - Additional information about/with the message
/// 
/// Return
/// LRESULT - The result of event processing (Returns 0 if everything is fine)
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
/// Summary
/// Processes key pressed events
///
/// Parameters
/// wParam - The value of the key being pressed
void KeyPressed(WPARAM wParam);
/// Summary
/// Processes key relesed events
///
/// Parameters
/// wParam - The value of the key being released
void KeyNotPressed(WPARAM wParam);
#pragma endregion

#pragma region Application Entry Function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	#pragma region Leak Detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// this function call will set a breakpoint at the location of a leaked block
	// set the parameter to the identifier for a leaked block
	// _CrtSetBreakAlloc(242);
	#pragma endregion

	// Creates the window
	WindowCreator* window = new WindowCreator(hInstance, cmdShow, &WndProc);

	// Creates the game instance
	EnvironmentManager* environmentManager = new EnvironmentManager(window->GetWindowHandle(), window->GetClientDimensions());
	
	// Will run until quit message is posted
	RunEnvironment(environmentManager);

	// Clean Up
	delete environmentManager;
	delete window;

	// Make this return any errors that may occur. Have runloop return a value
	return 0;
}
#pragma endregion

#pragma region Application Loop
void RunEnvironment(EnvironmentManager* environmentManager)
{
	// Container that stores system messages
	MSG msg = { 0 };

	// Launch environment thread
	std::thread eventThread(GlobalThreading::RunEnvironmentThread, environmentManager, &msg);

	// Event handler loop
	while (true)
	{
		// Retrieves the next message from the message queue
		// PM_REMOVE indicates that the retrieved message should be removed from the queue
		// Returns false if there are no messages to process
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			// WM_QUIT does not need to be translated or dispatched
			if (msg.message == WM_QUIT)
				break;

			// Translate virtual-ley messages into character messages
			TranslateMessage(&msg);

			// Dispatches message to the appropriate winow's procedure function
			DispatchMessage(&msg);
		}
	}

	eventThread.join();
}
#pragma endregion

#pragma region Event Handler
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// Closes the window
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		KeyPressed(wParam);
		break;
	case WM_KEYUP:
		KeyNotPressed(wParam);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
void KeyPressed(WPARAM wParam)
{
	switch (wParam)
	{
	case GlobalInput::A:
		GlobalInput::keysPressed[0] = true;
		break;
	case GlobalInput::D:
		GlobalInput::keysPressed[1] = true;
		break;
	case GlobalInput::I:
		GlobalInput::keysPressed[2] = true;
		break;
	case GlobalInput::J:
		GlobalInput::keysPressed[3] = true;
		break;
	case GlobalInput::K:
		GlobalInput::keysPressed[4] = true;
		break;
	case GlobalInput::L:
		GlobalInput::keysPressed[5] = true;
		break;
	case GlobalInput::S:
		GlobalInput::keysPressed[6] = true;
		break;
	case GlobalInput::W:
		GlobalInput::keysPressed[7] = true;
		break;
	case GlobalInput::SPACE:
		GlobalInput::keysPressed[8] = true;
		break;
	default:
		break;
	}
}
void KeyNotPressed(WPARAM wParam)
{
	switch (wParam)
	{
	case GlobalInput::A:
		GlobalInput::keysPressed[0] = false;
		break;
	case GlobalInput::D:
		GlobalInput::keysPressed[1] = false;
		break;
	case GlobalInput::I:
		GlobalInput::keysPressed[2] = false;
		break;
	case GlobalInput::J:
		GlobalInput::keysPressed[3] = false;
		break;
	case GlobalInput::K:
		GlobalInput::keysPressed[4] = false;
		break;
	case GlobalInput::L:
		GlobalInput::keysPressed[5] = false;
		break;
	case GlobalInput::S:
		GlobalInput::keysPressed[6] = false;
		break;
	case GlobalInput::W:
		GlobalInput::keysPressed[7] = false;
		break;
	case GlobalInput::SPACE:
		GlobalInput::keysPressed[8] = false;
		break;
	default:
		break;
	}
}
#pragma endregion