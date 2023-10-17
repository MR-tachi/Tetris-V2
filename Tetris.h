#pragma once
#include "Piece_Base.h"
#include "Page_Game.h"
#include "Page_Hold.h"
#include "Page_Next.h"
#include "Page_Menu.h"
#include "GameScores.h"
#include "Music.h"
#include "Information.h"


class Tetris
{
private:
	Page_Hold HoldPage;
	Page_Game GamePage;
	Page_Next NextPage;
	Page_Menu MenuPage;
	Page_Score ScorePage;
	Information Inf;
	Music Play;
	bool isMainMenu = 1;
	bool isPauseMenu = 1;
	
	void PauseMenu();
	void Menu();
	void GameOver();
	void KeyboardInput(char _Input);
	void HoldFunc();
	void BackGroundDraw();
	std::string username;

public:
	Tetris();
	void RunGame();
};