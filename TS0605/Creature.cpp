//Author: ¼B®a¦¨
//Date: 2023/04/30
//Last Update: 2023/04/30
//Description: The implementation of Creature class

#include "Creature.h"
#include "Diary.h"
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

vector<day_log> Diary::date; //initialize the static variable

struct nameCompare { //compare function for sorting
	bool operator()(const pair<string, int>& left, const pair<string, int>& right) { 
		return left.first < right.first; //compare the name
	}
};

Creature::Creature(string name) { //default constructor
	this->name = name; //set the name
	this->day_idx = Diary::date.size() - 1; //set the day index
}

Creature::Creature(string name, Creature& base) { //constructor to create a new creature
	*this = base; //copy the base
	this->name = name; //set the name
	this->output = ""; //set the output
	this->day_idx = Diary::date.size() - 1; //set the day index
}

Creature& Creature::operator[](string part) { //operator[] overloading
	if (status.find(part) == status.end()) //if the part is not in the map
	{
		status[part] = 0; //set the part to 0
	}
	this->idx = part; //set the index
	return *this; //return the creature
}

Creature& Creature::operator=(int value) { //operator= overloading
	int n = this->status[this->idx]; //get the original value
	if (n == value) //if the value is the same
	{
		return *this; //return the creature
	}
	else if (n == 0) //if the old value is zero
	{
		this->status[this->idx] = value; //set the value
		output += this->name + "'s " + this->idx + " appeared (" + to_string(n) + " -> " + to_string(value) + ")." + '\n'; //set the output, show that the part appeared
		Diary::newevent(this->name, output); //create a new event
		output = ""; //reset the output
		return *this; //return the creature
	}
	else if (n > value) //if the old value is larger than the new value
	{
		this->status[this->idx] = value; //set the value
		output += this->name + "'s " + this->idx + " decreased (" + to_string(n) + " -> " + to_string(value) + ")." + '\n'; //set the output, show that the part decreased
		Diary::newevent(this->name, output); //create a new event
		output = ""; //reset the output
		return *this; //return the creature
	}
	else if (n < value) //if the old value is smaller than the new value
	{
		this->status[this->idx] = value; //set the value
		output += this->name + "'s " + this->idx + " increased (" + to_string(n) + " -> " + to_string(value) + ")." + '\n'; //set the output, show that the part increased
		Diary::newevent(this->name, output); //create a new event
		output = ""; //reset the output
		return *this; //return the creature
	}
}

Creature& Creature::operator+=(int input) { //operator+= overloading
	return (*this) = this->status[this->idx] + input; //use operator= to add the value
}
Creature& Creature::operator-=(int input) { //operator-= overloading
	return (*this) = this->status[this->idx] - input; //use operator= to subtract the value
}

void Creature::PrintStatus() { //print the status
	cout << this->name << "'s status:" << endl; //print the name
	vector<pair<string,int>> v(status.begin(), status.end()); //create a vector to store the map
	sort(v.begin(), v.end(), nameCompare()); //sort the vector
	for (auto it = v.begin(); it != v.end(); it++) //print the status
	{
		if (it->second != 0) //if the value is not zero
		{
			cout << it->first << " * " << it->second << endl; //print the status
		}
	}
	cout << endl; //print a new line
}

void Creature::PrintLog() { //print the log
	cout << this->name << "'s log:" << endl; //print the name
	for (int i = day_idx; i < Diary::date.size(); i++) //loop through the days
	{
		cout << "Day " << Diary::date[i].name << endl; //print the day
		for (int j = 0; j < Diary::date[i].eventlist.size(); j++) //loop through the events
		{
			if (Diary::date[i].eventlist[j].name == this->name) //if the event is about this creature
				cout << Diary::date[i].eventlist[j].content; //print the event
		}
	}
	cout << endl; //print a new line
}