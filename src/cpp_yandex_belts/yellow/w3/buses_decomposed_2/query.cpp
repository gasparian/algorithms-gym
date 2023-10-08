#include "query.h"

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