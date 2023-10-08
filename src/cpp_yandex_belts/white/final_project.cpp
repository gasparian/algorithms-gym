#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <exception>
#include <string>
#include <iomanip>
#include <system_error>

using namespace std;

class Date {
public:
  Date() {
      date = {};
  }
  void SetDate(int year, int month, int day) {
      date = {year, month, day};
  }
  int GetYear() const {
      return date[0];
  }
  int GetMonth() const {
      return date[1];
  }
  int GetDay() const {
      return date[2];
  }
private:
  vector<int> date;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if ( (lhs.GetYear() < rhs.GetYear()) |
         ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() < rhs.GetMonth())) |
         ((lhs.GetYear() == rhs.GetYear()) && (lhs.GetMonth() == rhs.GetMonth()) && (lhs.GetDay() < rhs.GetDay())) )
        return true;
    return false;
}

class Database {
public:
  void AddEvent(const Date& date, const string& event) {
      base[date].insert(event);
  }
  bool DeleteEvent(const Date& date, const string& event) {
      auto it = base.find(date);
      if ( it != base.end() ) {
        auto it = base[date].find(event);
        if ( it != base[date].end() ) {
            base[date].erase(it);
            return true;
        }
      } 
      return false;
  }

  int DeleteDate(const Date& date) {
      int N = 0;
      auto it = base.find(date);
      if ( it != base.end() ) {
        N = base[date].size();
        base.erase(it);
      } 
      return N;
  }

  set<string> Find(const Date& date) const {
    set<string> value;
    if (base.count(date) > 0) {
        value = base.at(date);
    }
    return value;
  }
  
  void Print() const {
      for ( auto it_d=base.begin(); it_d != base.end(); ++it_d ) {
          ostringstream out_date;
          out_date << setw(4) << setfill('0') << to_string(it_d->first.GetYear()) << '-'
                   << setw(2) << setfill('0') << to_string(it_d->first.GetMonth()) << '-'
                   << setw(2) << setfill('0') << to_string(it_d->first.GetDay());
          set<string>::iterator it_e = it_d->second.begin();
          while (it_e != it_d->second.end()) {
              cout << out_date.str() << ' ' << *it_e << endl;
              it_e++;
          }
      }
  }

private:
  map<Date, set<string>> base;
};

void filter_stream(string& c, istringstream& ss, int& i, bool day_flag) {
    if ( ss.peek() == '-' ) {
        ss.ignore(1);
        if ( !isdigit(ss.peek()) ) {
            throw invalid_argument("Wrong date format: " + c);  
        } else {
            ss >> i;
            i *= -1;
        }
    } else if ( (ss.peek() == '+') | isdigit(ss.peek()) ) {
        ss >> i;
        if ( day_flag ) {
            string n;
            getline(ss, n);
            char next_char = n[0];
            if ( !isdigit(next_char) && !n.empty() && (next_char != ' ') ) {
                throw invalid_argument("Wrong date format: " + c);
            }
        }
        
    } else {
        throw invalid_argument("Wrong date format: " + c);
    }
}

void parse_date(string& c, Date& date) {
    istringstream ss(c);
    int y, m, d;
    string buf;
    vector<string> b;

    ss >> y;
    if ( ss.peek() != '-' )
        throw invalid_argument("Wrong date format: " + c);
    ss.ignore(1);

    filter_stream(c, ss, m, false);

    if ( ss.peek() != '-' )
        throw invalid_argument("Wrong date format: " + c);
    ss.ignore(1);
    filter_stream(c, ss, d, true);

    if ( (m < 1) | (m > 12) )
        throw invalid_argument("Month value is invalid: " + to_string(m));  

    if ( (d < 1) | (d > 31) )
        throw invalid_argument("Day value is invalid: " + to_string(d));  

    date.SetDate(y, m, d);
}

int main() {

  // Test: 

  // Add 0-1-2 event1
  // Add 1-2-3 event2
  // Find 0-1-2       >>> `event1`
  //
  // Del 0-1-2        >>> `Deleted 1 events`
  // Print            >>> `0001-02-03 event2`
  // Del 1-2-3 event2 >>> `Deleted successfully`
  // Del 1-2-3 event2 >>> `Event not found`
  // Add 0-13-32 event1 >>> `Month value is invalid: 13`

  Database db;
    
  string input;

  while (getline(cin, input)) {
    string buf;
    vector<string> command;
    Date date;

    istringstream ss(input);
    while ( getline(ss, buf, ' ') ) {
        command.push_back(buf);
    }

    if ( !command.size() | (command.size() > 3) )
        continue;

    if ( command.size() > 1 ) {
        try {
            parse_date(command[1], date);
        } catch (invalid_argument& ex) {
            cout << ex.what() << endl;
            return 1;
            // continue;
        }
    } 

    if ( (command[0] == "Add") ) {
        db.AddEvent(date, command[2]);
    } else if ( command[0] == "Del"  ) {
        if ( command.size() > 2 ) {
            bool del_event = db.DeleteEvent(date, command[2]);
            if ( !del_event ) 
                cout << "Event not found" << endl;
            else 
                cout << "Deleted successfully" << endl;
        } else {
            int N = db.DeleteDate(date);
            cout << "Deleted " << N << " events" << endl;
        }
    } else if ( command[0] == "Find" ) {
        set<string> value;
        value = db.Find(date);
        if ( value.size() > 0 ) {
            for (string v : value) {
                cout << v << endl;
            }
        }
    } else if ( command[0] == "Print" ) {
        db.Print();
    } else {
        cout << "Unknown command: " << command[0] << endl;
        return 1;
        // continue;
    }
  }

  return 0;
}