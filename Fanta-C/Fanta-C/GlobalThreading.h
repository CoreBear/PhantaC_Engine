#ifndef _GLOBAL_THREADING_H
#define _GLOBAL_THREADING_H

// System Headers
#include <chrono>
#include <string>

// My Headers
#include "GlobalTime.h"

// Forward Declarations (Can I do this better?)
static const char*								charString;
static float									fpsTimeElapsed;
static std::chrono::duration<float>				chronoDelta;
static std::chrono::steady_clock::time_point	frameEndTime;
static std::chrono::steady_clock::time_point	frameStartTime;
static std::string								fpsString;
static ushort									actualFpsCount;
static ushort									frameCounter;

class GlobalThreading
{

public:
	// Used by EntryEventLoop.cpp
	static void RunEnvironmentThread(EnvironmentManager* environmentManager, MSG* msg) { environmentManager->ThreadLauncher(msg); }
	
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
			#pragma region FPS
			// Variable Initialization
			const ushort thousandMilliseconds = 1000;	// Milliseconds
			frameCounter = 0;
			fpsTimeElapsed = 0;			
			#pragma endregion
			
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

				#pragma region FPS
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

					// Convert number to string
					fpsString = std::to_string(actualFpsCount).c_str();
					
					// Convert string to char*
					charString = fpsString.c_str();

					// Hack to show FPS. Remove later
					environmentManager->UpdateFPSIndicator(charString);
				}				
				#pragma endregion
			}
		}
	}
};

#endif