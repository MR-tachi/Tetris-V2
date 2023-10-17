#pragma once
#include "Point.h"

// Matrise 4 * 4
// Baraye Negahdarie Yek Halate Khas Az Yek Tetromino(Tike)
class TetrominoMatrix
{
public:
	bool Points[4][4];

	TetrominoMatrix();
	TetrominoMatrix(const Point & a, const Point & b, const Point & c, const Point & d);

	void Assign(const Point & a, const Point & b, const Point & c, const Point & d);

};