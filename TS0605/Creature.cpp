#include "Creature.h"
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

Creature::Creature(string name) {
	this->name = name;
}

Creature::Creature(string name, Creature& base) {
	*this = base;
	this->name = name;
	this->output = "";
}

Creature& Creature::operator[](string part) {
	if (status.find(part) == status.end())
	{
		status[part] = 0;
	}
	this->idx = part;
	return *this;
}

Creature& Creature::operator=(int value) {
	int n = this->status[this->idx];
	if (n == value)
	{
		return *this;
	}
	else if (value == 0)
	{
		this->status[this->idx] = value;
		output += this->name + " 's " + this->idx + " disappeared. (" + to_string(n) + " -> " + to_string(value) + ")." + '\n';
		return *this;
	}
	else if (n == 0)
	{
		this->status[this->idx] = value;
		output += this->name + " 's " + this->idx + " appeared. (" + to_string(n) + " -> " + to_string(value) + ")." + '\n';
		return *this;
	}
	else if (n > value)
	{
		this->status[this->idx] = value;
		output += this->name + " 's " + this->idx + " decreased. (" + to_string(n) + " -> " + to_string(value) + ")." + '\n';
		return *this;
	}
	else if (n < value)
	{
		this->status[this->idx] = value;
		output += this->name + " 's " + this->idx + " increased. (" + to_string(n) + " -> " + to_string(value) + ")." + '\n';
		return *this;
	}
}

Creature& Creature::operator+=(int input) {
	return (*this) = this->status[this->idx] + input;
}
Creature& Creature::operator-=(int input) {
	return (*this) = this->status[this->idx] - input;
}

void Creature::PrintStatus() {
	cout << this->name << " 's status" << endl;
	for (auto it = status.begin(); it != status.end(); it++)
	{
		if (it->second != 0)
		{
			cout << it->first << " * " << it->second << endl;
		}
	}
	cout << endl;
}

void Creature::PrintLog() {
	cout << this->name << " 's log" << endl;
	cout << "Day: 0000" << endl;
	cout << output << endl;
}