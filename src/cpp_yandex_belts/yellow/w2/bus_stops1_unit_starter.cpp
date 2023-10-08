#include <unordered_set>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

struct Response {
  string s;
};

ostream& operator<<(ostream& os, const Response& r) {
  os << r.s;
  return os;
}

// struct BusesForStopResponse {
//   string s;
// };

// ostream& operator<<(ostream& os, const BusesForStopResponse& r) {
//   os << r.s;
//   return os;
// }

// struct StopsForBusResponse {
//   string s;
// };

// ostream& operator<<(ostream& os, const StopsForBusResponse& r) {
//   os << r.s;
//   return os;
// }

// struct AllBusesResponse {
//   string s;
// };

// ostream& operator<<(ostream& os, const AllBusesResponse& r) {
//   os << r.s;
//   return os;
// }

istream& operator>>(istream& is, Query& q) {
  int stops_count = 0;
  string inp;
  is >> inp;
  if ( inp == "NEW_BUS" ) {
    q.type = QueryType::NewBus;
    is >> q.bus;
    is >> stops_count;
    int i = 0;
    q.stops = {};
    while ( i < stops_count ) {
        is >> inp;
        q.stops.push_back(inp);
        i++;
    }
  } else if ( inp == "BUSES_FOR_STOP" ) {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if ( inp == "STOPS_FOR_BUS" ) {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
  } else if ( inp == "ALL_BUSES" ) {
    q.type = QueryType::AllBuses;
  }

  return is;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
      for (string stop : stops) {
        buses_to_stops[bus].push_back(stop);
        stops_to_buses[stop].push_back(bus);
      }
  }

  Response GetBusesForStop(const string& stop) const {
      Response resp;
      if (stops_to_buses.count(stop) == 0) {
        resp.s = "No stop";
      } else {
        for (const string& bus : stops_to_buses.at(stop)) {
          resp.s += bus + " ";
        }
      }
      return resp;
  }

  Response GetStopsForBus(const string& bus) const {
      Response resp;
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

  Response GetAllBuses() const {
    Response resp;
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

private:
    map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}

// 10
// ALL_BUSES
// BUSES_FOR_STOP Marushkino
// STOPS_FOR_BUS 32K
// NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
// NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
// BUSES_FOR_STOP Vnukovo
// NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
// NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
// STOPS_FOR_BUS 272
// ALL_BUSES

// No buses
// No stop
// No bus
// 32 32K
// Stop Vnukovo: 32 32K 950
// Stop Moskovsky: no interchange
// Stop Rumyantsevo: no interchange
// Stop Troparyovo: 950
// Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
// Bus 32: Tolstopaltsevo Marushkino Vnukovo
// Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
// Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo