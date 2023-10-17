#pragma once
#include "Piece_Base.h"

// Tike S
class Piece_S :
	public Piece_Base
{
public:
	Piece_S();

	Piece_S(short _mode);
	void Create(short _now)override;
};