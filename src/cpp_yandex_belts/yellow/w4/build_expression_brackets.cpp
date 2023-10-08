#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main() {
    string s;
    int length;
    cin >> s >> length;
    deque<string> d;
    d.push_back(s);

    cin.ignore();
    if ( length ) {
        for ( int i=0; i < length; ++i ) {
            string buf;
            getline(cin, buf);
            if ( (d.back().find(" ") == 1) && (d.back()[0] == '-' || d.back()[0] == '+') && (buf[0] == '*' || buf[0] == '/') ) {
                d.push_front("(");
                d.push_back(")");
            }

            d.push_back(" ");
            d.push_back(buf);
        }   
    }

    for ( string& el : d )
        cout << el;
    cout << endl;
    return 0;
}