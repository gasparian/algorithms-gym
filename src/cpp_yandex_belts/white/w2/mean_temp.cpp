#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, K = 0;
    float mean = 0;
    cin >> n;
    vector<int> v(n), out;

    for ( int& x : v ) {
        cin >> x;
        mean += x * 1.0 / (n * 1.0);
    }    
  
    for ( int i = 0; i < v.size(); ++i ) {
        if ( v[i] > mean ) {
            out.push_back(i);
            ++K;
        }
    }
    
    cout << K << endl;
    for (auto x : out) {
        cout << x << " ";
    }    
    cout << endl;

    return 0;
}
