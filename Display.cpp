#include "Display.h"


Display::Display()
{
	this->openEncode = true;
	this->openDecode = false;
	this->quit = false;
	this->something = false;

	this->arrText.push_back("  _  ___     _   ______                             _   ");
	this->arrText.push_back(" | |/ (_)   | | |  ____|                           | |  ");
	this->arrText.push_back(" | ' / _  __| | | |__   _ __   ___ _ __ _   _ _ __ | |_ ");
	this->arrText.push_back(" |  < | |/ _` | |  __| | '_ \\ / __| '__| | | | '_ \\| __|");
	this->arrText.push_back(" | . \\| | (_| | | |____| | | | (__| |  | |_| | |_) | |_ ");
	this->arrText.push_back(" |_|\\_\\_|\\__,_| |______|_| |_|\\___|_|   \\__, | .__/ \\__|");
	this->arrText.push_back("                                         __/ | |        ");
	this->arrText.push_back("                                        |___/|_|        ");
}


Display::~Display()
{
}

void Display::draw()
{
	int height_2text = 3;
	this->textcolor(3);
	
	for (int i = 0; i < this->arrText.size(); i++)
	{
		Sleep(100);
		this->gotoXY(36, height_2text++);
		std::cout << this->arrText[i] << std::endl;
	}

	int step = 1;

	while (!GetAsyncKeyState(VK_RETURN))
	{
		this->clear();
		this->textcolor(3);
		int width_1 = 45;
		int height_1;

		height_1 = height_2text + 1;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (i == 0 || i == 2)
				{
					this->gotoXY(width_1 + j, height_1 + i);
					std::cout << "=";
				}
				else if ((i == 1 && j == 0) || (i == 1 && j == 29))
				{
					this->gotoXY(width_1 + j, height_1 + i);
					std::cout << "|";
				}
				else if (i == 1 && j == 9)
				{
					this->gotoXY(width_1 + j, height_1 + i);
					std::cout << "YOUR CHOICE ?";
				}
			}
			std::cout << std::endl;
			width_1 = 45;
		}
		int width_2 = 45;
		int height_2 = height_1 + 3;

		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (((i == 0 && j == 0) || (i == 0 && j == 29)) || ((i == 2 && j == 0) 
					|| (i == 2 && j == 29)) || ((i == 4 && j == 0) || (i == 4 && j == 29)) || ((i == 6 && j == 0) || (i == 6 && j == 29)))
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "|";
				}
				else if (i == 0 && j == 9 && this->openEncode == false)
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "1. Encode";
					this->textcolor(3);
				}
				else if (i == 0 && j == 9 && this->openEncode == true)
				{
					this->textcolor(130);
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "1. Encode";
					this->textcolor(3);
				}
				else if (i == 2 && j == 9 && this->openDecode == true)
				{
					this->textcolor(130);
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "2. Decode";
					this->textcolor(3);
				}
				else if (i == 2 && j == 9 && this->openDecode == false)
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "2. Decode";
					this->textcolor(3);
				}
				else if (i == 4 && j == 9 && this->something == true)
				{
					this->textcolor(130);
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "3. Something";
					this->textcolor(3);
				}
				else if (i == 4 && j == 9 && this->something == false)
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "3. Something";
					this->textcolor(3);
				}
				else if (i == 6 && j == 9 && this->quit == true)
				{
					this->textcolor(130);
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "4. Quit !";
					this->textcolor(3);
				}
				else if (i == 6 && j == 9 && this->quit == false)
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "4. Quit !";
					this->textcolor(3);
				}
				else if (i == 1 || i == 3 || i == 5 || i == 7)
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "=";
				}
			}
			std::cout << std::endl;
			width_2 = 45;
		}

		if (GetAsyncKeyState(VK_DOWN))
		{
			if (step <= 4)
			{
				step++;
				Sleep(80);
			}
		}
		if (GetAsyncKeyState(VK_UP))
		{
			if (step >= 1)
			{
				step--;
				Sleep(80);
			}
		}

		if (step == 1)
		{
			this->openDecode = false;
			this->openEncode = true;
			this->something = false;
			this->quit = false;
		}
		else if (step == 2)
		{
			this->openDecode = true;
			this->openEncode = false;
			this->something = false;
			this->quit = false;
		}
		else if (step == 3)
		{
			this->openDecode = false;
			this->openEncode = false;
			this->something = true;
			this->quit = false;
		}
		else if (step == 4)
		{
			this->openDecode = false;
			this->openEncode = false;
			this->something = false;
			this->quit = true;
		}
	}
}

void Display::run()
{
	while (true)
	{
		this->draw();

		if (this->openDecode == true)
		{
			this->textcolor(180);
			this->gotoXY(47, 15);
			std::cout << "                             ";
			this->gotoXY(47, 16);
			std::cout << "        COMING SOON !        ";
			this->gotoXY(47, 17);
			std::cout << "                             ";
			this->textcolor(3);
			Sleep(2000);

			system("cls");
		}
		else if (this->openEncode == true)
		{
			system("cls");
			this->encode.run();
		}
		else if (this->something == true)
		{
			system("cls");
			this->message.run();
			this->something = false;
			system("cls");
		}
		else exit(0);
	}
}
