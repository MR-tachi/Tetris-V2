#pragma once
#include "Piece_Base.h"

// Tike J
class Piece_J :
	public Piece_Base
{
public:
	Piece_J();

	Piece_J(short _mode);
	void Create(short _now)override;
};