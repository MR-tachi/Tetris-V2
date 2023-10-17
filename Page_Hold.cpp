#include "Page_Hold.h"



Page_Hold::Page_Hold()
	:Page_Base(Point(1, 1), 6, 6, 7),HoldedTetromino(nullptr)
{
}

Piece_Base * Page_Hold::Update(Piece_Base * New)
{
	New->SetPage(Point(2, 2) , GetPageColor());
	if (HoldedTetromino != nullptr)
	{
		Piece_Base * Old = HoldedTetromino;
		HoldedTetromino = New;

		return Old;
	}
	else
	{
		HoldedTetromino = New;
		return nullptr;
	}
}

void Page_Hold::DrawInside()
{
	DrawPage();
	HoldedTetromino->Draw(0);
}