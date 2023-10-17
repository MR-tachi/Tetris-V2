#include "Piece_J.h"

Piece_J::Piece_J()
{
	Create(0);
}

Piece_J::Piece_J(short _mode)
{
	Create(_mode);
}

void Piece_J::Create(short _now)
{
	HalatHa[0].Assign(Point(1, 1), Point(2, 0), Point(2, 1), Point(0, 1));
	HalatHa[1].Assign(Point(1, 1), Point(0, 0), Point(1, 0), Point(1, 2));
	HalatHa[2].Assign(Point(1, 1), Point(0, 1), Point(0, 2), Point(2, 1));
	HalatHa[3].Assign(Point(1, 1), Point(1, 0), Point(1, 2), Point(2, 2));

	SetNowHalat(_now);
	//Rang = 153;
	Rang = 031;
}