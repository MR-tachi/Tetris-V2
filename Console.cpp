#include "Console.h"

#include <iostream>
#include <Windows.h>
#include <direct.h>
using namespace std;

void Console::setcolor(short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}

void Console::colorXY(short x, short y, short color, char* str)
{
	Console::setcolor(color);
	Console::gotoXY(x, y, str);
}

void Console::gotoXY(short & y, short & x)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Console::gotoXY(short & x, short & y, char* str)
{
	gotoXY(x, y);
	cout << str;
}

void Console::PrintMoraba(const Point & Noqte, short color, const Point & Safe)
{
	if (Noqte.x < 0)
		return;

	unsigned short ZaribX = (Noqte.x + Safe.x) * 2;
	unsigned short ZaribY = (Noqte.y + Safe.y) * 5;

	Console::colorXY(0 + ZaribX, 0 + ZaribY, color, "    ");
	Console::colorXY(1 + ZaribX, 1 + ZaribY, color, "    ");
	Console::colorXY(0 + ZaribX, 1 + ZaribY, color, "    ");
	Console::colorXY(1 + ZaribX, 0 + ZaribY, color, "    ");

	Console::setcolor(7);
}


void Console::SetCosoleSize(short x, short y)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions

								//MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, r.left, r.top, x, y, TRUE);
}
