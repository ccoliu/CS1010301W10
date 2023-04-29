#pragma once
#include <iostream>
#include <vector>
using namespace std;

class VecNf
{
private:
	vector<float> vec;
public:
	VecNf();
	VecNf(float* dest, int cnt);
	VecNf(const VecNf& rhs);
	int Size() { return vec.size(); }
	VecNf& operator=(const VecNf& rhs);
	float& operator[](int index);
	VecNf& operator+(const VecNf& rhs);
	VecNf& operator-(const VecNf& rhs);
	float operator*(const VecNf& rhs);
	friend VecNf& operator* (float scale, const VecNf& rhs);
};
