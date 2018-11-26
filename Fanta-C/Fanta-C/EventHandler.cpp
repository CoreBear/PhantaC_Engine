#pragma region Dependencies
// My Headers
#include "EventHandler.h"			// Connection to declarations

#include "GlobalInput.h"

// Defines
// Mouse position capture
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))
#pragma endregion

#pragma region Global Variables
bool GlobalInput::keysCurrentlyPressed[11];
#pragma endregion

#pragma region Private

void EventHandler::ControllerInput()
{

}
#pragma endregion