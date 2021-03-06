#pragma region Dependencies
// My Headers
#include "ThreadManager.h"		// Connection to declarations

#include "EnvironmentManager.h"
#include "GlobalConsoleWrite.h"
#include "GlobalTime.h"
#include "WindowCreator.h"
#pragma endregion

#pragma region Forward Declarations
const char*				GlobalConsoleWrite::conversionChar = nullptr;
float					GlobalTime::deltaTime = 0;
HWND*					GlobalConsoleWrite::handle = nullptr;
std::string				GlobalConsoleWrite::conversionString;
ThreadManager*			ThreadManager::threadManagerInstance = nullptr;
#pragma endregion

#pragma region Initializaiton & Running
ThreadManager::ThreadManager(EnvironmentManager* inEnvironmentManager, MSG* inMsg, WindowCreator* window)
{
	// Flags that allow other threads to skip this functionality
	bool mainThreadHasPassedFirstPoint = false;
	bool mainThreadHasPassedSecondPoint = false;

	// Assign the handle for console/header writing
	GlobalConsoleWrite::handle = window->GetWindowHandle();

	// Launches the first thread
	threads[0] = new std::thread(InputLogicThread, inEnvironmentManager, inMsg);
	
	// In place for the second thread
	if (!mainThreadHasPassedFirstPoint)
	{
		// Flip flag so other threads cannot follow and get stuck in the loop
		mainThreadHasPassedFirstPoint = true;

		// Launces the second thread
		threads[1] = new std::thread(PhysicsThread, inEnvironmentManager, inMsg);
	}

	// In place for the second thread
	if (!mainThreadHasPassedSecondPoint)
	{
		// Flip flag so other threads cannot follow and get stuck in the loop
		mainThreadHasPassedSecondPoint = true;

		// Launces the third thread
		threads[2] = new std::thread(RenderThread, inEnvironmentManager, inMsg);
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
void ThreadManager::InputLogicThread(EnvironmentManager* inEnvironmentManager, MSG* inMsg)
{
	// Run everything function until quit is received
	while (inMsg->message != WM_QUIT)
	{
		inEnvironmentManager->RunEventHandler();
		inEnvironmentManager->RunScene();
	}
}
void ThreadManager::RenderThread(EnvironmentManager* inEnvironmentManager, MSG* inMsg)
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

		// Run module
		inEnvironmentManager->RunRenderer();
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
