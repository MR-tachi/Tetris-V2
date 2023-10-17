#include "Piece_I.h"

Piece_I::Piece_I()
{
	Create(3);
}

Piece_I::Piece_I(short _mode)
{
	Create(_mode);
}

void Piece_I::Create(short _now)
{
	HalatHa[0].Assign(Point(0, 1), Point(1, 1), Point(2, 1), Point(3, 1));
	HalatHa[1].Assign(Point(1, 0), Point(1, 1), Point(1, 2), Point(1, 3));
	HalatHa[2] = HalatHa[0];
	HalatHa[3] = HalatHa[1];

	SetNowHalat(_now);
	//Rang = 187;
	Rang = 185;
}