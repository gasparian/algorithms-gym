#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, K = 0;
    int64_t mean = 0;
    cin >> n;
    vector<int> v(n), out;

    for ( auto& x : v ) {
        cin >> x;
        mean += x;
    }    
    mean /= n;
  
    for ( int i = 0; i < v.size(); ++i ) {
        if ( v[i] > mean ) {
            out.push_back(i);
            ++K;
        }
    }
    
    cout << K << endl;
    for (auto& x : out) {
        cout << x << " ";
    }    
    cout << endl;

    return 0;
}
