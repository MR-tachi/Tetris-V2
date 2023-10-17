#pragma once
#include "Piece_Base.h"

// Tile T
class Piece_T :
	public Piece_Base
{
public:
	Piece_T();

	Piece_T(short _mode);
	void Create(short _now)override;
};