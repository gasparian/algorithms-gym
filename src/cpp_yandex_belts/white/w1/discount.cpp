#include <iostream>
using namespace std;

int main() {
    double N, A, B, X, Y;
    cin >> N >> A >> B >> X >> Y;
    X /= 100; Y /= 100;

    if (N > A && N <= B) {
        N -= N*X;
    } else if (N > B) {
        N -= N*Y; 
    }
    cout << N;
    
    return 0;
}
