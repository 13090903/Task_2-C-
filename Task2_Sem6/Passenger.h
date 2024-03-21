#pragma once
#include<iostream>
#include <vector>
#include<string>
using namespace std;
class Passenger
{
private:
	int _num;
	string _endName;
public:
	Passenger(int num, string endName) {
		_num = num;
		_endName = endName;
	}

	int getNum() const;
	void setNum(int num);

	string getEndName();
	void setEndName(string endName);
};

