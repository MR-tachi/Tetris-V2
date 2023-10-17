#include "Piece_Z.h"

Piece_Z::Piece_Z()
{
	Create(2);
}

Piece_Z::Piece_Z(short _mode)
{
	Create(_mode);
}

void Piece_Z::Create(short _now)
{
	HalatHa[0].Assign(Point(1, 1), Point(0, 0), Point(0, 1), Point(1, 2));
	HalatHa[1].Assign(Point(1, 1), Point(0, 2), Point(1, 2), Point(2, 1));
	HalatHa[2] = HalatHa[0];
	HalatHa[3] = HalatHa[1];

	SetNowHalat(_now);
	//Rang = 68;
	Rang = 67;
}