#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

map<char, int> BuildCharCounter(string& w) {
    map<char, int> m;
    for (const char& c : w) {
            ++m[c];
        }
    return m;
}

int main() {
    int n;
    cin >> n; 
    vector<vector<string>> commands;
  
    for ( int i = 0; i < n; ++i ) {
        string w1, w2;
        cin >> w1 >> w2;
        commands.push_back({w1, w2});
    }
 
    for ( auto c : commands ) {
        string result = "NO";
        if ( BuildCharCounter(c[0]) == BuildCharCounter(c[1]) ) {
            result = "YES";
        }
        cout << result << endl;
    }
    return 0;
}
