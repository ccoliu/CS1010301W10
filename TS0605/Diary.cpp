//Author: ¼B®a¦¨
//Date: 2023/04/30
//Last Update: 2023/04/30
//Description: The implementation of Diary class

#include "Diary.h"

void Diary::NewDay(string day) { //static function of creating new day
	day_log new_day; //create a new day
	new_day.name = day; //set the day name
	date.push_back(new_day); //push the day into the vector
}

void Diary::newevent(string name, string content) { //static function of creating new event
	event new_event; //create a new event
	new_event.name = name; //set the event name
	new_event.content = content; //set the event content
	date[date.size()-1].eventlist.push_back(new_event); //push the event into the vector
}