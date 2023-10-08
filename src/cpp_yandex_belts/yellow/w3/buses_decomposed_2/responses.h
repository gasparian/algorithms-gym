#pragma once

#include <string>
#include <iostream>

using namespace std;

struct BusesForStopResponse {
  string s;
};

ostream& operator<<(ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  string s;
};

ostream& operator<<(ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  string s;
};

ostream& operator<<(ostream& os, const AllBusesResponse& r);