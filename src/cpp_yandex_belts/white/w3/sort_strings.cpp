#include <map>
#include <set>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

std::string str2lower(std::string s) {
    std::for_each(s.begin(), s.end(), [](char & c) {c = std::tolower(c);});
    return s;
}

int main() {
    std::vector<std::string> A;
    int n;
    std::cin >> n;

    if ( (n < 0) || (n > 1000) ) {
        return 0;
    }

    for ( int i = 0; i < n; ++i ) {
        std::string buf;
        std::cin >> buf;
        A.push_back(buf);
    }

    std::sort(A.begin(), A.end(), [](std::string el1, std::string el2){ return str2lower(el1) < str2lower(el2); });
    for ( auto& item : A )
        std::cout << item << ' ';

    return 0;
}