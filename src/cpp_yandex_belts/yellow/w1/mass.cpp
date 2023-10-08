#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, rho, w, h, d;
    cin >> n >> rho;
    uint64_t S = 0; 

    for ( int i=0; i < n; ++i ) {
        cin >> w >> h >> d;
        S += w*h*d*rho;
    }    

    cout << S << endl;

    return 0;
}
