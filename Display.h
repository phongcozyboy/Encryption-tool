#pragma once
#include <iostream>
#include <fstream>
#include <Windows.h>
#include "Encode.h"
#include "Something.h"

class Display
{
private:
	// Hàm dịch chuyển con trỏ đến tọa độ x, y.
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
	Encode encode;
	Something message;
	bool openEncode;
	bool openDecode;
	bool something;
	bool quit;
	std::vector<std::string> arrText;

	void draw();
public:

	Display();
	~Display();

	void run();
};

