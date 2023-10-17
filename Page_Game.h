#pragma once
#include "Page_Base.h"
#include "Point.h"
#include "Piece_Base.h"
#include "Console.h"

class Page_Game :
	public Page_Base
{
private:
	short MatriseSaken[20][10];
	Piece_Base * MovingTetromino;
	bool isSakenValue;
	
public:
	Page_Game();

	void NewTetrominoInput(Piece_Base *);
	bool isSaken();
	Piece_Base * GetOutTetromino();
	void DrawSakenPieces();

	bool isBlockFree(short, short);
	bool TestForMove(Piece_Base *);
	void NoInput();
	void Move_Right_Piece();
	void Move_Left_Piece();
	bool Move_Down_Piece();
	void Rotate_Right_Piece();
	void Rotate_Left_Piece();
	short Move_HardDrop();

	bool isThisLineFull(short);
	short LineChecker();
	void EraseLines(short);
	void SwipLines(short);

	bool isGameOver();
};

