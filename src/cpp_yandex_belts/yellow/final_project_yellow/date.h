#pragma once

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <system_error>

using namespace std;

class Date {
public:
  Date();
  Date(int year, int month, int day);
  int GetYear() const;
  int GetMonth() const;
  int GetDay() const;
private:
  vector<int> date;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);

ostream& operator<<(ostream& out, const Date& date);

Date ParseDate(istream& ss);
