#pragma once
#include "Bus.h"
#include "BusStop.h"
#include "Passenger.h"
class Handler
{
private:
	Bus* _bus;

public:
	Handler(Bus* bus) {
		_bus = bus;
	}
	vector<BusStop*> getRouteOfBus();
	void setRouteToBus(vector<BusStop*> stops);
	BusStop* getBusStop(int idx);
	vector<Passenger*> getPassengersFromBus();
	int getBusPassengersAmount();
	string getBusStopName(BusStop* busStop);
	string getPassengerEndStop(Passenger* passenger);
	void setPassengersToBus(vector<Passenger*> passengers);
	int getBusCapacity();
	vector<Passenger*> getPassengersFromBusStop(BusStop* busStop);
	void addPassengerToBus(Passenger* passenger);
	void deleteFirstPassengerFromBusStop(BusStop* busStop);
	int getPassengerNum(Passenger* passenger);
};

