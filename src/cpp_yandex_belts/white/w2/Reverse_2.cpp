#include <iostream>
#include <vector>
using namespace std;

vector <int> Reversed(const vector<int>& v) {
    int size = v.size() - 1; 
    vector<int> new_v = {}; 
    for ( int i = 0; i < (size + 1); ++i ) {
        new_v.push_back(v[size - i]);
    }
    return new_v; 
}

int main() {
    /*vector<int> numbers = {1, 5, 3, 4, 2}, new_v;
    new_v = Reverse(numbers);
    for ( auto x : new_v ) {
        cout << x << " ";
    }
    cout << endl;*/
    return 0;
}
