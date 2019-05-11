#include "Something.h"



Something::Something()
{
	this->messager =
		"Hi, i'm phongle\n as a student and an amateur programmer who created this small encryption\n software in my spare time, and some features are not yet complete but\n are about to be completed by the time Next time, but I'm not sure when ^^.";
	this->height_text = 3;
}


Something::~Something()
{
}


void Something::run()
{
	this->textcolor(3);
	int height_textData = this->height_text + 1;
	for (int i = 0; i < 80; i++)
	{
		this->gotoXY(20 + i, height_textData);
		std::cout << "=";
		this->gotoXY(20 + i, height_textData + 15);
		std::cout << "=";
	}
	for (int i = 0; i < 15; i++)
	{
		this->gotoXY(20, height_textData + i);
		std::cout << "|";
		this->gotoXY(99, height_textData + i);
		std::cout << "|";
	}
	int tempHeight = height_textData + 1;
	int tempWidth = 22;

	this->gotoXY(tempWidth, tempHeight);
	for (int i = 0; i < this->messager.size(); i++)
	{
		
		std::cout << this->messager[i];
		Sleep(50);

		if (this->messager[i] == '\n')
			this->gotoXY(tempWidth + 2, ++tempHeight);
		if (this->messager[i] == '\n' && this->messager[i - 1] == 'e')
		{
			tempHeight += 2;
			this->gotoXY(tempWidth + 2, tempHeight);
		}
		
	}

	this->gotoXY(65, 14);
	std::cout << "Developed by";
	int color = 1;


	while (true)
	{
		if (color == 7) color = 1;
		this->gotoXY(78, 14);			
		this->textcolor(color++);
		std::cout << "< realphongle >";
		Sleep(100);

		this->textcolor(3);

		if (GetAsyncKeyState(VK_ESCAPE) || GetAsyncKeyState(VK_RETURN))  break;
	}
}