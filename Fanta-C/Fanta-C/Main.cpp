#pragma region Dependencies
// System Headers
#include <Windows.h>			// Contains all destd::finitions for creating a windows based application

// My Headers
#include "GameManager.h"
#pragma endregion

#pragma region Application Entry Function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	// Creates the game instance
	GameManager gameManager(hInstance, cmdShow);
	return 0;
}
#pragma endregion