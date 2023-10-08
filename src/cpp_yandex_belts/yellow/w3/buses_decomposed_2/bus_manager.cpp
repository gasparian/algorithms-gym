#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
    for (string stop : stops) {
    buses_to_stops[bus].push_back(stop);
    stops_to_buses[stop].push_back(bus);
    }
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
    BusesForStopResponse resp;
    if (stops_to_buses.count(stop) == 0) {
    resp.s = "No stop";
    } else {
    for (const string& bus : stops_to_buses.at(stop)) {
        resp.s += bus + " ";
    }
    }
    return resp;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
    StopsForBusResponse resp;
    if (buses_to_stops.count(bus) == 0) {
    resp.s = "No bus";
    } else {
    for (const string& stop : buses_to_stops.at(bus)) {
        resp.s += "Stop " + stop + ": ";
        if (stops_to_buses.at(stop).size() == 1) {
        resp.s += "no interchange";
        resp.s += '\n';
        } else {
        for (const string& other_bus : stops_to_buses.at(stop)) {
            if (bus != other_bus) {
            resp.s += other_bus + " ";
            }
        }
        resp.s += '\n';
        }
    }
    resp.s.pop_back();
    }
    return resp;
}

AllBusesResponse BusManager::GetAllBuses() const {
    AllBusesResponse resp;
    if (buses_to_stops.empty()) {
        resp.s = "No buses";
    } else {
        for (const auto& bus_item : buses_to_stops) {
            resp.s += "Bus " + bus_item.first + ": ";
            for (const string& stop : bus_item.second) {
                resp.s += stop + " ";
            }
            resp.s += '\n';
        }
        resp.s.pop_back();
    }
    return resp;
}