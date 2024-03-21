#include "Passenger.h"
#include "BusStop.h"
#include<iostream>
#include <vector>
#include<string>
using namespace std;
string Passenger::getEndName()
{
    return _endName;
}
void Passenger::setEndName(string endName)
{
    _endName = endName;
}
int Passenger::getNum() const
{
    return _num;
}
void Passenger::setNum(int num)
{
    _num = num;
}
