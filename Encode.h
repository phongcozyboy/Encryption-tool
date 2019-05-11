#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <Windows.h>
#include <stdio.h>
#include "Huffman.h"

class Encode
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
	int height_text;
	bool choice;
	bool openDisplay_1;
	bool openDisplay_2;
	bool checkWrite;
	bool returnDisplay;
	std::string data;
	std::string pathFile;
	std::string dataEncode;
	std::vector<std::string> arrText;
	Huffman *huffman;

	void drawChoice();
	void draw();
	
	void getPath();
	void display_1();
	void display_2();
public:
	Encode();
	~Encode();

	void run();
};

