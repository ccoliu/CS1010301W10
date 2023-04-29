//Author: ¼B®a¦¨
//Date: 2023/04/29
//Last Update: 2023/04/29
//Description: The implementation of NumberGame class

#include "VecNf.h"
#include <iostream>
#include <vector>
using namespace std;

VecNf::VecNf() { //default constructor
	vec = vector<float>(0); //set the vector size to 0
}

VecNf::VecNf(float* dest, int cnt) { //constructor
	vec = vector<float>(); //set the vector size to 0
	for (int i = 0; i < cnt; i++) {
		vec.push_back(dest[i]); //push the number into the vector
	}
}

VecNf::VecNf(const VecNf& rhs) { //copy constructor
	vec = vector<float>(); //set the vector size to 0
	vec = rhs.vec; //copy the vector
}

VecNf& VecNf::operator=(const VecNf& rhs) { //assignment operator
	vec = rhs.vec; //copy the vector
	cout << "ASSIGNMENT!!!" << endl; //print out the message
	return *this; //return the vector
}

float& VecNf::operator[](int index) { //subscript operator
	if (index < vec.size()) //if the index is smaller than the vector size
	{
		return vec[index]; //return the number
	}
}

VecNf& VecNf::operator+(const VecNf& rhs) { //addition operator
	VecNf* res = new VecNf(); //create a new vector
	if (vec.size() != rhs.vec.size()) //if the vector size is not equal
	{
		cout << "dimensions inconsistent" << endl; //print out the message
		return *res; //return the vector
	}
	res->vec = vec; //copy the vector
	for (int i = 0; i < rhs.vec.size(); i++) {
		res->vec[i] += rhs.vec[i]; //add the number
	}
	return *res; //return the vector
}

VecNf& VecNf::operator-(const VecNf& rhs) { //subtraction operator
	VecNf* res = new VecNf(); //create a new vector
	if (vec.size() != rhs.vec.size()) //if the vector size is not equal
	{
		cout << "dimensions inconsistent" << endl; //print out the message
		return *res; //return the vector
	}
	res->vec = vec; //copy the vector
	for (int i = 0; i < rhs.vec.size(); i++) { 
		res->vec[i] = vec[i] - rhs.vec[i]; //subtract the number
	}
	return *res; //return the vector
}

float VecNf::operator*(const VecNf& rhs) { //multiplication operator
	if (vec.size() != rhs.vec.size()) //if the vector size is not equal
	{
		cout << "dimensions inconsistent" << endl; //print out the message
		return 0; //return 0
	}
	float res = 0; //create a new number
	for (int i = 0; i < vec.size(); i++) {
		res += vec[i] * rhs.vec[i]; //multiply the number
	}
	return res; //return the number
}

VecNf& operator* (float scale, const VecNf& rhs) { //scalar multiplication operator
	VecNf* res = new VecNf(); //create a new 
	for (int i = 0; i < rhs.vec.size(); i++) {
		res->vec.push_back(scale * rhs.vec[i]); //multiply the number
	}
	return *res; //return the vector
}