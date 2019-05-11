#pragma once
#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>

class Something
{
private:
	std::string messager;
	int height_text;

	void gotoXY(int cot, int dong)
	{
		HANDLE hConsoleOutput;
		COORD Cursor_an_Pos = { cot - 1,dong - 1 };
		hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
	}
	void clear()
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD coordScreen = { 0, 0 };
		DWORD cCharsWritten;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD dwConSize = NULL;

		GetConsoleScreenBufferInfo(hConsole, &csbi);
		FillConsoleOutputCharacter(hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten);
		GetConsoleScreenBufferInfo(hConsole, &csbi);
		FillConsoleOutputAttribute(hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten);
		SetConsoleCursorPosition(hConsole, coordScreen);
		return;
	}
	void textcolor(int x)
	{
		HANDLE mau;
		mau = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(mau, x);
	}

public:
	Something();
	~Something();

	void run();
};

