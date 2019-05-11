#include <iostream>
#include "Display.h"

void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

int main()
{
	Display e;
	e.run();

	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}