#pragma region Dependencies
// System Includes
#include <Windows.h>			// Contains all destd::finitions for creating a windows based application

#include <time.h>				// For delta time

#include "InputController.h"
#include "ProgramGlobals.h"
#include "Renderer.h"
#include "SceneManager.h"

// Mouse position capture
#define GET_X_LPARAM(lp) ((int)(short)LOWORD(lp))
#define GET_Y_LPARAM(lp) ((int)(short)HIWORD(lp))
#pragma endregion

#pragma region Global Variables
HWND						windowHandle;							// Instance/Pointer to the program window
LPCSTR						windowClassName = "Fanta-CWinClass";	// Unique for the application
LPCSTR						windowName = "Fanta-C Engine";			// Name of window
InputController				inputController;
#pragma endregion

#pragma region Prototypes
int InitializeApplication(HINSTANCE hInstance, int cmdShow);
int Run(HINSTANCE hInstance, HWND windowHandle);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
#pragma endregion

#pragma region Initialization
// Application entry function
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPWSTR cmdLine, int cmdShow)
{
	UNREFERENCED_PARAMETER(prevInstance);
	UNREFERENCED_PARAMETER(cmdLine);

	// Creates main window and shows it on screen
	if (InitializeApplication(hInstance, cmdShow) != 0)
	{
		MessageBox(nullptr, TEXT("Failed to create applicaiton window."), TEXT("Error"), MB_OK);
		return -1;
	}

	// This shootingStarts the "Run" loop and only returns when the user closes the main window
	int returnCode = Run(hInstance, windowHandle);

	return returnCode;
}

int InitializeApplication(HINSTANCE hInstance, int cmdShow)
{
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);					// Size, in bytes, of this structure
	wndClass.style = CS_HREDRAW | CS_VREDRAW;				// Handles redraw if movement or size adjustment for horizontal and vertical
	wndClass.lpfnWndProc = &WndProc;						// Pointer to procedure that will handle window events for any windows created using this class
	wndClass.hInstance = hInstance;							// Handle to instance of module that owns this window class. Will be passed to winMain
	wndClass.hCursor = LoadCursor(nullptr, IDC_ARROW);		// Handle to class cursor
	wndClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);	// Handle to brush for background painting
	wndClass.lpszMenuName = nullptr;						// Pointer to string that specifies the resource name of the class menu
	wndClass.lpszClassName = windowClassName;				// Pointer to string which uniquely identifies this window class

															// If window was not registered...
	if (!RegisterClassEx(&wndClass)) return -1;

	// Creates a rectcubeAngle that will be passed into the window setup
	RECT windowRect = { 0, 0, clientDimensions[1], clientDimensions[0] };

	// Adjusts window rectcubeAngle to account for the window style
	AdjustWindowRect(&windowRect, WS_OVERLAPPEDWINDOW, FALSE);

	windowHandle = CreateWindowA(windowClassName, windowName, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
		windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, nullptr, nullptr, hInstance, nullptr);

	// If window handle was not created...
	if (!windowHandle) return -1;

	ShowWindow(windowHandle, cmdShow);

	// Forces client area of the window to be painted
	UpdateWindow(windowHandle);

	return 0;
}
#pragma endregion

#pragma region Main Loop
int Run(HINSTANCE hInstance, HWND windowHandle)
{
	constexpr double			targetedFrameCompletionTime = double(1000) / targetFPS;
	//float						deltaTime = 0;
	MSG							msg = { 0 };
	SceneManager				sceneManager(&inputController);
	Renderer					renderer(hInstance, windowHandle, sceneManager);
	time_t						endTime = 0;										
	time_t						startTime = 0;
	
	// Main application loop
	while (true)
	{
		// Retrieves the next message from the message queue
		// PM_REMOVE indicates that the retrieved message should be removed from the queue
		// Returns false if there are no messages to process
		if (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			// WM_QUIT does not need to be translated or dispatched
			if (msg.message == WM_QUIT)
				break;

			// Translate virtual-ley messages into character messages
			TranslateMessage(&msg);

			// Dispatches message to the appropriate winow's procedure function
			DispatchMessage(&msg);
		}
		else
		{
			// Stores how long it took to complet the frame
			//deltaTime = endTime - startTime;

			// Stores the time at the beginning of the frame
			//time(&startTime);

			inputController.Update();

			renderer.RenderScene();

			// Stores the time at the end of the frame
			//time(&endTime);
		}
	}

	return static_cast<int>(msg.wParam);
}
// Handles mouse, keyboard, and window events that are sent to the application
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	// Closes the window
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		inputController.KeyPressed((ushort)wParam);
		break;
	case WM_KEYUP:
		inputController.KeyReleased((ushort)wParam);
		break;
	case WM_MOUSEMOVE:
		inputController.MouseMovement(GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam));
		break;
	case WM_LBUTTONDOWN:
	case WM_RBUTTONDOWN:
		inputController.MouseButtonPressed((ushort)wParam);
		break;
	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
		inputController.MouseButtonRelease((ushort)wParam);
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
#pragma endregion