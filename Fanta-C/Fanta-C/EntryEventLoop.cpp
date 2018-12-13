#pragma region Dependencies
// System Headers
#include <Windows.h>			// Contains all destd::finitions for creating a windows based application
#include <thread>

// My Headers
#include "EnvironmentManager.h"
#include "GlobalInputVariables.h"
#include "GlobalTypedefs.h"
#include "ThreadManager.h"
#include "WindowCreator.h"

// Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#pragma endregion

#pragma region Forward Declarations
// Application Loop
/// Summary
/// Launches the thread that runs environment level of the application
///
/// Parameters
/// environmentManager - Runs everything, except window creation and events 
/// window - Creates window
void RunEnvironment(EnvironmentManager* environmentManager, WindowCreator* window);
// System Event Handler
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
#pragma endregion

#pragma region Application Entry Function
// Program Entry
/// Summary
/// The first function that is called to run the program
///
/// Parameters
/// hInstance - Hangle to current application instance
/// prevInstance - Handle to previous application instance
/// cmdLine - Pointer to null-terminated string specifying the command line for the applciation, excluding the program name
/// cmdShow - Specifies how the window will be shown
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	#pragma region Leak Detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// this function call will set a breakpoint at the location of a leaked block
	// set the parameter to the identifier for a leaked block
	// _CrtSetBreakAlloc(6402);
	#pragma endregion

	// Creates the window
	WindowCreator* window = WindowCreator::GetInstance(hInstance, cmdShow, &WndProc);

	// Creates the game instance
	EnvironmentManager* environmentManager = EnvironmentManager::GetInstance(window->GetWindowHandle(), window->GetClientDimensions());
	
	// Will run until quit message is posted
	RunEnvironment(environmentManager, window);

	// Clean Up
	delete environmentManager;
	delete window;

	// Make this return any errors that may occur. Have runloop return a value
	return 0;
}
#pragma endregion

#pragma region Application Loop
void RunEnvironment(EnvironmentManager* environmentManager, WindowCreator* window)
{
	// Flag to let other threads know they can skip this functionality
	bool firstThreadHasPassedThisPoint = false;

	// Container that stores system messages
	MSG msg = { 0 };

	// Creates the object that the majority of the threads will continue to run in
	ThreadManager* threadManager = ThreadManager::GetInstance(environmentManager, &msg, window);
	
	// In place for the second thread
	if (!firstThreadHasPassedThisPoint)
	{
		// Flip flag so other threads cannot follow and get stuck in the loop
		firstThreadHasPassedThisPoint = true;

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
	}

	// Join threads and delete the manager
	threadManager->JoinThreads();
	delete threadManager;
}
#pragma endregion

#pragma region System Event Handler
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// Closes the window
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
#pragma endregion