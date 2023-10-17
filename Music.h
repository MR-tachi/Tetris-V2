#pragma once
#include <Windows.h>
#pragma comment( lib, "winmm" ) 
class Music
{
public:
	Music();
	~Music();
	virtual void HardSond();
	virtual void MoveSound();
	virtual void LvlUpSound();
	virtual void HoldSound();
	virtual void RemoveLineSound(int);
	virtual void GameOverSound();
};

