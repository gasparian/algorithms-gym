#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

int main() {
    std::vector<int> A;
    int n;
    std::cin >> n;

    if ( (n < 0) || (n > 1000) ) {
        return 0;
    }

    for ( int i = 0; i < n; ++i ) {
        int buf;
        std::cin >> buf;

        if ( (buf < -1000000) || (buf > 1000000) ) {
            continue;
        }

        A.push_back(buf);
    }

    std::sort(A.begin(), A.end(), [](int el1, int el2){ return std::abs(el1) < std::abs(el2); });
    for ( auto& item : A )
        std::cout << item << ' ';

    return 0;
}