#include "Piece_T.h"

Piece_T::Piece_T()
{
	Create(0);
}

Piece_T::Piece_T(short _mode)
{
	Create(_mode);
}

void Piece_T::Create(short _now)
{
	HalatHa[0].Assign(Point(1, 0), Point(0, 1), Point(1, 2), Point(1, 1));
	HalatHa[1].Assign(Point(0, 1), Point(1, 2), Point(2, 1), Point(1, 1));
	HalatHa[2].Assign(Point(1, 0), Point(1, 2), Point(2, 1), Point(1, 1));
	HalatHa[3].Assign(Point(0, 1), Point(1, 0), Point(2, 1), Point(1, 1));

	SetNowHalat(_now);
	//Rang = 221;
	Rang = 215;
}