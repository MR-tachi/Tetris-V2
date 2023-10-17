#pragma once

#include "Page_Base.h"
class Page_Score
{
public:
	Page_Score();
	void SpaceScore(short);
	void DownScore();
	void LineScore(short);
	short GetLevel();
	int GetScore();
	void Draw();
	short GetTotalLine();


private:
	int Score;
	short TotalLine;
	short TmpLine;
	short Level;
};

