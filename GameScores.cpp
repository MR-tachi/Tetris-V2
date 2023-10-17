#include "GameScores.h"
#include "Music.h"
#include "Console.h"

#include <iomanip>
#include <iostream>

using namespace std;

Page_Score::Page_Score()
{
	TotalLine = 0;
	Score = 0;
	Level = 1;
	TmpLine = 0;
}

void Page_Score::SpaceScore(short _lines)
{
	Score += (2 * _lines);
}

void Page_Score::DownScore()
{
	Score++;
}

void Page_Score::LineScore(short _lines)
{
	Music Play;
	TotalLine += _lines;
	switch (_lines) {
	case 0:
		break;
	case 1:
		Score += (40 * Level);
		TmpLine += 1;
		break;
	case 2:
		Score += (100 * Level);
		TmpLine += 3;
		break;
	case 3:
		Score += (300 * Level);
		TmpLine += 5;
		break;
	case 4:
		Score += (1200 * Level);
		TmpLine += 8;
		break;
	}
		Play.RemoveLineSound(_lines);
	if (5 * Level <= TmpLine) {
		TmpLine %= (Level * 5);
		Level++;
		Play.LvlUpSound();
	}
}

short Page_Score::GetLevel()
{
	return Level;
}

int Page_Score::GetScore()
{
	return Score;
}

void Page_Score::Draw()
{
	Console::setcolor(10);
	short X = 9;
	for (short Y = 17; Y <= 24; Y++) {
		Console::gotoXY(Y, X);
		if (Y == 17)
			cout << "      SCORE BOARD     ";
		else if (Y == 19)
			cout << "    Score : " << setw(10) << left << Score;
		else if (Y == 21)
			cout << "    Level : " << setw(10) << left << Level;
		else if (Y == 23)
			cout << "    GOAL  : " << setw(10) << left << ((5 * Level) - TmpLine);
		else cout << setw(22) << " ";
	}
}

short Page_Score::GetTotalLine()
{
	return TotalLine;
}


