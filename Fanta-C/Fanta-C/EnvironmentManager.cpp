#pragma region Dependencies
// My Headers
#include "EnvironmentManager.h"			// Connection to declarations

#include "AudioManager.h"
#include "GlobalTime.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "Renderer.h"
#include "SceneGraph.h"
#include "SceneManager.h"
#include "SceneObject.h"
#include "UiManager.h"
#pragma endregion

#pragma region Forward Declarations
const char*			GlobalConsoleWrite::conversionChar = nullptr;
float				GlobalTime::deltaTime = 0;
HWND*				GlobalConsoleWrite::handle = nullptr;
std::string			GlobalConsoleWrite::conversionString;
EnvironmentManager*	EnvironmentManager::environmentManagerInstance = nullptr;
#pragma endregion

#pragma region Initialization
EnvironmentManager::EnvironmentManager(Application_Level::WindowCreator* window) : fpsTimeElapsed(0), targetFPS(60), frameCounter(0), thousandMilliseconds(1000)
{
	// Assign the handle for console/header writing
	GlobalConsoleWrite::handle = window->GetWindowHandle();

	#pragma region Module Creation
	audioManagerPtr = AudioManager::GetInstance();

	sceneManagerPtr = SceneManager::GetInstance(*window);

	inputManagerPtr = InputManager::GetInstance(sceneManagerPtr->GetScenePtr()->GetPlayer(), sceneManagerPtr->GetScenePtr());

	physicsManagerPtr = PhysicsManager::GetInstance(&sceneManagerPtr->GetScenePtr()->GetGrid());
	
	rendererPtr = Renderer::GetInstance(window, sceneManagerPtr, targetFPS);

	uiManagerPtr = UiManager::GetInstance(rendererPtr);
	#pragma endregion
}
EnvironmentManager* EnvironmentManager::GetInstance(Application_Level::WindowCreator* window)
{
	// If instance has already been created
	if (environmentManagerInstance) return environmentManagerInstance;

	// If instance has not been created, create one and return it
	else
	{
		environmentManagerInstance = new EnvironmentManager(window);
		return environmentManagerInstance;
	}
}
#pragma endregion

#pragma region Update
void EnvironmentManager::Update()
{
	FPSStart();
	inputManagerPtr->Update();
	sceneManagerPtr->Update();
	physicsManagerPtr->Update();
	uiManagerPtr->Update();
	rendererPtr->DrawDebug();
	audioManagerPtr->Update();
	sceneManagerPtr->GetScenePtr()->CleanScene();
	FPSEnd();
}
#pragma endregion

#pragma region Private Functionality
void EnvironmentManager::FPSEnd()
{
	// Assign frame's end time
	frameEndTime = std::chrono::steady_clock::now();

	// Get delta time in chrono standards and assign it to global delta time
	chronoDelta = frameEndTime - frameStartTime;
	GlobalTime::deltaTime = chronoDelta.count();

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
}
void EnvironmentManager::FPSStart()
{
	// Assign the start time for the frame
	frameStartTime = std::chrono::steady_clock::now();
}
#pragma endregion


#pragma region Clean Up
EnvironmentManager::~EnvironmentManager()
{
	if (audioManagerPtr) delete audioManagerPtr;
	if (inputManagerPtr) delete inputManagerPtr;
	if (physicsManagerPtr) delete physicsManagerPtr;
	if (rendererPtr) delete rendererPtr;
	if (sceneManagerPtr) delete sceneManagerPtr;
	if (uiManagerPtr) delete uiManagerPtr;
}
#pragma endregion