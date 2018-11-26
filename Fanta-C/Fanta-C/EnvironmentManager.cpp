#pragma region Dependencies
// My Headers
#include "EnvironmentManager.h"			// Connection to declarations

#include "AudioManager.h"
#include "InputManager.h"
#include "PhysicsManager.h"
#include "Renderer.h"
#include "SceneGraph.h"
#include "SceneManager.h"
#pragma endregion

#pragma region Global Variables
float GlobalTime::deltaTime = 0;
#pragma endregion

#pragma region Global Functions
void ThreadInitializer(uchar typeOfThread, EnvironmentManager* environmentManager, MSG* msg)
{
	switch (typeOfThread)
	{
	case 0:		
		environmentManager->RunAudio(msg);
		break;
	case 1:
		environmentManager->RunInput(msg);
		break;
	case 2:
		environmentManager->RunPhysics(msg);
		break;
	case 3:
		environmentManager->RunRenderer(msg);
		break;
	case 4:
		environmentManager->RunScene(msg);
		break;
	}
}
#pragma endregion

#pragma region Initialization
EnvironmentManager::EnvironmentManager(HWND windowHandle, ushort* clientDimensions)
{
	#pragma region Module Creation
	audioManagerPtr = new AudioManager;

	inputManagerPtr = new InputManager;

	physicsManagerPtr = new PhysicsManager;

	sceneManagerPtr = new SceneManager(clientDimensions, &windowHandle, targetFPS);
	
	rendererPtr = new Renderer(windowHandle, sceneManagerPtr, clientDimensions, targetFPS, sceneManagerPtr->GetScenePtr()->GetCamera());
	#pragma endregion
}
void EnvironmentManager::ThreadMaintenance(MSG* msg)
{	
	// Thread Creation
	for (iterators[0] = 0; iterators[0] < numberOfThreads; ++iterators[0])
		threads[iterators[0]] = new std::thread(ThreadInitializer, iterators[0], this, msg);

	while (msg->message != WM_QUIT)
	{
		// For each thread
		for (threadIterator = 0; threadIterator < numberOfThreads; ++threadIterator)
		{
			// If thread cycle isn't complete, start over
			if (!cycleCompleted[threadIterator])
				continue;
		}

		// Zero out global delta time
		GlobalTime::deltaTime = 0;

		for (threadIterator = 0; threadIterator < numberOfThreads; ++threadIterator)
		{
			// Update global delta time
			GlobalTime::deltaTime += chronoDelta[threadIterator].count();

			// Update flags that effect individual delta time
			resetTimes[threadIterator] = true;
			cycleCompleted[threadIterator] = false;
		}
	}

	// Join threads before destroying them
	for (auto& thread : threads) thread->join();	
}
#pragma endregion

#pragma region Thread Functions
void EnvironmentManager::RunAudio(MSG* msg)
{
	while (msg->message != WM_QUIT)
	{
		startTime[0] = std::chrono::steady_clock::now();

		audioManagerPtr->Update();

		endTime[0] = std::chrono::steady_clock::now();
		chronoDelta[0] = endTime[0] - startTime[0];

		// Continue adding to cumulative, until time to reset it back to zero
		if (!resetTimes[0])
			cumulativeDeltas[0] += chronoDelta[0].count();
		else
		{
			cumulativeDeltas[0] = 0;
			resetTimes[0] = false;
		}
	
		if (!cycleCompleted[0]) cycleCompleted[0] = true;
	}
}
void EnvironmentManager::RunInput(MSG* msg)
{
	while (msg->message != WM_QUIT)
	{
		startTime[1] = std::chrono::steady_clock::now();

		inputManagerPtr->Update();

		endTime[1] = std::chrono::steady_clock::now();
		chronoDelta[1] = endTime[1] - startTime[1];

		// Continue adding to cumulative, until time to reset it back to zero
		if (!resetTimes[1])
			cumulativeDeltas[1] += chronoDelta[1].count();
		else
		{
			cumulativeDeltas[1] = 0;
			resetTimes[1] = false;
		}

		if (!cycleCompleted[1]) cycleCompleted[1] = true;
	}
}
void EnvironmentManager::RunPhysics(MSG* msg)
{
	while (msg->message != WM_QUIT)
	{
		startTime[2] = std::chrono::steady_clock::now();

		physicsManagerPtr->Update(sceneManagerPtr->GetScenePtr()->GetCollidableObjects());

		endTime[2] = std::chrono::steady_clock::now();
		chronoDelta[2] = endTime[2] - startTime[2];

		// Continue adding to cumulative, until time to reset it back to zero
		if (!resetTimes[2])
			cumulativeDeltas[2] += chronoDelta[2].count();
		else
		{
			cumulativeDeltas[2] = 0;
			resetTimes[2] = false;
		}

		if (!cycleCompleted[2]) cycleCompleted[2] = true;
	}
}
void EnvironmentManager::RunRenderer(MSG* msg)
{
	while (msg->message != WM_QUIT)
	{
		startTime[3] = std::chrono::steady_clock::now();

		rendererPtr->Update(sceneManagerPtr->GetScenePtr()->GetRenderableObjects(), sceneManagerPtr->GetScenePtr()->GetCamera());

		endTime[3] = std::chrono::steady_clock::now();
		chronoDelta[3] = endTime[3] - startTime[3];

		// Continue adding to cumulative, until time to reset it back to zero
		if (!resetTimes[3])
			cumulativeDeltas[3] += chronoDelta[3].count();
		else
		{
			cumulativeDeltas[3] = 0;
			resetTimes[3] = false;
		}

		if (!cycleCompleted[3]) cycleCompleted[3] = true;
	}
}
void EnvironmentManager::RunScene(MSG* msg)
{ 
	while (msg->message != WM_QUIT)
	{
		startTime[4] = std::chrono::steady_clock::now();

		sceneManagerPtr->Update();

		endTime[4] = std::chrono::steady_clock::now();
		chronoDelta[4] = endTime[4] - startTime[4];

		// Continue adding to cumulative, until time to reset it back to zero
		if (!resetTimes[4])
			cumulativeDeltas[4] += chronoDelta[4].count();
		else
		{
			cumulativeDeltas[4] = 0;
			resetTimes[4] = false;
		}

		if (!cycleCompleted[4]) cycleCompleted[4] = true;
	}
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
	
	// Delete all threads
	for (iterators[0] = 0; iterators[0] < numberOfThreads; ++iterators[0])
		delete threads[iterators[0]];
}
#pragma endregion
