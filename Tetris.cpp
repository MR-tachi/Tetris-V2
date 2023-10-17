#include "Tetris.h"
#include <random>
#include <string>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include "Console.h"
#include "Piece_Base.h"
#include "Piece_I.h"
#include "Piece_J.h"
#include "Piece_L.h"
#include "Piece_O.h"
#include "Piece_S.h"
#include "Piece_T.h"
#include "Piece_Z.h"
#include "Music.h"

#include <iostream>
#include <iomanip>

using namespace std;



Tetris::Tetris()
{
}

void Tetris::RunGame()
{
	Console::SetCosoleSize();
	Menu();
	cin >> username;
	time_t s = time(0);
	struct tm * now = localtime(&s);
	int start = (now->tm_hour * 3600) + (now->tm_min * 60) + now->tm_sec;///time system ra daryaft mikonad
	BackGroundDraw();
	HoldPage.DrawPage();
	GamePage.DrawPage();
	NextPage.DrawPage();
	NextPage.DrawInside();
	int Tmpline;

	while (!GamePage.isGameOver())
	{
		if (GamePage.isSaken()) // Agar Yek Tetromino Be Akhar Berese
		{
			NextPage.EraseInside(); // Update e NextPage
			GamePage.NewTetrominoInput(NextPage.GetTetromino()); // Update e NextPage va Gereftane Tetrominoye Jadid
			NextPage.DrawInside(); // Update e NextPage

			Tmpline = GamePage.LineChecker(); // Chek Kardane Line Haye Por shde va pass dadane teedad khat e hazf shode
			GamePage.DrawSakenPieces(); // Chap Kardane Bakhsh Haye Sabet

			ScorePage.LineScore(Tmpline);
			ScorePage.Draw();
			Tmpline = 0;
		}

		if (kbhit()) // Agar Keyboard Zarbe Bkhore
		{
			KeyboardInput(getch());
		}
		else
		{
			GamePage.NoInput();
			Sleep(800 - (ScorePage.GetLevel() * 50));//sorate bazi bar asase level
		}

	}
	s = time(0);
	now = localtime(&s);
	int finish = (now->tm_hour * 3600) + (now->tm_min * 60) + now->tm_sec;//time system ra daryaft mikonad barye zaman ejreaye baazi
	Data User;
	User.setHighScore(ScorePage.GetScore());
	User.setLines(ScorePage.GetTotalLine());
	User.setLevel(ScorePage.GetLevel());
	User.setTime(finish - start);
	Inf.Update(User);
	GameOver();
	cout << "\t\t\t\t\tYour Time is " << (User.getTime() / 60) << " :" << (User.getTime() % 60) << endl;
	Sleep(2000);
	getch();
	exit(0);
	// Kar Haye Bad Az GameOver
}


void Tetris::PauseMenu()
{
	bool pause=1;
	while (pause) {
		char tmp;
			tmp = getch();
		switch (tmp)
		{
		case '27': 
			pause = 0;
			break;
		default: 
			continue;
		}
	}
}

void Tetris::Menu()
{
	while (isMainMenu) {
		system("cls");
		MenuPage.MainMenu();
		short Y = 15, X = 40;
		switch (getch())
		{
		case '1':
			Y = 15;
			X = 50;
			system("cls");
			Console::gotoXY(Y, X);
			Console::setcolor(10);
			cout << "Enter Your Username : ";
			isMainMenu = 0;
			break;
		case '2':
			break;
		case '3':
			Inf.HighScores();
			getch();
			break;
		case '4':
			system("cls");
			MenuPage.Help();
			getch();
			break;
		case '5':
			exit(0);
		}
		}
}

void Tetris::GameOver()
{
	system("cls");
	short X = 0, Y = 6;
	Console::gotoXY(Y, X);
	Console::setcolor(4);
	cout << "                 ######      ###    ##     ## ########     #######  ##     ## ######## ########  \n";
	cout << "                 ##    ##    ## ##   ###   ### ##          ##     ## ##     ## ##       ##     ##\n";
	cout << "                 ##         ##   ##  #### #### ##          ##     ## ##     ## ##       ##     ##\n";
	cout << "                 ##   #### ##     ## ## ### ## ######      ##     ## ##     ## ######   ######## \n";
	cout << "                 ##    ##  ######### ##     ## ##          ##     ##  ##   ##  ##       ##   ##  \n";
	cout << "                 ##    ##  ##     ## ##     ## ##          ##     ##   ## ##   ##       ##    ## \n";
	cout << "                  ######   ##     ## ##     ## ########     #######     ###    ######## ##     ##\n";


	Play.GameOverSound();

	cout << "\n\n\t\t\t\t\tYour Score : " << ScorePage.GetScore() << endl;
	cout << "\t\t\t\t\tYour Level : " << ScorePage.GetLevel() << endl;
	cout << "\t\t\t\t\tYour Removed Lines : " << ScorePage.GetTotalLine()<< endl;

}

void Tetris::KeyboardInput(char tmp)
{
	if (tmp == -32)
		tmp = getch();

	switch (tmp)
	{
	case 'x':
	case 'w':
	case 72: // Rotate Right
		GamePage.Rotate_Right_Piece();
		Play.MoveSound();
		break;
	case 'z': // Rotate Left
		GamePage.Rotate_Left_Piece();
		Play.MoveSound();
		break;
	case 'd':
	case 77: // Move Right
		GamePage.Move_Right_Piece();
		Play.MoveSound();
		break;
	case 'a':
	case 75: // Move Left
		GamePage.Move_Left_Piece();
		Play.MoveSound();
		break;
	case 's':
	case 80: // Soft Drop
		GamePage.Move_Down_Piece();
		ScorePage.DownScore();
		Play.MoveSound();
		break;
	case 'c': // Hold
		HoldFunc();
		Play.HoldSound();
		break;
	case ' ': // Hard Drop
		short Moved_lines;
		Moved_lines = GamePage.Move_HardDrop();
		ScorePage.SpaceScore(Moved_lines);
		Play.HardSond();
		break;
	case 27:
		//PauseMenu();
		break;
	}
}

void Tetris::HoldFunc()
{
	Piece_Base * HoldedTet = HoldPage.Update(GamePage.GetOutTetromino());
	if (HoldedTet == nullptr)
	{
		NextPage.EraseInside();
		GamePage.NewTetrominoInput(NextPage.GetTetromino());
		NextPage.DrawInside();
	}
	else
	{
		GamePage.NewTetrominoInput(HoldedTet);
	}

	HoldPage.DrawInside();
}

void Tetris::BackGroundDraw()
{
	for (short i = 0; i < 25; ++i)
		for (short j = 0; j < 50; ++j)
			Console::PrintMoraba(Point(i, j), 136, Point(0, 0));
}
