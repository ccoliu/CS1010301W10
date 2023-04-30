#pragma once
#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	string name;
	string content;
} event;

typedef struct {
	string name;
	vector<event> eventlist;
} day_log;

class Diary
{
public:
	static void NewDay(string day);
	static void newevent(string name, string content);
	static vector<day_log> date;
};
