#pragma once
#include "Piece_Base.h"

// Tike L
class Piece_L :
	public Piece_Base
{
public:
	Piece_L();

	Piece_L(short _mode);
	void Create(short _now)override;
};