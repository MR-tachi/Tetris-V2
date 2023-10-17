#pragma once
#include "Point.h"

// Abzare Khuruji
namespace Console
{
	void setcolor(short color); // SetKardane Range Matn
	void colorXY(short x, short y, short color, char* str);

	void gotoXY(short & x, short & y);
	void gotoXY(short & x, short & y, char* str);

	void PrintMoraba(const Point & Noqte, short color, const Point & Safe);

	void SetCosoleSize(short x = 1100, short y = 900);
}