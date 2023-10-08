#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void make_worry(vector<bool>& v, int& i) {
    v[i] = true;
}

void make_quiet(vector<bool>& v, int& i) {
    v[i] = false;
}

void come(vector<bool>& v, int& k) {
    bool flag = false;
    if ( k < 0 ) {
        k -= 2 * k;
        flag = true;
    }
    for ( int i = 0; i < k; ++i) {
        if ( flag ) v.pop_back();
        else v.push_back(false);
    }
}

int worry_count(vector<bool>& v) {
    int n = 0;
    for (auto x : v ) {
        if ( x ) ++n;
    } 
    return n;    
}

struct command {
    string name;
    int value;
};

int main() {
    vector<bool> queue;
    char dlmtr;
    int n;
    cin >> n;
    vector<command> commands;

    for ( int i = 0; i < n; ++i ) {
       string s;
       int val;

       cin >> s;
       if ( s.size() < s.find("_") ) {
           cin >> val;
       } else {
           val = 0;
       }
       commands.push_back({s, val});
    }

    for ( auto c : commands ) {
       if ( c.name == "COME" ) come(queue, c.value);
       if ( c.name == "WORRY" ) make_worry(queue, c.value);
       if ( c.name == "QUIET" ) make_quiet(queue, c.value);
       if ( c.name == "WORRY_COUNT" ) {
           cout << worry_count(queue) << endl;
       }
    }    
    return 0;
}
