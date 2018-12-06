#ifndef _GLOBAL_THREADING_H
#define _GLOBAL_THREADING_H

// System Headers
#include <chrono>

// My Headers
#include "GlobalConsoleWrite.h"
#include "GlobalThreadVariables.h"
#include "GlobalTime.h"

// Pushes out as many frames as possible
class GlobalThreading
{
public:
	// Used by EntryEventLoop.cpp
	static void RunEnvironmentThread(EnvironmentManager* environmentManager, MSG* msg) { environmentManager->InitializeEnvironment(msg); }
	
	// Used by EnvironmentManager.cpp
	static void RunEnvironmentManagerThreads(ushort typeOfThread, EnvironmentManager* environmentManager, MSG* inMsg)
	{
		switch (typeOfThread)
		{
		case GlobalThreadVariables::THREAD::PHYSICS:
		{
			// Run everything function until quit is received
			while (inMsg->message != WM_QUIT)
				environmentManager->RunPhysics();
		}
		break;
		case GlobalThreadVariables::THREAD::FRAME:
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
				environmentManager->RunInput();
				environmentManager->RunScene();
				//environmentManager->RunPhysics();
				environmentManager->RunRenderer();
				environmentManager->RunAudio();

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
		break;
		}
	}
};

#endif