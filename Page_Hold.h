#pragma once
#include "Page_Base.h"
#include "Piece_Base.h"

class Page_Hold :
	public Page_Base
{
private:
	Piece_Base* HoldedTetromino;

public:
	Page_Hold();

	Piece_Base* Update(Piece_Base * New);
	void DrawInside();
};