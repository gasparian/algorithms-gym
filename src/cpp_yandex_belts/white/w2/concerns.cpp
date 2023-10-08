#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int month = 0;
vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct months {
    int day;
    vector<string> list;
};
vector<vector<months>> table;

void add( int& day, string& s) {
    ::table[::month][day].list.push_back(s);
}

void next() {
    int prev = ::month;
    ::month++;
    if ( ::month > 11 ) {
        ::month = 0;
        prev = 11;
    }  
 
   int diff = ::month_days[::month] - ::month_days[prev];
   int last_id = min(::month_days[prev], ::month_days[::month]);
   ::table[::month] = ::table[prev];
 
   if ( diff < 0 ) {
       for ( int i = 0; i < abs( diff ); ++i ) { 
           int current_size = ::table[::month].size();
           
           for ( auto el : ::table[::month][current_size - 1].list ) {
               ::table[::month][last_id - 1].list.push_back(el);
           }
           ::table[::month].pop_back();
       }

   } else if ( diff > 0 ) {
       for ( int i = last_id; i < (diff + last_id); ++i ) {    
           ::table[::month].push_back({i, {}});
       }
   }
}

void dump(int& day) {
    cout << ::table[::month][day].list.size() << " ";
    for ( auto s : ::table[::month][day].list ) {
        cout << s << " ";
    }
    cout << endl;
}

struct command {
    string name;
    int value;
    string s;
};

int main() {
    // init table with months 
    ::table.assign(12, {});
    
    for ( int i = 0; i < ::month_days[::month]; ++i ) {
        ::table[::month].push_back({i, {}});
    }

    char dlmtr;
    int n;
    cin >> n;
    vector<command> commands;

    for ( int i = 0; i < n; ++i ) {
       string c, s;
       int val;

       cin >> c;
       if ( c.size() < c.find("NEXT") ) {
           cin >> val;
           val -= 1;
           if ( c.size() < c.find("DUMP") ) {
               cin >> s;
           } else {
               s = "";
           }
       } else {
           val = 0;
           s = "";
       }
       commands.push_back({c, val, s});
    }

    for ( auto c : commands ) {
       if ( c.name == "ADD" ) add(c.value, c.s);
       if ( c.name == "DUMP" ) dump(c.value);
       if ( c.name == "NEXT" ) next();
    }    
    return 0;
}

