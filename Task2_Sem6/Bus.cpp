#include "Bus.h"
#include<iostream>
#include <vector>
#include<string>
using namespace std;
vector<BusStop*> Bus::getRoute()
{
    return _route;
}
void Bus::setRoute(vector<BusStop*> route)
{
    _route = route;
}
vector<Passenger*> Bus::getPassengers()
{
    return _passengers;
}
void Bus::setPassengers(vector<Passenger*> passengers)
{
    _passengers = passengers;
}
int Bus::getNumber()
{
    return _number;
}
void Bus::setCapacity(int capacity)
{
    _capacity = capacity;
}
int Bus::getCapacity()
{
    return _capacity;
}
void Bus::setNumber(int number)
{
    _number = number;
}
void Bus::addPassenger(Passenger* pasenger)
{
    _passengers.push_back(pasenger);
}
void Bus::deletePassenger(int idx)
{
    _passengers.erase(_passengers.begin() + idx);
}
