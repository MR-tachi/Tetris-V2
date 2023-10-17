#pragma once
#include <string>
class Data
{
public:
	Data(const std::string & ="",short=0, short=0, int = 0,int=0);
	~Data();


	void setUserName(const std::string);
	std::string getUserName() const ;
	void setLines(const short);
	short getLines() const;
	void setLevel(const short);
	short getLevel() const;
	void setHighScore(const int);
	int getHgihScore() const;
	void setTime(const int);
	int getTime() const;
	void Played();
	short getPlayTimes()const;

private:
	char UserName[20];
	short PlayTimes;
	short Lines;
	short Level;
	int HighScore;
	int Time;

};

