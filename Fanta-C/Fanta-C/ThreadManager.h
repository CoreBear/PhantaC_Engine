#ifndef _THREAD_MANAGER_H
#define _THREAD_MANAGER_H

// System Headers
#include <thread>
#include <Windows.h>

// My Headers
#include "GlobalTypedefs.h"

// Forward Declarations
class EnvironmentManager;
class WindowCreator;

class ThreadManager
{
	EnvironmentManager*		environmentManager;
	static ThreadManager*	threadManagerInstance;
	const static uchar		numberOfThreads = 2;
	std::thread*			threads[numberOfThreads];
	uchar					iterator;

	// Initialization & Running
	ThreadManager(EnvironmentManager* inEnvironmentManager, MSG* inMsg, WindowCreator* window);
	ThreadManager(ThreadManager const&) = delete;
	ThreadManager operator=(ThreadManager const&) = delete;

	static void FrameThread(EnvironmentManager* inEnvironmentManager, MSG* inMsg);
	static void PhysicsThread(EnvironmentManager* inEnvironmentManager, MSG* inMsg);

public:
	// Public Interface
	void JoinThreads() { for (auto& thread : threads) thread->join(); }

	// Accessors
	static ThreadManager* GetInstance(EnvironmentManager* inEnvironmentManager = nullptr, MSG* inMsg = nullptr, WindowCreator* window = nullptr);

	// Clean Up
	~ThreadManager();
};

#endif




