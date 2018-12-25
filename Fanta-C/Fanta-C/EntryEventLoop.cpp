#pragma region Dependencies
// System Headers
#include <Windows.h>			// Contains all destd::finitions for creating a windows based application
#include <thread>

// My Headers
#include "EnvironmentManager.h"
#include "GlobalInputVariables.h"
#include "GlobalTypedefs.h"
#include "WindowCreator.h"

// Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#pragma endregion

#pragma region Forward Declarations
// Application
/// Summary
/// Launches the thread that runs environment level of the application
/// and runs system event loop
/// Parameters
/// environmentManager - Runs everything, except window creation and events 
void RunApplication(EnvironmentManager& environmentManager);

// Environment
/// Summary
/// Runs the environment that houses the game
///
/// Parameters
/// environmentManager - Runs everything, except window creation and events 
/// msg - Stores system events
void RunEnvironment(EnvironmentManager* environmentManager, const MSG* msg);

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
	// _CrtSetBreakAlloc(244);
	#pragma endregion

	// Creates the window
	Application_Level::WindowCreator* window = Application_Level::WindowCreator::GetInstance(hInstance, cmdShow, &WndProc);

	// Creates the game instance
	EnvironmentManager* environmentManager = EnvironmentManager::GetInstance(window);
	
	// Will run until quit message is posted
	RunApplication(*environmentManager);

	// Clean Up
	delete environmentManager;
	delete window;

	// Make this return any errors that may occur. Have runloop return a value
	return 0;
}
#pragma endregion

#pragma region Application
void RunApplication(EnvironmentManager& environmentManager)
{
	// Flag to let other threads know they can skip this functionality
	bool mainThreadHasBeenHere = false;

	// Container that stores system messages
	MSG msg = { 0 };
	
	std::thread* environmentThread = new std::thread(RunEnvironment, &environmentManager, &msg);

	// In place for the second thread
	if (!mainThreadHasBeenHere)
	{
		// Flip flag so other threads cannot follow and get stuck in the loop
		mainThreadHasBeenHere = true;

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

	// Join threads and delete additional
	environmentThread->join();
	delete environmentThread;
}
#pragma endregion

#pragma region Environment
void RunEnvironment(EnvironmentManager* environmentManager, const MSG* msg)
{
	// Will continue running until quit message is received
	while (msg->message != WM_QUIT)
		environmentManager->Update();
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