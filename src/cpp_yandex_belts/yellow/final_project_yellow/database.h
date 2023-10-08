#pragma once

#include <map>
#include <set>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <iterator>
#include "date.h"

using namespace std;

class Database {
public:
  void Add(const Date& date, const string& event);
  string Last(const Date& date) const;
  void Print(ostream& out) const;

  template <class Func> int RemoveIf(Func predicate) {
      int counter = 0;
      // iterate through the each date and scan sets of events
      for (auto it1 = this->base.begin(); it1 != this->base.end(); ) {
          Date outer_date = it1->first;
          for  (auto it2 = it1->second.begin(); it2 != it1->second.end(); ) {
            if ( predicate(outer_date, *(it2)) ) {
              // drop event from the deque first, then from `base` map
              this->base_last_el[it1->first].erase(
                remove_if(this->base_last_el[it1->first].begin(), this->base_last_el[it1->first].end(), 
                        [predicate, outer_date](const string& event){ return predicate(outer_date, event); } ),
              this->base_last_el[it1->first].end());

              it2 = it1->second.erase(it2); 
              ++counter;
            } else {
              ++it2;
            }
          }
          
          // drop the empty date from the both maps
          if ( it1->second.empty() ) {
              it1 = this->base.erase(it1);
          } else {
              ++it1;
          }

          if ( this->base_last_el[outer_date].empty() ) {
              this->base_last_el.erase(outer_date);
          }
      }

      return counter;
  }
  template <class Func> vector<string> FindIf(Func predicate) const {
      vector<string> out;
      // iterate through the each date and scan sets of events
      for (auto it1 = this->base_last_el.begin(); it1 != this->base_last_el.end(); it1++) {
          Date outer_date = it1->first;
          ostringstream ss;
          ss << outer_date;
          string date_str = ss.str() + " ";

          for  (auto it2 = it1->second.begin(); it2 != it1->second.end(); it2++) {
            string el = *it2;
            if ( predicate(outer_date, el) ) {
                out.push_back(date_str + el);
            }
          }
      }
      return out;
  }

private:
  map<Date, set<string>> base;
  map<Date, deque<string>> base_last_el;
};