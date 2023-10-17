#include "Piece_O.h"

Piece_O::Piece_O()
{
	Create(0);
}

Piece_O::Piece_O(short _mode)
{
	Create(_mode);
}

void Piece_O::Create(short _now)
{
	HalatHa[0].Assign(Point(1, 1), Point(1, 2), Point(2, 1), Point(2, 2));
	HalatHa[1] = HalatHa[2] = HalatHa[3] = HalatHa[0];

	SetNowHalat(_now);
	//Rang = 238;
	Rang = 239;
}
