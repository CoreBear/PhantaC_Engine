#pragma region Dependencies
// System Headers
#include <Windows.h>			// Contains all destd::finitions for creating a windows based application

// My Headers
#include "GameController.h"
#pragma endregion

#pragma region Application Entry Function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	// Creates the game instance
	GameController gameController(hInstance, cmdShow);
	return 0;
}
#pragma endregion