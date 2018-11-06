#ifndef _EVENT_HANDLER_H
#define _EVENT_HANDLER_H

// System Headers
#include <Windows.h>

class EventHandler
{
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	// Accessors
	WNDPROC GetWndProc() { return &WndProc; }
};

#endif