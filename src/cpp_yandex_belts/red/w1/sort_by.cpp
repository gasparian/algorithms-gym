#include "airline_ticket.h"
#include "test_runner.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <numeric>
using namespace std;

#define SORT_BY(field)                                          \
    [](const AirlineTicket& inp1, const AirlineTicket& inp2) {  \
        return inp1.field < inp2.field;                         \
    }                                                           \

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

void TestSortBy() {
  vector<AirlineTicket> tixs = {
    {"VKO", "AER", "Utair",     {2018, 2, 28}, {17, 40}, {2018, 2, 28}, {20,  0}, 1200},
    {"AER", "VKO", "Utair",     {2018, 3,  5}, {14, 15}, {2018, 3,  5}, {16, 30}, 1700},
    {"AER", "SVO", "Aeroflot",  {2018, 3,  5}, {18, 30}, {2018, 3,  5}, {20, 30}, 2300},
    {"PMI", "DME", "Iberia",    {2018, 2,  8}, {23, 00}, {2018, 2,  9}, { 3, 30}, 9000},
    {"CDG", "SVO", "AirFrance", {2018, 3,  1}, {13, 00}, {2018, 3,  1}, {17, 30}, 8000},
  };

  sort(begin(tixs), end(tixs), SORT_BY(price));
  ASSERT_EQUAL(tixs.front().price, 1200);
  ASSERT_EQUAL(tixs.back().price, 9000);

  sort(begin(tixs), end(tixs), SORT_BY(from));
  ASSERT_EQUAL(tixs.front().from, "AER");
  ASSERT_EQUAL(tixs.back().from, "VKO");

  sort(begin(tixs), end(tixs), SORT_BY(arrival_date));
  ASSERT_EQUAL(tixs.front().arrival_date, (Date{2018, 2, 9}));
  ASSERT_EQUAL(tixs.back().arrival_date, (Date{2018, 3, 5}));

  sort(begin(tixs), end(tixs), SORT_BY(arrival_time));
  ASSERT_EQUAL(tixs.front().arrival_time, (Time{3, 30}));
  ASSERT_EQUAL(tixs.back().arrival_time, (Time{20, 30}));
}

int main() {
  TestRunner tr;
  RUN_TEST(tr, TestSortBy);
}