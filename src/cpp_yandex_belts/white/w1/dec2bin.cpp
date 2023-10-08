#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N;
    vector<int> bin;
    cin >> N;

    while (N > 0) {
        bin.insert(bin.begin(), N % 2);
        N /= 2;
    }

    for (auto n : bin) {
        cout << n;
    }

    return 0;
}
