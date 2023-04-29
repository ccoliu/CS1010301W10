#pragma once
#include <iostream>
#include <vector>
using namespace std;

class NumberGame
{
private:
	vector<int> devNumberList;
	vector<int> NumberList;
	vector<int> res;
	string FileName;
	int number;
public:
	void SetInput(int input);
	void ProcessInput();
	void SetFileName(string filename);
	void LoadNumberList();
	void PrintAllValid();
	void Reset();
};