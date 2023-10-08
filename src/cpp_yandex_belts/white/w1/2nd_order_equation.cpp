#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double A, B, C, D, x1, x2;
    cin >> A >> B >> C;
    if (A == 0 && B != 0) {
        x1 = -1 * (C / B);
        cout << x1;
        
        return 0;
    }

    D = B*B - 4.0*A*C;
    if (D >= 0 && B != 0) {
        x1 = (-1.*B + sqrt(D)) / (2.* A);
        x2 = (-1.*B - sqrt(D)) / (2.* A);
        if (x1 == x2) {
            cout << x1;
        } else {
            cout << x1 << ' ' << x2;
        }
    }
    
    return 0;
}
