#pragma region Dependencies
// My Headers
#include "WindowCreator.h"			// Connection to declarations

using namespace Application_Level;
#pragma endregion

#pragma region Forward Declarations
WindowCreator* WindowCreator::windowCreatorInstance = nullptr;
#pragma endregion

#pragma region Initialization
WindowCreator::WindowCreator(HINSTANCE hInstance, int cmdShow, WNDPROC wndProc)
	: windowClassName("Fanta-C"), windowName("Fanta-C Engine"), clientDimensions{720, 1280}
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

	RECT windowRect = { 0, 0, clientDimensions[1], clientDimensions[0] };	// Creates a rectangle for the window that will be passed into the window setup

	// Creates and assigns the window handlw
	windowHandle = CreateWindowA(windowClassName, windowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, nullptr, nullptr, hInstance, nullptr);

	// Shows the window
	ShowWindow(windowHandle, cmdShow);

	// Forces client area of the window to be painted
	UpdateWindow(windowHandle);
}
WindowCreator* WindowCreator::GetInstance(HINSTANCE hInstance, int cmdShow, WNDPROC wndProc)
{
	// If there is already and instance, return it
	if (windowCreatorInstance) return windowCreatorInstance;
	
	// If there isn't already an instance, create one and return it
	else
	{
		windowCreatorInstance = new WindowCreator(hInstance, cmdShow, wndProc);
		return windowCreatorInstance;
	}
}
#pragma endregion