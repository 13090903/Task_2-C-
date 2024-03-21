#include "BusStop.h"
#include<iostream>
#include <vector>
#include<string>
#include "Passenger.h"
using namespace std;
vector<Passenger*> BusStop::getPassengers()
{
    return _passengers;
}
void BusStop::setPassengers(vector<Passenger*> passengers)
{
    _passengers = passengers;
}
string BusStop::getName()
{
    return _name;
}
void BusStop::setName(string name)
{
    _name = name;
}
void BusStop::addPassenger(Passenger* pasenger)
{
    _passengers.push_back(pasenger);
}
void BusStop::deleteFirstPassenger()
{
    _passengers.erase(_passengers.begin());
}



