#ifndef _WINDOW_CREATION_H
#define _WINDOW_CREATION_H

// System Headers
#include <windows.h>
#include <string>
// My Headers
#include "GlobalTypedefs.h"

class WindowCreator
{
	HWND	windowHandle;							// Instance/Pointer to the program window
	LPCSTR	windowClassName = "Fanta-CWinClass";	// Unique for the application
	LPCSTR	windowName = "Fanta-C Engine";			// Name of window
	ushort	clientDimensions[2] = { 720, 1280 };	// Index 0 - Height. 1 - Width	

public:
	// Initialization
	WindowCreator(HINSTANCE hInstance, int cmdShow, WNDPROC wndProc);

	// Accessors
	HWND GetWindowHandle() { return windowHandle; }
	ushort* GetClientDimensions() { return clientDimensions; }
};

#endif