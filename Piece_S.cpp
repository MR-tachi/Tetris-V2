#include "Piece_S.h"

Piece_S::Piece_S()
{
	Create(0);
}

Piece_S::Piece_S(short _mode)
{
	Create(_mode);
}

void Piece_S::Create(short _now)
{
	HalatHa[0].Assign(Point(1, 1), Point(1, 0), Point(0, 1), Point(0, 2));
	HalatHa[1].Assign(Point(1, 1), Point(0, 1), Point(1, 2), Point(2, 2));
	HalatHa[2] = HalatHa[0];
	HalatHa[3] = HalatHa[1];

	SetNowHalat(_now);
	//Rang = 170;
	Rang = 167;
}