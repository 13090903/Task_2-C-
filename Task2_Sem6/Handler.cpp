#include "Handler.h"
#include "BusStop.h"
#include<iostream>
#include <vector>
#include<string>
using namespace std;

vector<BusStop*> Handler::getRouteOfBus()
{
    return _bus->getRoute();
}
void Handler::setRouteToBus(vector<BusStop*> stops)
{
    _bus->setRoute(stops);
}
BusStop* Handler::getBusStop(int idx)
{
    return _bus->getRoute()[idx];
}
vector<Passenger*> Handler::getPassengersFromBus() {
    return _bus->getPassengers();
}
int Handler::getBusPassengersAmount() {
    return _bus->getPassengers().size();
}
string Handler::getBusStopName(BusStop* busStop) {
    return busStop->getName();
}
string Handler::getPassengerEndStop(Passenger* passenger) {
    return passenger->getEndName();
}
void Handler::setPassengersToBus(vector<Passenger*> passengers) {
    _bus->setPassengers(passengers);
}
int Handler::getBusCapacity() {
    return _bus->getCapacity();
}
vector<Passenger*> Handler::getPassengersFromBusStop(BusStop* busStop) {
    return busStop->getPassengers();
}
void Handler::addPassengerToBus(Passenger* passenger) {
    _bus->addPassenger(passenger);
}
void Handler::deleteFirstPassengerFromBusStop(BusStop* busStop) {
    busStop->deleteFirstPassenger();
}
int Handler::getPassengerNum(Passenger* passenger) {
    return passenger->getNum();
}