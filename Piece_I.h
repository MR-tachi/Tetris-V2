#pragma once
#include "Piece_Base.h"

// TIke I
class Piece_I :
	public Piece_Base
{
public:
	Piece_I();

	Piece_I(short _mode);
	void Create(short _now)override;
};