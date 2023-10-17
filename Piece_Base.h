#pragma once
#include "Point.h"
#include "TetrominoMatrix.h"


// classe Pedare Hameeye Tike (Tetromino) Ha
class Piece_Base
{
private:
	Point Mokhtasat;
	short HalateAlan;
	Point InThisPageDrawIt;
	short BackgColor;

protected:
	TetrominoMatrix HalatHa[4];
	short Rang;

public:
	Piece_Base();

	// Tabe Set Kardane Yeki Az 0,1,2,3 Halat Ha
	void SetNowHalat(short);
	void SetMokhtasat(short, short) noexcept;
	void ResetMokhtasat() noexcept;

	TetrominoMatrix GetSafeMatrix()const noexcept;
	Point GetMokhtasat()const noexcept;
	short GetRang()const noexcept;

	// Taabe Draw
	void Draw()const noexcept;
	void Erase()const noexcept;
	void Draw(short Pos)const;
	void Erase(short Pos)const;
	void SetPage(const Point & _mokhtasat, short _rang);

	// Rotate
	// Move
	void Move_Right() noexcept;
	void Move_Left() noexcept;
	void Move_Down() noexcept;
	void Rotate_Right() noexcept;
	void Rotate_Left() noexcept;

	// Taabe Sakhte Har Sheye Bache
	virtual void Create(short) = 0;
};