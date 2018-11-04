#pragma region Dependencies
// System Headers
#include <Windows.h>			// Contains all destd::finitions for creating a windows based application

// My Headers
#include "GameManager.h"

// Leak Detection
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#pragma endregion

#pragma region Application Entry Function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	#pragma region Leak Detection
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	// this function call will set a breakpoint at the location of a leaked block
	// set the parameter to the identifier for a leaked block
	//_CrtSetBreakAlloc(266);
	#pragma endregion

	// Creates the game instance
	GameManager gameManager(hInstance, cmdShow);
	return 0;
}
#pragma endregion