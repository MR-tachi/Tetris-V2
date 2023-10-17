#include "Data.h"
#include <string>

using namespace std;

Data::Data(const std::string& _username , short _line , short _lvl, int _score, int _time):Lines(_line),Level(_lvl),HighScore(_score),Time(_time)
{
	setUserName(_username);
}


Data::~Data()
{
}

void Data::setUserName(const std::string tmp)
{
	int length = tmp.size();
	length = (length < 20 ? length : 19);
	tmp.copy(UserName, length);
	UserName[length] = '\0';
}

std::string Data::getUserName() const
{
	return UserName;
}

void Data::setLines(const short _line)
{
	Lines = _line;
}

short Data::getLines() const
{
	return Lines;
}

void Data::setLevel(const short _level)
{
	Level = _level;
}

short Data::getLevel() const
{
	return Level;
}

void Data::setHighScore(const int _highscore)
{
	HighScore = _highscore;
}

int Data::getHgihScore() const
{
	return HighScore;
}

void Data::setTime(const int _time)
{
	Time = _time;
}

int Data::getTime() const
{
	return Time;
}

void Data::Played()
{
	PlayTimes++;
}

short Data::getPlayTimes() const
{
	return PlayTimes;
}
