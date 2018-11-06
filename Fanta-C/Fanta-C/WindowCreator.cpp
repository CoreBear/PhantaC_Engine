#pragma region Dependencies
// My Headers
#include "WindowCreator.h"			// Connection to declarations
#pragma endregion

#pragma region Initialization
WindowCreator::WindowCreator(HINSTANCE hInstance, int cmdShow, WNDPROC wndProc)
{
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);									// Size, in bytes, of this structure
	wndClass.style = CS_HREDRAW | CS_VREDRAW;								// Handles redraw if movement or size adjustment for horizontal and vertical
	wndClass.lpfnWndProc = wndProc;											// Pointer to procedure that will handle window events for any windows created using this class
	wndClass.hInstance = hInstance;											// Handle to instance of module that owns this window class. Will be passed to winMain
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);						// Handle to class cursor
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);					// Handle to brush for background painting
	wndClass.lpszMenuName = nullptr;										// Pointer to string that specifies the resource name of the class menu
	wndClass.lpszClassName = windowClassName;								// Pointer to string which uniquely identifies this window class

	RegisterClassEx(&wndClass);												// Registers window class in system

	RECT windowRect = { 0, 0, clientDimensions[1], clientDimensions[0] };	// Creates a rectcubeAngle that will be passed into the window setup

	windowHandle = CreateWindowA(windowClassName, windowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, nullptr, nullptr, hInstance, nullptr);

	ShowWindow(windowHandle, cmdShow);

	// Forces client area of the window to be painted
	UpdateWindow(windowHandle);
}
#pragma endregion