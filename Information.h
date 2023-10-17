#pragma once
#include <iostream>
#include <fstream>
#include "Data.h"




class Information
{
public:
	Information();
	void Update(const Data &);
	void HighScores();

private:
	std::fstream file;
	//Data info;
};

