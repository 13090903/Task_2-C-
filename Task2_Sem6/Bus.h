#pragma once
#include<iostream>
#include <vector>
#include<string>
#include "BusStop.h"
using namespace std;
class Bus
{
private:
	int _number;
	int _capacity;
	vector<BusStop*> _route;
	vector<Passenger*> _passengers;
public:
	Bus(int number, int capacity) {
		_number = number;
		_capacity = capacity;
	}
	vector<BusStop*> getRoute();
	void setRoute(vector<BusStop*> route);

	vector<Passenger*> getPassengers();
	void setPassengers(vector<Passenger*> route);

	int getNumber();
	void setNumber(int number);

	int getCapacity();
	void setCapacity(int capacity);

	void addPassenger(Passenger* pasenger);
	void deletePassenger(int idx);
};

