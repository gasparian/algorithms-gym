#include <iostream>
#include <string>
using namespace std;

int main() {
    int A, B;
    string out;
    cin >> A >> B;
    
    if (A % 2 != 0) {
        A += 1;
    }
    
    while (A < B) {
        out += to_string(A) + ' ';
        A += 2;
    }

    if (B % 2 == 0) {
        out += to_string(B);
    } else {
        out.pop_back();
    }
    cout << out;    

    return 0;
}
