#pragma once
#include "Piece_Base.h"

// Tike O
class Piece_O :
	public Piece_Base
{
public:
	Piece_O();

	Piece_O(short _mode);
	void Create(short _now)override;
};