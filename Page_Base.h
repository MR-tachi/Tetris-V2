#pragma once
#include "Point.h"

class Page_Base
{
private:
	// Makane Safe
	Point Mokhtasat;
	short TedadSatr;
	short TedadSutun;

	// Rang Bandie Safe
	short BackgColor;

public:
	Page_Base();
	Page_Base(const Point & _Mokhtasat, short _Satr, short _Sutun, short _BackgColor);

	// Chaape Safe
	void DrawPage()const noexcept;
	short GetPageColor() const noexcept;
};