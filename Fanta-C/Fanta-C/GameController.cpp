#pragma region Dependencies
// My Headers
#include "GameController.h"			// Connection to declarations
#include "GameState.h"
#include "InputController.h"
#include "Renderer.h"
#include "SceneManager.h"
#pragma endregion

// Do this better
static InputController inputController;			// This has to be static, because wndProc is static

#pragma region Initialization
GameController::GameController(HINSTANCE hInstance, int cmdShow)
{
	// Creates main window instance
	InitializeWindow(hInstance, cmdShow);

	// Creates the game's state machine
	currentState = availableStates[0] = new GameRunning(this);
	availableStates[1] = new GamePaused;

	// Loads the scene manager
	sceneManagerPtr = new SceneManager(&inputController, clientDimensions);

	// Loads the render
	rendererPtr = new Renderer(windowHandle, sceneManagerPtr, clientDimensions, targetFPS);

	// Starts the game loop
	ApplicationLoop();
}
void GameController::InitializeWindow(HINSTANCE hInstance, int cmdShow)
{
	WNDCLASSEX wndClass = { 0 };
	wndClass.cbSize = sizeof(WNDCLASSEX);									// Size, in bytes, of this structure
	wndClass.style = CS_HREDRAW | CS_VREDRAW;								// Handles redraw if movement or size adjustment for horizontal and vertical
	wndClass.lpfnWndProc = &WndProc;										// Pointer to procedure that will handle window events for any windows created using this class
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

#pragma region Update
void GameController::ApplicationLoop()
{
	MSG							msg = { 0 };	// Container that stores system messages

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
			// Stores how long it took to complete the frame
			chronoDelta = endTime - startTime;
			deltaTime = chronoDelta.count();

			// Stores the time at the beginning of the frame
			startTime = std::chrono::steady_clock::now();

			// User input
			inputController.Update(deltaTime);

			// Call game controller's state machine
			currentState->UpdateState(deltaTime);

			// Stores the time at the end of the frame
			endTime = std::chrono::steady_clock::now();
		}
	}
}
void GameController::MainGameUpdate(float deltaTime)
{
	sceneManagerPtr->Update(deltaTime);
	rendererPtr->Update(sceneManagerPtr->GetvisibleSceneObjects(), sceneManagerPtr->GetCamera());
}
#pragma endregion

#pragma region System Input
LRESULT CALLBACK GameController::WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
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
		/*case WM_MOUSEMOVE:
		inputController.MouseMovement((ushort)lParam, (ushort)lParam);
		break;
		case WM_LBUTTONDOWN:
		case WM_RBUTTONDOWN:
		inputController.MouseButtonPressed((ushort)wParam);
		break;
		case WM_LBUTTONUP:
		case WM_RBUTTONUP:
		inputController.MouseButtonRelease((ushort)wParam);
		break;*/
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}

	return 0;
}
#pragma endregion