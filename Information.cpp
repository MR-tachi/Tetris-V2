#include "Information.h"
#include <iostream>
#include<string>
#include <iomanip>
using namespace std;
Information::Information()
{
	file.open("Data\\HighScores.dat", ios::in | ios::out | ios::binary);
	Data info;
	if (!file)
	{
		ofstream tmp;
		tmp.open("Data\\HighScores.dat", ios::out | ios::binary);
		tmp.close();
		file.open("Data\\HighScores.dat", ios::in | ios::out | ios::binary);
		for (int i = 0; i < 100; i++)
		{
			file.write(reinterpret_cast<const char *>(&info), sizeof(Data));
		}
	}
	file.close();
	//file.read(reinterpret_cast<char *>(&info), sizeof(Data));
	//if (file.eof())//agar file khali bod , yek data ye khali dar file mirizad
	//{
	//file.seekg(0, ios::end);
	//file.write(reinterpret_cast<const char *>(&info), sizeof(Data));
	//info.~Data();
	//}
}


void Information::Update(const Data & _tmp)
{
	Data info;
	file.open("Data\\HighScores.dat", ios::app | ios::binary);
	_tmp;
	info.Played();
	file.write(reinterpret_cast<const char*>(&_tmp), sizeof(Data));
	//file.seekg(0);
	//file.read(reinterpret_cast<char *>(&info), sizeof(Data));
	//int i = 0;
	//for (i = 0; i <= 100; i++)
	//{
	//	if (info.getUserName() == _tmp.getUserName())//agar username player az ghabl mojod bashsad
	//	{
	//		cout << "player found";
	//		getchar();
	//		if (info.getHgihScore() < _tmp.getHgihScore())//agar player record khod ra zad 
	//		{
	//			info.setHighScore(_tmp.getHgihScore());
	//			info.setLevel(_tmp.getLevel());
	//			info.setLines(_tmp.getLines());
	//			info.setTime(_tmp.getLines());
	//			cout << " score better";
	//			getchar();
	//		}

	//		break;
	//	}
	//		if (info.getUserName() == "")//agar  username ie dar file nabashad
	//		{
	//			info = _tmp;
	//			break;
	//		}
	//file.read(reinterpret_cast<char *>(&info), sizeof(Data));
	////agar hanooz bazikoni dar file bood vali username motabeghat nadasht yek class data read mikonim
	//}

	//info.Played();
	//file.seekp(sizeof(Data));
	//file.write(reinterpret_cast<const char*>(&info), sizeof(Data));
	file.close();
}

void Information::HighScores()
{
	file.open("Data\\HighScores.dat", ios::in | ios::binary);
	file.seekg(0);
	system("cls");
	cout << setw(15) << left << "Username" << setw(14) << "High Score" << setw(12) << "PlayTimes";
	cout << setw(17) << "Line Removed" << setw(9) << "Level" << setw(7) << "Time" << endl;
	Data Info;
	file.read(reinterpret_cast<char *>(&Info), sizeof(Data));
	for(int i=0; i<100 ;i++)
	{
		if (Info.getUserName()!="")
		{
			cout << setw(15) << Info.getUserName() << setw(14) << Info.getHgihScore() << setw(12) << Info.getPlayTimes() << setw(17) << Info.getLines();
			cout << setw(9) << Info.getLevel() << setw(2) << (Info.getTime() / 60) << " : " << setw(2) << (Info.getTime() % 60) << endl << endl;
		}
		//else  break;
		file.read(reinterpret_cast<char *>(&Info), sizeof(Data));
	}
}
