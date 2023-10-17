#include "TetrominoMatrix.h"
#include <stdexcept>
using namespace std;
TetrominoMatrix::TetrominoMatrix()
{
}

TetrominoMatrix::TetrominoMatrix(const Point & a, const Point & b, const Point & c, const Point & d)
{
	Assign(a, b, c, d);
}

void TetrominoMatrix::Assign(const Point & a, const Point & b, const Point & c, const Point & d)
{
	if (a.x > 4 || a.x < 0
		|| a.y > 4 || a.y < 0
		|| b.x > 4 || b.x < 0
		|| b.y > 4 || b.y < 0
		|| c.x > 4 || c.x < 0
		|| c.y > 4 || c.y < 0
		|| d.x > 4 || d.x < 0
		|| d.y > 4 || d.y < 0)
	{
		throw invalid_argument("Matrise Yek Tetromino 4*4 Ast. Vurudi Ra Controll Konid.");
	}

	for (short i = 0; i < 4; i++)
		for (short j = 0; j < 4; j++)
		{
			Points[i][j] = false;
		}

	Points[a.x][a.y] = true;
	Points[b.x][b.y] = true;
	Points[c.x][c.y] = true;
	Points[d.x][d.y] = true;
}