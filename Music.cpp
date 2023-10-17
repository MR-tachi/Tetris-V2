#include "Music.h"



Music::Music()
{
}


Music::~Music()
{
}

void Music::HardSond()
{
	PlaySound(TEXT("Music/Hard"), NULL, SND_ALIAS);
}

void Music::MoveSound()
{
	PlaySound(TEXT("Music/Move"), NULL, SND_ALIAS);
}

void Music::LvlUpSound()
{
	PlaySound(TEXT("Music/LevelUp"), NULL, SND_ALIAS);
}

void Music::HoldSound()
{
	PlaySound(TEXT("Music/Hold"), NULL, SND_ALIAS);
}

void Music::RemoveLineSound(int tmp)
{
	switch (tmp)
	{
	case 1:
		PlaySound(TEXT("Music/One"), NULL, SND_ALIAS);
		break;
	case 2:
		PlaySound(TEXT("Music/Two"), NULL, SND_ALIAS);
		break;
	case 3:
		PlaySound(TEXT("Music/Three"), NULL, SND_ALIAS);
		break;
	case 4:
		PlaySound(TEXT("Music/Four"), NULL, SND_ALIAS);
		break;
	}
}

void Music::GameOverSound()
{
	PlaySound(TEXT("Music/GameOver1"), NULL, SND_ALIAS);
	PlaySound(TEXT("Music/GameOver2"), NULL, SND_ALIAS);
}
