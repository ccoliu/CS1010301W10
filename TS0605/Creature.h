#pragma once
#include <iostream>
#include <map>
#include "Diary.h"
using namespace std;

class Creature
{
private:
	string name;
	string idx;
	string output = "";
	int day_idx;
	map<string,int> status;
public:
	Creature(string name);
	Creature(string name, Creature& base);
	Creature& operator[](string part);
	Creature& operator=(int value);
	Creature& operator+=(int input);
	Creature& operator-=(int input);
	void PrintStatus();
	void PrintLog();
};