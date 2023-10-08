#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

void CHANGE_CAPITAL(map<string, string>& m, string& country, string& capital) {
    if ( m.count(country) <= 0 ) {
        cout << "Introduce new country " << country << " with capital " << capital;
    } else {
        if ( m[country] == capital ) {
            cout << "Country " << country << " hasn't changed its capital";
        } else {
            cout << "Country " << country << " has changed its capital from " << m[country] << " to " << capital;
        }
    }

    m[country] = capital;
    cout << endl;
}

void RENAME(map<string, string>& m, string& old_name, string& new_name) {
    int isin = m.count(old_name);
    if ( (m.count(new_name) == 1) || (old_name == new_name) || (isin == 0) ) {
        cout << "Incorrect rename, skip";
    } else if ( isin == 1 ) {
        m[new_name] = m[old_name];
        m.erase(old_name);
        if ( m[new_name] != "" ) {
            cout << "Country " << old_name << " with capital " << m[new_name] << " has been renamed to " << new_name;
        }
    }
    cout << endl;
}

void ABOUT(map<string, string>& m, string& country) {
    if ( m.count(country) == 1) {
        cout << "Country " <<  country << " has capital " << m[country];
    } else {
        cout << "Country " << country  << " doesn't exist";
    }
    cout << endl;
}

void DUMP(map<string, string>& m) {
     if ( m.size() == 0 ) {
         cout << "There are no countries in the world";
     } else {
         string out;
         for ( auto& el : m ) {
             out += el.first + "/" + el.second + " ";
         }
         cout << out;
     }
     cout << endl;
}

struct command {
    string name;
    string s1;
    string s2;
};

int main() {
    map<string, string> countries;
    int n;
    cin >> n;
    vector<command> commands;
    for ( int i = 0; i < n; ++i ) {
       string com, s1, s2;
       cin >> com;
       if ( (com.size() > com.find("CHANGE")) || (com.size() > com.find("RENAME")) ) {
           cin >> s1 >> s2;
       }
       if ( com.size() > com.find("ABOUT") ) {
           cin >> s1;
           s2 = "";
       }
       if ( com.size() > com.find("DUMP") ) {
           s1 = s2 = "";
       }
       commands.push_back({com, s1, s2});
    }
    
    for ( auto& c : commands ) {
        if ( c.name == "CHANGE_CAPITAL" ) CHANGE_CAPITAL(countries, c.s1, c.s2);
        if ( c.name == "RENAME" ) RENAME(countries, c.s1, c.s2);
        if ( c.name == "ABOUT" ) ABOUT(countries, c.s1);
        if ( c.name == "DUMP" ) DUMP(countries);
    }
     
    return 0;
}
