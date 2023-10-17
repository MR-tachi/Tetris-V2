#include "Page_Game.h"
#include <conio.h>
#include "TetrominoMatrix.h"
#include "Point.h"
#include <iostream>
#include <vector>

using namespace std;

Page_Game::Page_Game()
	:Page_Base(Point(1, 8), 20, 10 , 7),isSakenValue(true),MovingTetromino(nullptr)
{
	for (short i = 0; i < 20; i++)
		for (short j = 0; j < 10; j++)
		{
			MatriseSaken[i][j] = 0;
		}
}

void Page_Game::NewTetrominoInput(Piece_Base * _New)
{
	if (MovingTetromino != nullptr)
	{
		Point MokhtasatTetromino = MovingTetromino->GetMokhtasat();
		TetrominoMatrix Matrixe_4_4 = MovingTetromino->GetSafeMatrix();

		for (short i = 0; i < 4; i++)
		{
			for (short j = 0; j < 4; j++)
			{
				if (Matrixe_4_4.Points[i][j] == true)
					MatriseSaken[i + MokhtasatTetromino.x][j + MokhtasatTetromino.y] = MovingTetromino->GetRang();
			}
		}

		delete MovingTetromino;
	}

	_New->SetPage(Point(1, 8), GetPageColor());
	MovingTetromino = _New;
	isSakenValue = false;
}

void Page_Game::NoInput()
{
	Move_Down_Piece();
}

void Page_Game::Move_Right_Piece()
{
	MovingTetromino->Erase();

	MovingTetromino->Move_Right(); // Teste Nesbat Be Safhe Ye Dor
	{
		if (!TestForMove(MovingTetromino)) // Test Nesbat Be Tet Haye Qadimi
			MovingTetromino->Move_Left();
	}
	MovingTetromino->Draw();
}

void Page_Game::Move_Left_Piece()
{
	MovingTetromino->Erase();

	MovingTetromino->Move_Left(); // Teste Nesbat Be Safhe Ye Dor
	{
		if (!TestForMove(MovingTetromino)) // Test Nesbat Be Tet Haye Qadimi
			MovingTetromino->Move_Right();
	}
	MovingTetromino->Draw();
}

bool Page_Game::Move_Down_Piece()
{
	MovingTetromino->Erase();
	bool isOk = true;
	MovingTetromino->Move_Down(); // Teste Nesbat Be Safhe Ye Dor

	if (!TestForMove(MovingTetromino)) // Test Nesbat Be Tet Haye Qadimi
	{
		isSakenValue = true;
		isOk = false;
	}

	MovingTetromino->Draw();
	return isOk;
}

void Page_Game::Rotate_Right_Piece()
{
	MovingTetromino->Erase();
	MovingTetromino->Rotate_Right();

	if (!TestForMove(MovingTetromino)) // Test Nesbat Be Tet Haye Qadimi
		MovingTetromino->Rotate_Left();

	MovingTetromino->Draw();
}

void Page_Game::Rotate_Left_Piece()
{
	MovingTetromino->Erase();
	MovingTetromino->Rotate_Left();

	if (!TestForMove(MovingTetromino)) // Test Nesbat Be Tet Haye Qadimi
		MovingTetromino->Rotate_Right();

	MovingTetromino->Draw();
}

short Page_Game::Move_HardDrop()
{
	for (short i = 0; i < 20; ++i)
	{
		if (!Move_Down_Piece())
		return (i + 1);
	}
}

bool Page_Game::isThisLineFull(short Satr)
{
	for (short  i = 0; i < 10; ++i)
	{
		if (MatriseSaken[Satr][i] == 0)
			return false;
	}

	return true;
}

short Page_Game::LineChecker()
{
	vector < short > FullLines;
	for (short i = 0; i < 20; ++i)
	{
		if (isThisLineFull(i))
			FullLines.push_back(i);
	}

	if (!FullLines.empty())
		EraseLines(FullLines.back());

	for (short i = 0; i < FullLines.size(); ++i)
		SwipLines(FullLines[i]);

	return FullLines.size();
}

void Page_Game::EraseLines(short _Line)
{
	for (short i = 19; i >= 0; --i)
	{
		for (short j = 0; j < 10; ++j)
		{
			if (MatriseSaken[i][j] != 0)
				Console::PrintMoraba(Point(i, j), GetPageColor(), Point(1, 8));
		}
	}
}

void Page_Game::SwipLines(short _Line)
{
	for (short i = _Line; i > 0; --i)
	{
		for (short j = 0; j < 10; ++j)
		{
			MatriseSaken[i][j] = MatriseSaken[i - 1][j];
			MatriseSaken[i - 1][j] = 0;
		}
	}
}

bool Page_Game::isGameOver()
{
	for (short i = 0; i < 10; ++i)
	{
		if (!isBlockFree(0, i))
			return true;
	}

	return false;
}

bool Page_Game::isBlockFree(short x, short y)
{
	if (!(x <= 19 && y <= 9 && y >= 0))
		return false;

	if (MatriseSaken[x][y] == 0)
		return true;
	else
		return false;
}

bool Page_Game::isSaken()
{
	return isSakenValue;
}

Piece_Base * Page_Game::GetOutTetromino()
{
	MovingTetromino->Erase();
	MovingTetromino->ResetMokhtasat();
	isSakenValue = true;
	Piece_Base * ToReturn = MovingTetromino;

	MovingTetromino = nullptr;
	return ToReturn;
}

bool Page_Game::TestForMove(Piece_Base * Backup)
{
	Point MokhtasatTetromino = Backup->GetMokhtasat();
	TetrominoMatrix Matrixe_4_4 = Backup->GetSafeMatrix();

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			if (Matrixe_4_4.Points[i][j] == true)
			{
				if (!isBlockFree(i + MokhtasatTetromino.x + 1, j + MokhtasatTetromino.y))
					return false;
			}
		}
	return true;
}

void Page_Game::DrawSakenPieces()
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (MatriseSaken[i][j] != 0)
				Console::PrintMoraba(Point(i, j), MatriseSaken[i][j], Point(1,8));
		}
	}
}