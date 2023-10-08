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
            // s = "(" + s + ")" + " " + buf; // expensive operation
            d.push_front("(");
            d.push_back(") ");
            d.push_back(buf);
        }   
    }

    for ( string& el : d )
        cout << el;
    cout << endl;
    return 0;
}