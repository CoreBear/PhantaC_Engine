#pragma region Dependencies
// System Headers
#include <Windows.h>			// Contains all destd::finitions for creating a windows based application

// My Headers
#include "EventHandler.h"
#include "EnvironmentManager.h"
#include "InputManager.h"
#include "GlobalTypedefs.h"
#include "WindowCreator.h"

// Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#pragma endregion

#pragma region Forward Declarations
void RunLoop(EnvironmentManager* environmentManager, EventHandler* events);
#pragma endregion

#pragma region Application Entry Function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	#pragma region Leak Detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// this function call will set a breakpoint at the location of a leaked block
	// set the parameter to the identifier for a leaked block
	//_CrtSetBreakAlloc(244);
	#pragma endregion

	// Handles all player input
	InputManager inputManager;

	// Handles all application events
	EventHandler events(&inputManager);

	// Creates the window
	WindowCreator window(hInstance, cmdShow, events.GetWndProc());

	// Creates the game instance
	EnvironmentManager environmentManager(window.GetWindowHandle(), window.GetClientDimensions());
	
	// Will run until quit message is posted
	RunLoop(&environmentManager, &events);

	// Make this return any errors that may occur. Have runloop return a value
	return 0;
}
#pragma endregion

#pragma region Application Loop
void RunLoop(EnvironmentManager* environmentManager, EventHandler* events)
{
	MSG msg = { 0 };	// Container that stores system messages

	// Main application loop
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

		// Main game update
		else
		{
			// Runs input manager
			events->Update();

			// Runs environment
			environmentManager->Update();
		}
	}
}
#pragma endregion