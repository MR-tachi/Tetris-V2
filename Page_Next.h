#pragma once
#include "Page_Base.h"
#include "Piece_Base.h"
#include <queue>


class Page_Next :
	public Page_Base
{
	std::queue <Piece_Base *> TetrominoHa;
	Piece_Base* NewPiece();
	short RandomNumber();
	
public:
	Page_Next();

	Piece_Base * GetTetromino();
	void DrawInside();
	void EraseInside();
};