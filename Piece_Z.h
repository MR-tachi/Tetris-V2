#pragma once
#include "Piece_Base.h"

// Tike Z
class Piece_Z :
	public Piece_Base
{
public:
	Piece_Z();

	Piece_Z(short _mode);
	void Create(short _now)override;
};