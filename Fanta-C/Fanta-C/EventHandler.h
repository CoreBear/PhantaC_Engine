#ifndef _EVENT_HANDLER_H
#define _EVENT_HANDLER_H

// System Headers
#include <Windows.h>

// My Headers
#include "GlobalTypedefs.h"

class EventHandler
{
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
	static void KeyPressed(ushort keyPressed);
	static void KeyReleased(ushort keyReleased);
	static void MouseButtonPressed(ushort buttonPressed);
	static void MouseButtonRelease(ushort buttonReleased);
	static void MouseMovement(ushort xPosition, ushort yPosition);
	static void ControllerInput();

public:
	// Accessors
	WNDPROC GetWndProc() { return &WndProc; }
};

#endif