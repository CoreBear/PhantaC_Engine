#ifndef _GLOBAL_CONSOLE_WRITE_H
#define _GLOBAL_CONSOLE_WRITE_H

// System Headers
#include <string>
#include <Windows.h>

class GlobalConsoleWrite
{
public:
	// Variables
	static HWND* handle;
	static std::string conversionString;
	static const char* conversionChar;

	template<typename Generic> static void ConvertNumberToString(Generic value) { conversionString = std::to_string(value); }
	static void ConvertStringToCharPtr() { conversionChar = conversionString.c_str(); }
	static void WriteToConsole(const char* text) { SetWindowText(*handle, text); }
	template<typename Generic> static void WriteToConsole(Generic value) 
	{
		conversionString = std::to_string(value);
		conversionChar = conversionString.c_str();
		SetWindowText(*handle, conversionChar);
	}
};

#endif
