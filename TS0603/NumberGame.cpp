//Author: ¼B®a¦¨
//Date: 2023/04/29
//Last Update: 2023/04/29
//Description: The implementation of NumberGame class

#include "NumberGame.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> doProduct(vector<int> numbers, int product, int index) //find all possible product
{
	vector<int> res; //store all possible product
	if (index == numbers.size() - 1) //if the index is the last number
	{
		res.push_back(product); //push the product into the vector
		return res; //return the vector
	}
	else
	{
		vector<int> subproduct = doProduct(numbers, product, index + 1); //find all possible product without the number
		for (int i = 0; i < subproduct.size(); i++)
		{
			res.push_back(subproduct[i]); //push the product into the vector
		}
		subproduct = doProduct(numbers, product * numbers[index + 1], index + 1); //find all possible product with the number
		for (int i = 0; i < subproduct.size(); i++)
		{
			res.push_back(subproduct[i]); //push the product into the vector
		}
		return res; //return the vector
	}
}

vector<int> findAllProduct(vector<int> numbers) //find all possible product
{
	vector<int> res; //store all possible product
	while (!numbers.empty()) //if the vector is not empty
	{
		vector<int> subproduct = doProduct(numbers, numbers[0], 0); //find all possible product
		for (int i = 0; i < subproduct.size(); i++) 
		{
			res.push_back(subproduct[i]); //push the product into the vector
		}
		numbers.erase(numbers.begin()); //erase the first number
	}
	sort(res.begin(), res.end()); //sort the vector
	return res; //return the vector
}


void NumberGame::SetInput(int input)
{
	number = input; //set the input to the number
}

void NumberGame::ProcessInput()
{
	int temp = number; //set the number to temp
	int digit = 0; //set the digit to 0
	while (temp > 0) //if the temp is greater than 0
	{
		digit = temp % 10; //get the digit
		devNumberList.push_back(digit); //push the digit into the vector
		temp /= 10; //divide the temp by 10
	}
	sort(devNumberList.begin(), devNumberList.end()); //sort the vector
	NumberList = findAllProduct(devNumberList); //find all possible product
}

void NumberGame::SetFileName(string filename)
{
	FileName = filename; //set the filename to FileName
}

void NumberGame::LoadNumberList()
{
	ifstream fin; //declare the ifstream
	fin.open(FileName); //open the file
	int temp; //declare the temp
	int maxNum = 1;
	while (fin >> temp) //if the file is not empty
	{
		if (find(NumberList.begin(), NumberList.end(), temp) != NumberList.end()) //if the temp is in the NumberList
		{
			res.push_back(temp); //push the temp into the vector
		}
	}
}

void NumberGame::PrintAllValid() //print the valid number
{
	for (int i = 0; i < res.size(); i++)
	{ 
		cout << res[i] << endl; //print the valid number
	}
}

void NumberGame::Reset()
{
	devNumberList.clear(); //clear the vector
	NumberList.clear(); //clear the vector
	res.clear(); //clear the vector
}