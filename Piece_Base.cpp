#include "Piece_Base.h"
#include "Point.h"
#include "TetrominoMatrix.h"
#include "Console.h"

#include <iostream>
#include <stdexcept>

using namespace std;

Piece_Base::Piece_Base()
{
	ResetMokhtasat();
}

Point Piece_Base::GetMokhtasat()const noexcept
{
	return Mokhtasat;
}

short Piece_Base::GetRang()const noexcept
{
	return Rang;
}

TetrominoMatrix Piece_Base::GetSafeMatrix()const noexcept
{
	return this->HalatHa[HalateAlan];
}

void Piece_Base::SetPage(const Point & _mokhtasat, short _rang)
{
	if (_rang > 256 || _rang < 0)
		throw invalid_argument("Shomareye Range Vurudie Tabe Piece_Base::SetPage() Qalat Ast.");


	InThisPageDrawIt = _mokhtasat;
	BackgColor = _rang;
}

void Piece_Base::Erase()const noexcept
{
	for (short i = 0; i < 4; i++)
	{
		for (short j = 0; j < 4; j++)
		{
			if (HalatHa[HalateAlan].Points[i][j] == true)
				Console::PrintMoraba(Point(i + Mokhtasat.x, j + Mokhtasat.y), BackgColor, InThisPageDrawIt);
		}
	}
}

void Piece_Base::Erase(short Posion)const
{
	if (Posion < 0)
		throw invalid_argument("Positione Erase(short) Mostaqel Az Mokhtasat Nemitavand Manfi Bashad.");

	int Pos = Posion * 4;
	for (short i = 0; i < 4; i++)
	{
		for (short j = 0; j < 4; j++)
		{
			if (HalatHa[HalateAlan].Points[i][j] == true)
				Console::PrintMoraba(Point(i + Pos, j), BackgColor, InThisPageDrawIt);
		}
	}

}

void Piece_Base::Draw()const noexcept
{
	for (short i = 0; i < 4; i++)
	{
		for (short j = 0; j < 4; j++)
		{
			if (HalatHa[HalateAlan].Points[i][j] == true)
				Console::PrintMoraba(Point(i + Mokhtasat.x, j + Mokhtasat.y), Rang, InThisPageDrawIt);
		}
	}
}

void Piece_Base::Draw(short Position)const
{
	if (Position < 0)
		throw invalid_argument("Positione Draw(short) Mostaqel Az Mokhtasat Nemitavand Manfi Bashad.");

	int Pos = Position * 4;
	for (short i = 0; i < 4; i++)
	{
		for (short j = 0; j < 4; j++)
		{
			if (HalatHa[HalateAlan].Points[i][j] == true)
				Console::PrintMoraba(Point(i + Pos, j), Rang, InThisPageDrawIt);
		}
	}
}

void Piece_Base::SetNowHalat(short _halat)
{
	if (_halat < 0)
		throw invalid_argument("Noe Halat Nemitavand Manfi Bashad.");

	HalateAlan = _halat % 4;
}

void Piece_Base::SetMokhtasat(short _x, short _y)noexcept
{
	Mokhtasat.x = _x;
	Mokhtasat.y = _y;
}

void Piece_Base::ResetMokhtasat()noexcept
{
	SetMokhtasat(-2, 3);
}


void Piece_Base::Move_Down()noexcept
{
	Mokhtasat.x++;
}

void Piece_Base::Move_Left()noexcept
{
	Mokhtasat.y--;
}

void Piece_Base::Move_Right()noexcept
{
	Mokhtasat.y++;
}

void Piece_Base::Rotate_Right()noexcept
{
	if (HalateAlan == 3)
		HalateAlan = 0;
	else
		HalateAlan++;
}

void Piece_Base::Rotate_Left()noexcept
{
	if (HalateAlan == 0)
		HalateAlan = 3;
	else
		HalateAlan--;
}