#ifndef _GLOBAL_THREADING_H
#define _GLOBAL_THREADING_H

// System Headers
#include <chrono>

// My Headers
#include "GlobalTime.h"

// Forward Declarations (Can I do this better?)
static std::chrono::duration<float>				chronoDelta;
static std::chrono::steady_clock::time_point	frameEndTime;
static std::chrono::steady_clock::time_point	frameStartTime;

class GlobalThreading
{
public:
	// Used by EntryEventLoop.cpp
	static void RunEnvironmentThread(EnvironmentManager* environmentManager, MSG* msg) { environmentManager->ThreadManager(msg); }
	
	// Used by EnvironmentManager.cpp
	static void RunEnvironmentManagerThreads(uchar typeOfThread, EnvironmentManager* environmentManager, MSG* inMsg)
	{
		// Input Thread
		if (typeOfThread == 0)
		{
			// Run everything function until quit is received
			while (inMsg->message != WM_QUIT)
				environmentManager->RunInput();
		}

		// Frame Thread
		else
		{
			// Run everything function until quit is received
			while (inMsg->message != WM_QUIT)
			{
				// Assign the start time for the frame
				frameStartTime = std::chrono::steady_clock::now();

				// Run modules
				environmentManager->RunScene();
				environmentManager->RunPhysics();
				environmentManager->RunUI();
				environmentManager->RunRenderer();
				environmentManager->RunAudio();

				// Assign frame's end time
				frameEndTime = std::chrono::steady_clock::now();

				// Get delta time in chrono standards and assign it to global delta time
				chronoDelta = frameEndTime - frameStartTime;
				GlobalTime::deltaTime = chronoDelta.count();
			}
		}
	}
};

#endif