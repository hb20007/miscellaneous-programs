/**
 * ColoredTextDisplay.h
 * Purpose: Display a given text with given colors
 *
 * @author Lapious  (Adjustment for function)
 * @author vegaseat (Coloring Text)
 * @reference https://www.daniweb.com/software-development/cpp/code/216345/add-a-little-color-to-your-console-text
 * @version 1.0 25/2/2015
 */

#include <iostream>
#include <windows.h> // WinApi header

// Colors used by the 
enum ColorNames
{
	Transparent = 0,
	DarkBlue = 1,
	DarkGreen = 2,
	DarkTeal = 3,
	DarkRed = 4,
	DarkPink = 5,
	DarkYellow = 6,
	Gray = 7,
	DarkGray = 8,
	Blue = 9,
	Green = 10,
	Teal = 11,
	Red = 12,
	Pink = 13,
	Yellow = 14,
	White = 15
};

/**
 *	Displays the given text with the given background and foreground colors

 *	@param text The actual text to be displayed.
 *	@param BackgroundColor The background color for the given text
 *	@param ForegroundColor The foreground color for the given text.
 */
template<typename T>
void DisplayWithColor(T valueToDisplay, ColorNames BackgroundColor, ColorNames ForegroundColor)
{
	HANDLE  hConsole;

	// Convert the color numbers into single equivalent decimal value
	int color = (int)BackgroundColor * 16 + (int)ForegroundColor;

	// Get the console output handle
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, color);

	std::cout << valueToDisplay;
}

void ResetDisplayColor()
{
	DisplayWithColor("", Transparent, Gray);
}
