#pragma region Dependencies
// My Headers
#include "ThreadManager.h"		// Connection to declarations

#include "EnvironmentManager.h"
#include "GlobalConsoleWrite.h"
#include "GlobalTime.h"
#include "WindowCreator.h"
#pragma endregion

#pragma region Forward Declarations
const char*		GlobalConsoleWrite::conversionChar = nullptr;
float			GlobalTime::deltaTime = 0;
HWND*			GlobalConsoleWrite::handle = nullptr;
std::string		GlobalConsoleWrite::conversionString;
ThreadManager*	ThreadManager::threadManagerInstance = nullptr;
#pragma endregion

#pragma region Initializaiton & Running
ThreadManager::ThreadManager(EnvironmentManager* inEnvironmentManager, MSG* inMsg, WindowCreator* window) : environmentManager(inEnvironmentManager)
{
	// Flag to let other threads know they can skip this functionality
	bool firstThreadHasPassedThisPoint = false;

	// Assign the handle for console/header writing
	GlobalConsoleWrite::handle = window->GetWindowHandle();

	// Launches the first thread
	threads[0] = new std::thread(FrameThread, inEnvironmentManager, inMsg);
	
	// In place for the second thread
	if (!firstThreadHasPassedThisPoint)
	{
		// Flip flag so other threads cannot follow and get stuck in the loop
		firstThreadHasPassedThisPoint = true;

		// Launces the second thread
		threads[1] = new std::thread(PhysicsThread, inEnvironmentManager, inMsg);
	}
}
#pragma endregion

#pragma region Accessors
ThreadManager* ThreadManager::GetInstance(EnvironmentManager* inEnvironmentManager, MSG* inMsg, WindowCreator* window)
{
	// If instance is already created, return it
	if (threadManagerInstance) return threadManagerInstance;

	// If instance has not been created, create it and return it
	else
	{
		threadManagerInstance = new ThreadManager(inEnvironmentManager, inMsg, window);
		return threadManagerInstance;
	}
}
#pragma endregion

#pragma region Clean UP
ThreadManager::~ThreadManager()
{
	// Delete additional threads that aren't main
	for (iterator = 0; iterator < numberOfThreads; ++iterator)
		delete threads[iterator];
}
#pragma endregion

#pragma region Private
void ThreadManager::FrameThread(EnvironmentManager* inEnvironmentManager, MSG* inMsg)
{
	float									fpsTimeElapsed = 0;
	std::chrono::duration<float>			chronoDelta;
	std::chrono::steady_clock::time_point	frameEndTime;
	std::chrono::steady_clock::time_point	frameStartTime;
	std::string								fpsString;
	ushort									actualFpsCount;
	ushort									frameCounter = 0;
	const ushort							thousandMilliseconds = 1000;	// Milliseconds

	// Run everything function until quit is received
	while (inMsg->message != WM_QUIT)
	{
		// Assign the start time for the frame
		frameStartTime = std::chrono::steady_clock::now();

		// Run modules
		inEnvironmentManager->RunEventHandler();
		inEnvironmentManager->RunScene();
		inEnvironmentManager->RunRenderer();
		inEnvironmentManager->RunAudio();

		// Assign frame's end time
		frameEndTime = std::chrono::steady_clock::now();

		// Get delta time in chrono standards and assign it to global delta time
		chronoDelta = frameEndTime - frameStartTime;
		GlobalTime::deltaTime = chronoDelta.count();

		#pragma region FPS Counter
		// Update the time for fps update
		fpsTimeElapsed += GlobalTime::deltaTime * thousandMilliseconds;

		// Increment for each frame completed
		++frameCounter;

		// Update fps every half a second
		if (fpsTimeElapsed > thousandMilliseconds)
		{
			// Store the number of frames counted
			actualFpsCount = frameCounter;

			// Zero out frames counted for the next cycle
			frameCounter = 0;

			// Reset timer
			fpsTimeElapsed = 0;

			// Hack to show FPS. Remove later
			GlobalConsoleWrite::WriteToConsole(actualFpsCount);
		}
		#pragma endregion
	}
}
void ThreadManager::PhysicsThread(EnvironmentManager* inEnvironmentManager, MSG* inMsg)
{
	// Run everything function until quit is received
	while (inMsg->message != WM_QUIT)
		inEnvironmentManager->RunPhysics();
}
#pragma endregion
