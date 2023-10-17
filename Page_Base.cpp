#include "Page_Base.h"
#include "Console.h"


Page_Base::Page_Base()
{
}

Page_Base::Page_Base(const Point & _Mokhtasat, short _Satr, short _Sutun, short _BackgColor)
	:TedadSatr(_Satr), TedadSutun(_Sutun), Mokhtasat(_Mokhtasat), BackgColor(_BackgColor)
{
}



void Page_Base::DrawPage()const noexcept
{
	for (short i = 0; i<TedadSatr; ++i)
		for (short j = 0; j < TedadSutun; ++j)
		{
			Console::PrintMoraba(Mokhtasat, BackgColor, Point(i, j));
		}
}

short Page_Base::GetPageColor() const noexcept
{
	return BackgColor;
}
