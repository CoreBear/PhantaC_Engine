#ifndef _EVENT_HANDLER_H
#define _EVENT_HANDLER_H

// System Headers
#include <Windows.h>

// My Headers
#include "GlobalTypedefs.h"
#include "InputManager.h"

class EventHandler
{
	InputManager* input;

	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	static void KeyPressed(ushort keyPressed);
	static void KeyReleased(ushort keyReleased);
	static void MouseButtonPressed(ushort buttonPressed);
	static void MouseButtonRelease(ushort buttonReleased);
	static void MouseMovement(ushort xPosition, ushort yPosition);

public:
	// Initialization
	EventHandler(InputManager* inInput) { input = inInput; }

	// Update
	void Update();

	// Accessors
	WNDPROC GetWndProc() { return &WndProc; }
};

#endif