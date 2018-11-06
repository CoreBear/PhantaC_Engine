#pragma region Dependencies
// My Headers
#include "EventHandler.h"			// Connection to declarations

#include "InputManager.h"
#pragma endregion

#pragma region Global Variables
InputManager input;
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
		input.KeyPressed((ushort)wParam);
		break;
	case WM_KEYUP:
		input.KeyReleased((ushort)wParam);
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
#pragma endregion