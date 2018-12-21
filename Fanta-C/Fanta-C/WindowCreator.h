#ifndef _WINDOW_CREATION_H
#define _WINDOW_CREATION_H

// System Headers
#include <windows.h>
#include <string>

// My Headers
#include "GlobalTypedefs.h"

class WindowCreator
{
	// Variables
	HWND					windowHandle;			// Instance/Pointer to the program window
	LPCSTR					windowClassName;		// Unique for the application
	LPCSTR					windowName;				// Name of window
	ushort					clientDimensions[2];	// Index 0 - Height. 1 - Width	
	static WindowCreator*	windowCreatorInstance;

	// Initialization
	WindowCreator(HINSTANCE hInstance, int cmdShow, WNDPROC wndProc);
	WindowCreator(WindowCreator const&) = delete;
	WindowCreator& operator=(WindowCreator const&) = delete;

public:
	// Initialization
	static WindowCreator* GetInstance(HINSTANCE hInstance, int cmdShow, WNDPROC wndProc);

	// Accessors
	HWND* GetWindowHandle() { return &windowHandle; }
	ushort* GetClientDimensions() { return clientDimensions; }
};

#endif