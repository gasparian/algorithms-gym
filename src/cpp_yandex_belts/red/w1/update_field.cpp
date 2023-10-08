#include "airline_ticket.h"
#include "test_runner.h"

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

#define UPDATE_FIELD(ticket, field, values) {       \
  string field_name = #field;                       \
  auto it = values.find(field_name);                \
  if ( it != values.end() ) {                       \
    istringstream is(it->second);                   \
      is >> ticket.field;                           \
    }                                               \
}

bool operator<(const Date& lhs, const Date& rhs) {
    if ( (lhs.year < rhs.year) |
         ((lhs.year == rhs.year) && (lhs.month < rhs.month)) |
         ((lhs.year == rhs.year) && (lhs.month == rhs.month) && (lhs.day < rhs.day)) )
        return true;
    return false;
}

bool operator==(const Date& lhs, const Date& rhs) {
    if ( (lhs.year == rhs.year) &&
         (lhs.month == rhs.month) && 
         (lhs.day == rhs.day) )
        return true;
    return false;
}

ostream& operator<<(ostream& out, const Date& date) {
    out << setw(4) << setfill('0') << to_string(date.year) << '-'
        << setw(2) << setfill('0') << to_string(date.month) << '-'
        << setw(2) << setfill('0') << to_string(date.day);   
    return out;
}

istream& operator>>(istream& is, Date& date) {
    is >> date.year;
    is.ignore(1);
    is >> date.month;
    is.ignore(1);
    is >> date.day;
    return is;
}

bool operator<(const Time& lhs, const Time& rhs) {
    if ( (lhs.hours < rhs.hours) |
         ((lhs.hours == rhs.hours) && (lhs.minutes < rhs.minutes)) )
        return true;
    return false;
}

bool operator==(const Time& lhs, const Time& rhs) {
    if ( (lhs.hours == rhs.hours) &&
         (lhs.minutes == rhs.minutes) )
        return true;
    return false;
}

ostream& operator<<(ostream& out, const Time& tt) {
    out << setw(4) << setfill('0') << to_string(tt.hours) << ':'
        << setw(2) << setfill('0') << to_string(tt.minutes);   
    return out;
}

istream& operator>>(istream& is, Time& tt) {
    is >> tt.hours;
    is.ignore(1);
    is >> tt.minutes;
    return is;
}

void TestUpdate() {
  AirlineTicket t;
  t.price = 0;

  const map<string, string> updates1 = {
    {"departure_date", "2018-2-28"},
    {"departure_time", "17:40"}
  };
  UPDATE_FIELD(t, departure_date, updates1);
  UPDATE_FIELD(t, departure_time, updates1);
  UPDATE_FIELD(t, price, updates1);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 0);

  const map<string, string> updates2 = {
    {"price", "12550"},
    {"arrival_time", "20:33"},
  };

  UPDATE_FIELD(t, departure_date, updates2);
  UPDATE_FIELD(t, departure_time, updates2);
  UPDATE_FIELD(t, arrival_time, updates2);
  UPDATE_FIELD(t, price, updates2);

  ASSERT_EQUAL(t.departure_date, (Date{2018, 2, 28}));
  ASSERT_EQUAL(t.departure_time, (Time{17, 40}));
  ASSERT_EQUAL(t.price, 12550);
  ASSERT_EQUAL(t.arrival_time, (Time{20, 33}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestUpdate);
}