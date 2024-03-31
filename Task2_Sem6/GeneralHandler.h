#pragma once
#include "Bus.h"
#include "BusStop.h"
#include "Passenger.h"
#include "Handler.h"
class GeneralHandler {
private:
	Handler* _handler;

public:
	GeneralHandler(Handler* handler) {
		_handler = handler;
	}
	vector<Passenger*> dropOffPassengersAtBusStop(BusStop* bs);
	void addPassengersToBus(BusStop* bs);
	void showPassengersInBus();
};

