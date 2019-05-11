#include "Encode.h"



Encode::Encode()
{
	this->height_text = 3;
	this->openDisplay_1 = true;
	this->openDisplay_2 = false;
	this->returnDisplay = false;
	this->checkWrite = true;

	arrText.push_back("  ______                     _      ");
	arrText.push_back(" |  ____|                   | |     ");
	arrText.push_back(" | |__   _ __   ___ ___   __| | ___ ");
	arrText.push_back(" |  __| | '_ \\ / __/ _ \\ / _` |/ _ \\");
	arrText.push_back(" | |____| | | | (_| (_) | (_| |  __/");
	arrText.push_back(" |______|_| |_|\\___\\___/ \__,_|\\___|");
	arrText.push_back("                                    ");
}


Encode::~Encode()
{
	delete this->huffman;
}

void Encode::draw()
{
	system("cls");
	this->textcolor(3);

	for (int i = 0; i < this->arrText.size(); i++)
	{
		Sleep(100);
		this->gotoXY(42, this->height_text++);
		std::cout << this->arrText[i] << std::endl;
	}
}

void Encode::drawChoice()
{
	this->textcolor(3);
	this->draw();
	int step = 1;
	while (!GetAsyncKeyState(VK_RETURN))
	{
		int width_1 = 45;
		int height_1 = height_text + 1;
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

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 30; j++)
			{
				if (((i == 0 && j == 0) || (i == 0 && j == 29)) || ((i == 2 && j == 0) || (i == 2 && j == 29)) || ((i == 4 && j == 0) || (i == 4 && j == 29)))
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "|";
				}
				else if (i == 0 && j == 9 && this->openDisplay_1 == false)
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "1. File Path";
					this->textcolor(3);
				}
				else if (i == 0 && j == 9 && this->openDisplay_1 == true)
				{
					this->textcolor(130);
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "1. File Path";
					this->textcolor(3);
				}
				else if (i == 2 && j == 9 && this->openDisplay_2 == true)
				{
					this->textcolor(130);
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "2. Data entry";
					this->textcolor(3);
				}
				else if (i == 2 && j == 9 && this->openDisplay_2 == false)
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "2. Data entry";
					this->textcolor(3);
				}
				else if (i == 4 && j == 9 && this->returnDisplay == true)
				{
					this->textcolor(130);
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "3. Return !";
					this->textcolor(3);
				}
				else if (i == 4 && j == 9 && this->returnDisplay == false)
				{
					this->gotoXY(width_2 + j, height_2 + i);
					std::cout << "3. Return !";
					this->textcolor(3);
				}
				else if (i == 1 || i == 3 || i == 5)
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
			if (step <= 3)
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
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			this->returnDisplay = true;
			break;
		}

		if (step == 1)
		{
			this->openDisplay_1 = true;
			this->openDisplay_2 = false;
			this->returnDisplay = false;
		}
		else if (step == 2)
		{
			this->openDisplay_1 = false;
			this->openDisplay_2 = true;
			this->returnDisplay = false;
		}
		else if (step == 3)
		{
			this->openDisplay_1 = false;
			this->openDisplay_2 = false;
			this->returnDisplay = true;
		}
	}
	this->height_text = 3;
}


void Encode::getPath()
{
	this->draw();

	int height_textData = this->height_text + 1;

	for (int i = 0; i < 80; i++)
	{
		this->gotoXY(20 + i, height_textData);
		std::cout << "=";
		this->gotoXY(20 + i, height_textData + 2);
		std::cout << "=";
	}
	for (int i = 1; i < 79; i++)
	{
		this->gotoXY(20 + i, height_textData + 1);
		std::cout << " ";
	}
	this->gotoXY(20, height_textData + 1);
	std::cout << "| Path file: ";
	this->gotoXY(99, height_textData + 1);
	std::cout << "|";

	std::string tempData;
	int tempHeight = height_textData + 1;
	int tempWidth = 33;

	while (!GetAsyncKeyState(VK_RETURN))
	{
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			this->checkWrite = false;
			break;
		}

		rewind(stdin);
		this->gotoXY(tempWidth, tempHeight);
		char c = _getch();

		if (c == 8 && !tempData.empty())
		{
			if (tempHeight != height_textData + 1 && tempWidth == 22)
			{
				this->gotoXY(tempWidth--, tempHeight);
				std::cout << " ";
				tempHeight--;
				tempWidth = 97;
			}

			this->gotoXY(tempWidth--, tempHeight);
			std::cout << " ";
			tempData.erase(tempData.end() - 1);
		}
		else if (!_kbhit())
		{
			if (!GetAsyncKeyState(VK_RETURN))
			{
				tempWidth++;
				tempData.push_back(c);
			}
		}

		for (int i = 0; i < tempData.size(); i++)
		{
			this->gotoXY(tempWidth, tempHeight);
			std::cout << tempData[i];
		}

		if (tempWidth == 97)
		{
			tempHeight++;
			tempWidth = 22;
		}
	}

	if (this->checkWrite != false)
	{
		tempData.erase(tempData.begin());
		this->pathFile = tempData;
	}
}

void Encode::display_1()
{
	bool checkFin = false;
	std::ifstream finText;

	while (checkFin == false)
	{
		this->getPath();
		if (this->checkWrite == false) break;
		finText.open(this->pathFile, std::ios_base::in);

		if (!finText)
		{
			this->textcolor(180);
			this->gotoXY(47, 15);
			std::cout << "                             ";
			this->gotoXY(47, 16);
			std::cout << "    Link does not exist !    ";
			this->gotoXY(47, 17);
			std::cout << "                             ";

			Sleep(2000);
			this->textcolor(3);
		}
		else checkFin = true;

		this->gotoXY(47, 15);
		std::cout << "                             ";
		this->gotoXY(47, 16);
		std::cout << "                             ";
		this->gotoXY(47, 17);
		std::cout << "                             ";

		this->height_text = 3;
	}

	if (checkFin == true)
	{
		while (!finText.eof())
			std::getline(finText, this->data);
	}

	finText.close();
}

void Encode::display_2()
{
	this->draw();
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
	std::string tempData;

	while (!GetAsyncKeyState(VK_RETURN))
	{	
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			this->checkWrite = false;
			break;
		}

		rewind(stdin);
		this->gotoXY(tempWidth, tempHeight);
		char c = _getch();

		if (c == 8 && !tempData.empty())
		{
			if (tempHeight != height_textData + 1 && tempWidth == 22)
			{
				this->gotoXY(tempWidth--, tempHeight);
				std::cout << " ";
				tempHeight--;
				tempWidth = 97;
			}

			this->gotoXY(tempWidth--, tempHeight);
			std::cout << " ";
			tempData.erase(tempData.end() - 1);
		}
		else if(!_kbhit())
		{
			if (!GetAsyncKeyState(VK_RETURN))
			{
				tempWidth++;
				tempData.push_back(c);
			}
		}

		for (int i = 0; i < tempData.size(); i++)
		{
			this->gotoXY(tempWidth, tempHeight);
			std::cout << tempData[i];
		}

		if (tempWidth == 97)
		{
			tempHeight++;
			tempWidth = 22;
		}
	}
	
	if (!tempData.empty())
	{
		tempData.erase(tempData.begin());
		this->data = tempData;
	}
}


void Encode::run()
{
	
	while (true)
	{
		this->drawChoice();

		if (returnDisplay == true)
		{
			system("cls");
			break;
		}

		if (this->openDisplay_1 == true)
			this->display_1();
		if (this->openDisplay_2 == true)
			this->display_2();

		if (this->checkWrite == true)
		{
			this->huffman = new Huffman(this->data);
			this->dataEncode = this->huffman->getEncode();

			std::ofstream fout("ENCODE.txt", std::ios_base::out);

			for (int i = 0; i < this->dataEncode.size(); i++) fout << this->dataEncode[i];
			this->textcolor(180);
			this->gotoXY(44, 15);
			std::cout << "                                     ";
			this->gotoXY(44, 16);
			std::cout << "    Write to file successfullyt !    ";
			this->gotoXY(44, 17);
			std::cout << "                                     ";
			this->textcolor(3);

			fout.close();
			Sleep(2000);
		}


		//reset
		this->height_text = 3;
		this->data.clear();
		this->pathFile.clear();
		this->dataEncode.clear();
		this->openDisplay_1 = true;
		this->openDisplay_2 = false;
		this->checkWrite = true;
	}
}


