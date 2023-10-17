#include "Page_Next.h"
#include <random>
#include <ctime>

#include "Piece_Base.h"
#include "Piece_I.h"
#include "Piece_J.h"
#include "Piece_L.h"
#include "Piece_O.h"
#include "Piece_S.h"
#include "Piece_T.h"
#include "Piece_Z.h"

Piece_Base * Page_Next::NewPiece()
{
	Piece_Base* Temp;

	switch (RandomNumber())
	{
	case 0: Temp = new Piece_I; break;
	case 1: Temp = new Piece_J; break;
	case 2: Temp = new Piece_L; break;
	case 3: Temp = new Piece_O; break;
	case 4: Temp = new Piece_S; break;
	case 5: Temp = new Piece_T; break;
	case 6: Temp = new Piece_Z; break;
	}

	return Temp;
}

short Page_Next::RandomNumber()
{
	return rand() % 7;
}

Page_Next::Page_Next()
	: Page_Base(Point(1, 19), 20, 6 , 7)
{
	srand((unsigned int)time(0));

	for (size_t i = 0; i < 4; ++i)
		TetrominoHa.push(NewPiece());
}

Piece_Base * Page_Next::GetTetromino()
{
	TetrominoHa.push(NewPiece());
	Piece_Base* ToReturn = TetrominoHa.front();
	TetrominoHa.pop();

	return ToReturn ;
}

void Page_Next::DrawInside()
{
	std::queue <Piece_Base *> ToDraw(TetrominoHa);
	Piece_Base * TmpToDraw = nullptr;

	for (short i = 0; i < 4; ++i)
	{
		TmpToDraw = ToDraw.front();
		ToDraw.pop();
		TmpToDraw->SetPage(Point(2, 20) , GetPageColor());
		TmpToDraw->Draw(i);
	}
}

void Page_Next::EraseInside()
{
	std::queue <Piece_Base *> ToDraw(TetrominoHa);
	Piece_Base * TmpToDraw = nullptr;

	for (short i = 0; i < 4; ++i)
	{
		TmpToDraw = ToDraw.front();
		ToDraw.pop();
		TmpToDraw->SetPage(Point(2, 20) , GetPageColor());
		TmpToDraw->Erase(i);
	}
}