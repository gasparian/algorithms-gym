#include <algorithm>
#include <vector>
#include <iostream>

void Print(std::vector<int> v) {
    for ( int el : v ) {
        std::cout << el << " ";
    }
    std::cout << std::endl;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> v;
    for( int i = 1; i <= N; i++ )
        v.push_back(i);

    std::reverse(v.begin(), v.end());
    Print(v);

    while ( std::prev_permutation(v.begin(), v.end()) ) {
        Print(v);
    }

    return 0;
}
