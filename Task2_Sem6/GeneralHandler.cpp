#include "GeneralHandler.h"
#include "Handler.h"
#include "BusStop.h"
#include<iostream>
#include <vector>
#include<string>
using namespace std;


#define MIN(a, b) (a < b ? a : b)


vector<Passenger*> GeneralHandler::dropOffPassengersAtBusStop(BusStop* bs) {
    vector<Passenger*> ps;
    for (Passenger* p : _handler->getPassengersFromBus()) {
        if (_handler->getPassengerEndStop(p) != _handler->getBusStopName(bs)) {
            ps.push_back(p);
        }
    }
    return ps;
}
void GeneralHandler::deletePassengersFromBus(BusStop* bs) {
    int cap = _handler->getBusCapacity() - _handler->getBusPassengersAmount();
    int size = _handler->getPassengersFromBusStop(bs).size();
    for (int j = 0; j < MIN(cap, size); j++) {
        Passenger* p = _handler->getPassengersFromBusStop(bs)[0];
        _handler->deleteFirstPassengerFromBusStop(bs);
        _handler->addPassengerToBus(p);
    }
}

void GeneralHandler::showPassengersInBus()
{
    cout << "Passengers is now in bus: ";
    for (Passenger* p : _handler->getPassengersFromBus()) {
        cout << _handler->getPassengerNum(p) << " ";
    }
    cout << "\n";
}
