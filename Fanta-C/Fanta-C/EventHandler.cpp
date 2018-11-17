#pragma region Dependencies
// My Headers
#include "EventHandler.h"			// Connection to declarations

// Defines
// Mouse position capture
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))
#pragma endregion

#pragma region Global Variables
static bool	keysCurrentlyPressed[11];
#pragma endregion

#pragma region Update
void EventHandler::Update() { input->Update(keysCurrentlyPressed); }
#pragma endregion

#pragma region Private
LRESULT CALLBACK EventHandler::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		// Closes the window
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		KeyPressed((ushort)wParam);
		break;
	case WM_KEYUP:
		KeyReleased((ushort)wParam);
		break;
	/*case WM_MOUSEMOVE:
		input.MouseMovement((ushort)lParam, (ushort)lParam);
		break;
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
		input.MouseButtonPressed((ushort)wParam);
		break;
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
		input.MouseButtonRelease((ushort)wParam);
		break;*/
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
void EventHandler::KeyPressed(ushort keyPressed)
{
	// Add more to each switch for "Pushed this frame"
	switch (keyPressed)
	{
	case A:
		keysCurrentlyPressed[0] = true;
		break;
	case D:
		keysCurrentlyPressed[1] = true;
		break;
	case I:
		keysCurrentlyPressed[2] = true;
		break;
	case J:
		keysCurrentlyPressed[3] = true;
		break;
	case K:
		keysCurrentlyPressed[4] = true;
		break;
	case L:
		keysCurrentlyPressed[5] = true;
		break;
	case S:
		keysCurrentlyPressed[6] = true;
		break;
	case W:
		keysCurrentlyPressed[7] = true;
		break;
	case SPACE:
		keysCurrentlyPressed[8] = true;
		break;
	case Key1:
		keysCurrentlyPressed[9] = true;
		break;
	case Key2:
		keysCurrentlyPressed[10] = true;
		break;
	default:
		break;
	}
}
void EventHandler::KeyReleased(ushort keyReleased)
{
	// Add more to each switch for "Released this frame"
	switch (keyReleased)
	{
	case A:
		keysCurrentlyPressed[0] = false;
		break;
	case D:
		keysCurrentlyPressed[1] = false;
		break;
	case I:
		keysCurrentlyPressed[2] = false;
		break;
	case J:
		keysCurrentlyPressed[3] = false;
		break;
	case K:
		keysCurrentlyPressed[4] = false;
		break;
	case L:
		keysCurrentlyPressed[5] = false;
		break;
	case S:
		keysCurrentlyPressed[6] = false;
		break;
	case W:
		keysCurrentlyPressed[7] = false;
		break;
	case SPACE:
		keysCurrentlyPressed[8] = false;
		break;
	case Key1:
		keysCurrentlyPressed[9] = false;
		break;
	case Key2:
		keysCurrentlyPressed[10] = false;
		break;
	default:
		break;
	}
}
void EventHandler::MouseButtonPressed(ushort buttonPressed)
{

}
void EventHandler::MouseButtonRelease(ushort buttonReleased)
{

}
void EventHandler::MouseMovement(ushort xPosition, ushort yPosition)
{
	//GET_X_LPARAM(lParam);
}
#pragma endregion