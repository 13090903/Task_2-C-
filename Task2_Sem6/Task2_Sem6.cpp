// Task2_Sem6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include "Handler.h"
#include "GeneralHandler.h"
#include "Passenger.h"
#include "BusStop.h"
#include "Bus.h"

#define MIN(a, b) (a < b ? a : b)

using namespace std;

static void test(Bus* bus, vector<int> res) {
    Handler* handler = new Handler(bus);
    GeneralHandler* gh = new GeneralHandler(handler);
    vector<int> r;
    for (BusStop* bs : handler->getRouteOfBus()) {
        handler->setPassengersToBus(gh->dropOffPassengersAtBusStop(bs));
        gh->addPassengersToBus(bs);
        r.push_back(handler->getBusPassengersAmount());
    }
    for (int l = handler->getRouteOfBus().size() - 1; l >= 0; l--) {
        handler->setPassengersToBus(gh->dropOffPassengersAtBusStop(handler->getBusStop(l)));
        gh->addPassengersToBus(handler->getBusStop(l));
    }
    for (int i = 0; i < r.size(); i++) {
        if (r[i] != res[i]) {
            cout << "FAILED\n";
        }
        else {
            cout << "PASSED\n";
        }
    }
}

int main()
{
    vector<BusStop*> stops;
    map<string, int> m;
    for (int i = 0; i < 3; i++) {
        stops.push_back(new BusStop(to_string(i)));
        m[to_string(i)] = i;
    }
    cout << "Enter bus capacity\n";
    int n;
    cin >> n;
    Bus* bus = new Bus(1, n);
    Handler* handler = new Handler(bus);
    GeneralHandler* gh = new GeneralHandler(handler);
    cout << "Bus stop list: \n";
    for (int i = 0; i < 3; i++) {
        cout << stops[i]->getName() << " ";
    }
    cout << "\n";
    cout << "Create route (enter amount of stops then names separateed by space)\n";
    int k;
    cin >> k;
    vector<BusStop*> route;
    for (int i = 0; i < k; i++) {
        string route_stop;
        cin >> route_stop;
        route.push_back(stops[m[route_stop]]);
    }
    handler->setRouteToBus(route);
    cout << "For every bus stop enter passengers number and destination stop (enter amount of passengers then number and destination stop separateed by space)\n";
    for (BusStop* bs : stops) {
        cout << "stop " << bs->getName() << ":\n";
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int num;
            string endStop;
            cin >> num >> endStop;
            bs->addPassenger(new Passenger(num, endStop));
        }
    }
    cout << "Enter amount of cycles\n";
    int cycles;
    cin >> cycles;
    cout << "Bus simulation\n";
    for (int i = 0; i < cycles; i++) {
        for (BusStop* bs : handler->getRouteOfBus()) {
            cout << "Bus is now on the stop " << bs->getName() << "\n";
            handler->setPassengersToBus(gh->dropOffPassengersAtBusStop(bs));
            gh->addPassengersToBus(bs);
            gh->showPassengersInBus();
        }
        for (int l = bus->getRoute().size() - 1; l >= 0; l--) {
            cout << "Bus is now on the stop " << handler->getBusStop(l)->getName() << "\n";
            handler->setPassengersToBus(gh->dropOffPassengersAtBusStop(handler->getBusStop(l)));
            gh->addPassengersToBus(handler->getBusStop(l));
            gh->showPassengersInBus();
        }
    }
    Bus* bus1 = new Bus(1, 5);
    vector<BusStop*> route1;
    route1.push_back(stops[0]);
    route1.push_back(stops[1]);
    route1.push_back(stops[2]);
    bus1->setRoute(route1);
    route1[0]->addPassenger(new Passenger(1, "2"));
    route1[0]->addPassenger(new Passenger(2, "1"));
    route1[1]->addPassenger(new Passenger(3, "2"));
    vector<int> res;
    res.push_back(2);
    res.push_back(2);
    res.push_back(0);
    cout << "____________________\n";
    test(bus1, res);

}
