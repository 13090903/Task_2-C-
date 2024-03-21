#pragma once
#include "Passenger.h"
#include<iostream>
#include <vector>
#include<string>
using namespace std;

class BusStop
{
private:
	vector<Passenger*> _passengers;
	string _name;
public:
	BusStop(string name) {
		_name = name;
	}

	vector<Passenger*> getPassengers();
	void setPassengers(vector<Passenger*> passengers);

	string getName();
	void setName(string name);

	void addPassenger(Passenger* pasenger);
	void deleteFirstPassenger();
};

